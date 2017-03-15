/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graph_fdf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssumodhe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/13 17:28:01 by ssumodhe          #+#    #+#             */
/*   Updated: 2017/03/15 19:04:43 by ssumodhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"


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

void		ft_design_image(t_map *map, t_data *data)
{
	int	x;
	int	x_orig;
	int	y;
	int largeur;
	int hauteur;
	int	nb_line;
	int nb_col;
	int	y_orig;
	int z;
	int gap;
	float coeff;
	float coeff_alti;

	(void)data;

	hauteur = map->height;
	largeur = map->width;
	nb_line = 1;
	nb_col = 1;
	x_orig = ((map->width * GAP) / 4);
	y_orig = ((map->height * GAP) * 3 / 4);
//	x_orig = 50; // Deplace le plan sur l'axe horizontal. (GAUCHE/DROITE)
//	y_orig = 100; // Deplace le plan sur l'axe vertical. (HAUT/BAS)
	gap = 50; // Taille de la diagonale d'une case. (ZOOM +/-)
	coeff = 0.15; // [0 ; 0.5] Oriente la vue du plan. (DESSUS/DESSOUS)
	coeff_alti = coeff * gap;
	z = 10;
	y = y_orig;
	x = x_orig;
	while (nb_line <= hauteur)
	{
		nb_col = 1;
		while (nb_col <= largeur)
		{
/*			if (nb_col == 2)
			{
				ft_drawline_img(map, x, y, x + (gap/2), y - (gap * coeff) - (z + gap), 0x00FFFFFF);
				ft_drawline_img(map, x + (gap/2), y - (gap * coeff) - (z + gap), x + gap, y - (z + gap), 0x0000FF00);
				ft_drawline_img(map, x + gap, y - (z + gap), x + (gap/2), y + (gap * coeff), 0x00FF0000);
				ft_drawline_img(map, x + (gap/2), y + (gap * coeff), x, y, 0x00FFFFFF);
			}
			if (nb_col == 3)
			{
				ft_drawline_img(map, x, y - (z + gap), x + (gap/2), y - (gap * coeff), 0x00FFFFF);
				ft_drawline_img(map, x + (gap/2), y - (gap * coeff), x + gap, y, 0x0000FF00);
				ft_drawline_img(map, x + gap, y, x + (gap/2), y + (gap * coeff) - (z + gap), 0x00FF0000);
				ft_drawline_img(map, x + (gap/2), y + (gap * coeff) - (z + gap), x, y - (z + gap), 0x00FFC125);
			}
	

			if (nb_col != 3 && nb_col != 2)
			{*/
				ft_drawline_img(map, x, y, x + (gap/2), y - (gap * coeff), 0x00FFFFFF);
				ft_drawline_img(map, x + (gap/2), y - (gap * coeff), x + gap, y, 0x00FFFFFF);
				ft_drawline_img(map, x + gap, y, x + (gap/2), y + (gap * coeff), 0x00FFFFFF); //important pour la derniere diagonale
				ft_drawline_img(map, x + (gap/2), y + (gap * coeff), x, y, 0x00FFFFFF);
		//	}
				
			x = x + (gap * 1/2);
			y = y - (gap * coeff);
			nb_col++;
		}
		x = x_orig + (gap * 1/2 * nb_line);
		y = y_orig + (gap * coeff * nb_line);
		nb_line++;
	}



/*
	x_orig = ((map->width * GAP) / 4);
	y_orig = ((map->height * GAP) / 4);
	y_max = 0;
	tmp = data;
	while (tmp->next != NULL)
	{
		x_max = 0;
		gap = 0;
		while (tmp->data_line && tmp->data_line[x_max])
		{
			ft_pixel_put_img(map, x_orig + x_max + gap, (y_orig + y_max - ft_atoi(tmp->data_line[x_max])));
			x_max++;
			gap = gap + 10;
		}
		y_max = y_max + 20;
		tmp = tmp->next;
	}
*/



}

void		ft_createwindow(t_map *map, t_data *data)
{
	int bits_per_pixel;
	int endian;
	int size_line;

				ft_putendl(HIGHLIGHT"\nPHASE 3 --> CREATE WINDOW\n"RESET);

	//ADD CONDITION POUR SI map->height ou map->width > reso ecran
	//	map->fdf.win = mlx_new_window(map->fdf.mlx, 2560 , 1400, WIN_NAME); ECRAN MAX
	(void)data;
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
