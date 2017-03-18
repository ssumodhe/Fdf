/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graph_fdf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssumodhe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/13 17:28:01 by ssumodhe          #+#    #+#             */
/*   Updated: 2017/03/16 19:56:53 by ssumodhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"


void	ft_pixel_put_img(t_map *map, int x, int y)
{
	int		i;

	//gerer les couleurs.

	i = (4 * (x + (y * (map->width * GAP))));
	map->fdf.img_addr[i + 0] = 0xFF;
	map->fdf.img_addr[i + 1] = 0xFF;
	map->fdf.img_addr[i + 2] = 0xFF;
	map->fdf.img_addr[i + 3] = 0x00;

}

void	ft_choose_side(int	dq, int dp, int x, int y, t_map *map)
{
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
		ft_pixel_put_img(map, x, y);
		i++;
	}
}

void	ft_drawline_img(t_map *map,int x1, int y1, int x2, int y2, int colour)
{
	int		i;
	int		x;
	int		y;
	int		dx;
	int 	dy;
	int		xinc;
	int		yinc;
	int		cumul;

	(void)colour;
	x = x1;
	y = y1;
	dx = x2 - x1;
	dy = y2 - y1;
	xinc = (dx > 0) ? 1 : -1;
	yinc = (dy > 0) ? 1 : -1;
	dx = (dx < 0) ? -dx : dx;
	dy = (dy < 0) ? -dy : dy;

	ft_pixel_put_img(map, x, y);
	if (dx > dy)
//		ft_choose_side(dx, dy, x, y, map);
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
			ft_pixel_put_img(map, x, y);
			i++;
		}
	}
	else 
//		ft_choose_side(dy, dx, y, x, map);
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
			ft_pixel_put_img(map, x, y);
			i++;
		}
	}
}

/*
int			ft_getcolour(char *point)
{
	int		i;
	char	*tmp;
	char	*char_colour;
	int		*int_colour;

	i = 0;
	// Check si cet int fait blanc
	int_colour = 255 + 255 + 255; 
	while (tmp)
	{
		if (tmp[0] == ',' && tmp[2] == 'x')
		{
			char_colour = tmp;
			int_colour = ft_atoi_base(char_colour);
			return(int_colour);
		}
		tmp++;
	}
	return(int_colour);
}*/

void		ft_design_image(t_map *map, t_data *data)
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

	x_orig = ((map->width * GAP) / 8);
	y_orig = ((map->height * GAP) / 2);
	gap = GAP; // Taille de la diagonale d'une case. (ZOOM +/-)
	coeff = 0.3; // [0 ; 0.5] Oriente la vue du plan. (DESSUS/DESSOUS)
	coeff_alti = coeff * gap;
	y = 0;
	tmp = data;
	after = data;
	after = after->next;
	while (tmp->next != NULL)
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
			repeat = x * (gap/2);
			//a - > b
			ft_drawline_img(map, x_orig + (repeat), y_orig - (x * gap * coeff) - (z * coeff_alti), x_orig + (repeat) + (gap/2), y_orig  - (x * gap * coeff) - (w * coeff_alti) - (gap * coeff), 0x00FFFFFF);
//			//b - > c
//			ft_drawline_img(map, x_orig + (repeat)+ (gap/2), y_orig - (x * gap * coeff) - (gap * coeff),\
//				   	x_orig + (repeat) + gap, y_orig - (x * gap * coeff), 0x00FFFFFF);
//			//c - > d
//			ft_drawline_img(map, x_orig + (repeat)+ gap, y_orig - (x * gap * coeff),\
//				   	x_orig + (repeat) + (gap/2), y_orig - (x * gap * coeff) + (gap * coeff), 0x00FFFFFF);
			//d - > a
			ft_drawline_img(map, x_orig + (repeat)+ (gap/2), y_orig - (x * gap * coeff) - (v * coeff_alti) + (gap * coeff), x_orig + (repeat), y_orig - (x * gap * coeff) - (z * coeff_alti), 0x00FFFFFF);
			x++;
		}
		y++;
		tmp = tmp->next;
		//Point de depart + repetition
		x_orig = ((map->width * GAP) / 8) + (y * (gap/2));
		y_orig = ((map->height * GAP) / 2) + (y * gap * coeff);
	}
}

void		ft_createwindow(t_map *map, t_data *data)
{
	int bits_per_pixel;
	int endian;
	int size_line;

				ft_putendl(HIGHLIGHT"\nPHASE 3 --> CREATE WINDOW\n"RESET);

	//ADD CONDITION FOR IF map->height ou map->width > reso ecran
	//	map->fdf.win = mlx_new_window(map->fdf.mlx, 2560 , 1400, WIN_NAME); ECRAN MAX
	map->fdf.mlx = mlx_init();
	map->fdf.win = mlx_new_window(map->fdf.mlx, (map->width * GAP) + (GAP * 2) , \
			(map->height * GAP) + (GAP * 2), WIN_NAME);

	bits_per_pixel = 32;
	endian = 1; 
	size_line = 0;
	if(!(map->fdf.img = mlx_new_image(map->fdf.mlx, map->width * GAP, map->height * GAP)))
		exit(1);
	map->fdf.img_addr = mlx_get_data_addr(map->fdf.img, &bits_per_pixel, &size_line, &endian);
	ft_design_image(map, data);
	mlx_put_image_to_window(map->fdf.mlx, map->fdf.win, map->fdf.img, GAP, GAP);
	mlx_loop(map->fdf.mlx);
}
