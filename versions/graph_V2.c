/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graph_fdf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssumodhe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/13 17:28:01 by ssumodhe          #+#    #+#             */
/*   Updated: 2017/03/21 17:36:41 by ssumodhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		ft_createwindow(t_map *map, t_data *data, t_window *window)
{
	int bits_per_pixel;
	int endian;
	int size_line;
(void)data;
				ft_putnbr(map->width);
				ft_putchar(' ');
				ft_putnbr(map->height);
				ft_putendl("");
	map->fdf.mlx = mlx_init();
	map->fdf.win = mlx_new_window(map->fdf.mlx, window->win_w, window->win_h, WIN_NAME);
	bits_per_pixel = 32;
	endian = 1; 
	size_line = 0;
	if(!(map->fdf.img = mlx_new_image(map->fdf.mlx, window->win_w - (window->gap*2), window->win_h - (window->gap*2))))
		ft_exit("error creation image");
	map->fdf.img_addr = mlx_get_data_addr(map->fdf.img, &bits_per_pixel, &size_line, &endian);


//	a -> b
	ft_drawline_img(map, 0, 0, window->win_w - (window->gap*2), 0, 0x00FFFFFF);
//  b -> c
//	ft_drawline_img(map, window->win_w - (window->gap*2), 0, window->win_w - (window->gap*2), window->win_h - (window->gap*2), 0x00FFFFFF);
//  c -> d
	ft_drawline_img(map, 500 - (25 * 2), 300 - (25 *2), 0, 300 - (25 * 2),0x00FFFFFF);
//  d -> a
//	ft_drawline_img(map, 0,window->win_h - (window->gap*2), 0, 0, 0x00FFFFFF);


//	ft_design_image(map, data, window);
	mlx_put_image_to_window(map->fdf.mlx, map->fdf.win, map->fdf.img, window->gap, window->gap);
	mlx_loop(map->fdf.mlx);
}
/*
t_window	*ft_get_win_param(t_map *map)
{
	t_window	*win_param;
	int			gap;

	if (!(win_param = (t_window *)malloc(sizeof(*win_param))))
		ft_exit("error malloc t_window *window");
	map->k = 1;
	if ((((map->width * GAP) + (GAP * 2)) >= 2560) && (((map->height * GAP) + (map->highest * GAP) + (GAP*2)) >= 1400))
		map->k = 10;
	else if (((map->width * GAP) + (GAP * 2)) >= 2560)
		map->k = ((map->width * GAP) + (GAP * 2)) / 2560;
	else if (((map->height * GAP) + (map->highest * GAP) + (GAP*2)) >= 1400)
		map->k = ((map->height * GAP) + (map->highest * GAP) + (GAP*2)) / 1400;
	gap = GAP / map->k;
	win_param->win_h = (((map->height * gap) + (map->highest * gap))/map->k) + (gap * 2);
	win_param->win_w = ((map->width * gap) / map->k) + (gap * 2);
	win_param->y_orig = (((map->height * gap) + (map->highest * gap))/map->k) - gap;
	win_param->x_orig = gap;
	win_param->gap = gap;
	return (win_param);
}*/

t_window	*ft_get_win_param(t_map *map)
{
	t_window	*win_param;
	int			gap;

	if (!(win_param = (t_window *)malloc(sizeof(*win_param))))
		ft_exit("error malloc t_window *window");
	map->k = 1;
	gap = GAP / map->k;
	win_param->win_h = ((map->highest - map->lowest) * gap) + (gap * 2);
	win_param->win_w = ((map->width * gap)) + (gap * 2);
	win_param->y_orig = ((map->highest - map->lowest) * gap) + map->lowest;
	win_param->x_orig = gap;
	win_param->gap = gap;
	return (win_param);
}

void		ft_graph_part(t_map *map, t_data *data)
{
	t_window	*win_param;

				ft_putendl(HIGHLIGHT"\nPHASE 3 --> CREATE WINDOW\n"RESET);
	(void)data;
	win_param = ft_get_win_param(map);
				ft_putstr("win_h = ");
				ft_putnbr(win_param->win_h);
				ft_putchar('\n');
				ft_putstr("win_w = ");
				ft_putnbr(win_param->win_w);
				ft_putendl("");
				ft_putstr("x_orig = ");
				ft_putnbr(win_param->x_orig);
				ft_putendl("");
				ft_putstr("y_orig = ");
				ft_putnbr(win_param->y_orig);
				ft_putendl("");
				ft_putstr("gap = ");
				ft_putnbr(win_param->gap);
				ft_putendl("");

	ft_createwindow(map, data, win_param);
}
