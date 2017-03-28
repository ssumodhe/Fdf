/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_img_fdf.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssumodhe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/27 18:04:02 by ssumodhe          #+#    #+#             */
/*   Updated: 2017/03/28 19:29:56 by ssumodhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			ft_getcolour(char *point, char *img_colour)
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
	return(ft_atoi_base(img_colour, 16));
}

void		ft_design_image(t_data *data, t_image *image)
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
				ft_putendl(HIGHLIGHT"\nPHASE 4 --> DISPLAY IMAGE\n"RESET);

 	x_orig = image->x_orig;
	y_orig = image->y_orig;
	gap = image->gap; // Taille de la diagonale d'une case. (ZOOM +/-)
	coeff = image->coeff; // [0 ; 0.5] Oriente la vue du plan. (DESSUS/DESSOUS)
	coeff_alti = image->coef_h;
	y = 0;
	tmp = data;
	after = data;
	after = after->next;
	while (tmp->next != NULL && after->next != NULL)
	{
		x = 0;
		while (tmp->data_line && tmp->data_line[x])
		{
			colour = ft_getcolour(tmp->data_line[x], image->colour);
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
		//		w = w - w - z;
				w = z;
				z = v;
				ft_drawline_img(image, x_orig + (repeat) + (gap/2), y_orig - (x * gap * coeff) - (z * coeff_alti) +(gap * coeff), x_orig + (repeat) + (gap/2) + (gap/2), y_orig - (x * gap * coeff) - (w * coeff_alti), 0x00FF0000);

			}
		
			x++;
		}
		y++;
		tmp = tmp->next;
		after = after->next;
		//Point de depart + repetition - Pour se deplacer de ligne en ligne avec le decalage.
		x_orig = image->x_orig + (y * (gap/2)); 
		y_orig = image->y_orig + (y * gap * coeff);
	}
}
