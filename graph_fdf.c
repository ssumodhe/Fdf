/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graph_fdf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssumodhe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/13 17:28:01 by ssumodhe          #+#    #+#             */
/*   Updated: 2017/03/13 18:18:44 by ssumodhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		ft_createwindow(t_map *map, t_data *data)
{
	t_fdf	fdf;
//	char	*image_addr;
	int bits_per_pixel;
	int endian;
	int size_line;
	int	x;

	(void)data;
	fdf.mlx = mlx_init();
	fdf.win = mlx_new_window(fdf.mlx, (map->width * GAP) + (GAP * 2) , \
			(map->height * GAP) + (GAP * 2), WIN_NAME);

	bits_per_pixel = 32;
	endian = 1; 
	size_line = 0;
	if(!(fdf.image = mlx_new_image(fdf.mlx, map->width * GAP, map->height * GAP)))
		exit(1);
//	image_addr = mlx_get_data_addr(fdf.image, &bits_per_pixel, &size_line, &endian);

	mlx_put_image_to_window(fdf.mlx, fdf.win, fdf.image, GAP, GAP);
	x = 0;
	while (x < (map->width * GAP))
	{
		mlx_pixel_put(fdf.mlx, fdf.win, x, 0, 0x00FF0000);
		x++;
	}

	mlx_loop(fdf.mlx);
}
