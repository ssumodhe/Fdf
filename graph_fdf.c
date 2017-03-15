/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graph_fdf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssumodhe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/13 17:28:01 by ssumodhe          #+#    #+#             */
/*   Updated: 2017/03/15 13:05:33 by ssumodhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"


void	ft_pixel_put_img(t_map *map, int x, int y)
{
	int		i;

	i = (4 * (x + (y * (map->height * GAP))));
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

void		ft_createwindow(t_map *map, t_data *data)
{
	int bits_per_pixel;
	int endian;
	int size_line;
	int x_max;
	int y_max;

				ft_putendl(HIGHLIGHT"\nPHASE 3 --> CREATE WINDOW\n"RESET);

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

	x_max = (map->width * GAP) - 1;
	y_max = (map->height * GAP) - 1;
	ft_putstr("x_max = ");
	ft_putnbr(x_max);
	ft_putchar('\n');
	ft_putstr("y_max = ");
	ft_putnbr(y_max);
	ft_putchar('\n');
	ft_drawline_img(map, 0, 0, x_max, 0, 0x00FFFFFF);
	ft_drawline_img(map, x_max, 0, x_max, y_max, 0x00FFFFFF);
	ft_drawline_img(map, x_max, y_max, 0, y_max, 0x00FFFFFF);
	ft_drawline_img(map, 0, y_max, 0, 0, 0x00FFFFFF);


	mlx_put_image_to_window(map->fdf.mlx, map->fdf.win, map->fdf.img, GAP, GAP);
	mlx_loop(map->fdf.mlx);
}
