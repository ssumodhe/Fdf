/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_img.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssumodhe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/20 14:06:14 by ssumodhe          #+#    #+#             */
/*   Updated: 2017/03/24 20:37:23 by ssumodhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_pixel_put_img(t_image *img, int x, int y, int colour)
{
	int		i;

	if (x >= 0 && y >= 0)
	{
		i = (4 * (x + (y * img->img_w)));
		if (i < (4 * img->img_w * img->img_h)-4)
		{
			img->img_addr[i + 0] = colour & 0x000000FF;
			img->img_addr[i + 1] = (colour >> 8) & 0x000000FF;
			img->img_addr[i + 2] = (colour >> 16) & 0x000000FF;
			img->img_addr[i + 3] = 0x00;
		}
	}
}

/*void	ft_choose_side(int	dx, int dy, int x, int y, int xinc, int yinc, t_image *image, int colour)
{
	int i;
	int cumul;

		cumul = (dx / 2);
		i = 1;
		while (i <= dx)
		{
			x = x + xinc;
			cumul = cumul + dy;
			if (cumul >= dx)
			{
				cumul = cumul - dx;
				y = y + yinc;
			}
			ft_pixel_put_img(image, x, y, colour);
			i++;
		}



	int		i;
	int		qinc;
	int		pinc;
	int		cumul;

	qinc = (dq > 0) ? 1 : -1;
	pinc = (dp > 0) ? 1 : -1;
	cumul = (dq / 2);
	i = 1;
	while (i <= dq)
	{
		x = x + qinc;
		cumul = cumul + dp;
		if (cumul >= dq)
		{
			cumul = cumul - dq;
			y = y + pinc;
		}
		ft_pixel_put_img(image, x, y, colour);
		i++;
	}
}*/

void	ft_drawline_img(t_image *image,int x1, int y1, int x2, int y2, int colour)
{
	int		i;
	int		x;
	int		y;
	int		dx;
	int 	dy;
	int		xinc;
	int		yinc;
	int		cumul;

	x = x1;
	y = y1;
	dx = x2 - x1;
	dy = y2 - y1;
	xinc = (dx > 0) ? 1 : -1;
	yinc = (dy > 0) ? 1 : -1;
	dx = (dx < 0) ? -dx : dx;
	dy = (dy < 0) ? -dy : dy;

	ft_pixel_put_img(image, x, y, colour);
	if (dx > dy)
//		ft_choose_side(dx, dy, x, y, xinc, yinc, image, colour);
	{
		cumul = (dx / 2);
		i = 1;
		while (i <= dx)
		{
			x = x + xinc;
			cumul = cumul + dy;
			if (cumul >= dx)
			{
				cumul = cumul - dx;
				y = y + yinc;
			}
			ft_pixel_put_img(image, x, y, colour);
			i++;
		}
	}
	else 
//		ft_choose_side(dy, dx, y, x, yinc, xinc, image, colour);
	{
		cumul = (dy / 2);
		i = 1;
		while (i <= dy)
		{
			y = y + yinc;
			cumul = cumul + dx;
			if (cumul >= dy)
			{
				cumul = cumul - dy;
				x = x + xinc;
			}
			ft_pixel_put_img(image, x, y, colour);
			i++;
		}
	}
}

int			ft_getcolour(char *point)
{
	int		i;
	char	*tmp;
	char	*char_colour;
	int		int_colour;

	i = 0;
	tmp = point;
	while (tmp[0] != '\0')
	{
		if (tmp[0] == ',' && tmp[2] == 'x')
		{
			tmp = tmp + 3;
			char_colour = tmp;
			int_colour = ft_atoi_base(char_colour, 16);
			return(int_colour);
		}
		tmp++;
	}
	return(16777215);
}

void		ft_design_image(t_map *map, t_data *data, t_image *image)
{
	t_data *tmp;
	t_data *after;
	int	x;
	int	x_orig;
	int	y;
	int	y_orig;
	int z;
	int	w;
	int	v;
	int repeat;
	int gap;
	float coeff;
	float coeff_alti;
	int		colour;
	(void)map;
				ft_putendl(HIGHLIGHT"\nPHASE 4 --> DISPLAY IMAGE\n"RESET);

 	x_orig = image->x_orig;
	y_orig = image->y_orig;
	gap = image->gap; // Taille de la diagonale d'une case. (ZOOM +/-)
	coeff = 0.3; // [0 ; 0.5] Oriente la vue du plan. (DESSUS/DESSOUS)
	coeff_alti = gap * 3/4;
	y = 0;
	tmp = data;
	after = data;
	after = after->next;
	while (tmp->next != NULL && after->next != NULL)
	{
		x = 0;
		while (tmp->data_line && tmp->data_line[x])
		{
			colour = ft_getcolour(tmp->data_line[x]);
			w = 0;
			v = 0;
			z = ft_atoi(tmp->data_line[x]);
			if (tmp->data_line[x + 1])
				w = ft_atoi(tmp->data_line[x + 1]);
			if (after->data_line[x])
				v = ft_atoi(after->data_line[x]);
				
			repeat = x * (gap/2); // Pour se deplacer de case en case.
			
			if (tmp->data_line[x+1])
			{		 //a - > b
				ft_drawline_img(image, x_orig + (repeat), y_orig - (x * gap * coeff) - (z * coeff_alti), x_orig + (repeat) + (gap/2), y_orig - (x * gap * coeff) - (w * coeff_alti) - (gap * coeff), colour);
			}
						//d - > a
			ft_drawline_img(image, x_orig + (repeat), y_orig - (x * gap * coeff) - (z * coeff_alti), x_orig + (repeat)+ (gap/2), y_orig - (x * gap * coeff) - (v * coeff_alti) + (gap * coeff), colour);
			if (after->next->next == NULL && tmp->data_line[x+1])
			{		//c - > d
				z = v;
				w = 0;
				ft_drawline_img(image, x_orig + (repeat) + (gap/2), y_orig - (x * gap * coeff) - (z * coeff_alti) +(gap * coeff), x_orig + (repeat) + (gap/2) + (gap/2), y_orig - (x * gap * coeff) - (w * coeff_alti), colour);

			}
		
			x++;
		}
		y++;
		//Point de depart + repetition - Pour se deplacer de ligne en ligne avec le decalage.
		x_orig = image->x_orig + (y * (gap/2)); 
		y_orig = image->y_orig + (y * gap * coeff);
		tmp = tmp->next;
		after = after->next;
	}
}
