/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graph_fdf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssumodhe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/13 17:28:01 by ssumodhe          #+#    #+#             */
/*   Updated: 2017/03/23 14:48:40 by ssumodhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		ft_createwindow(t_map *map, t_data *data, t_image *image)
{
	int bits_per_pixel;
	int endian;
	int size_line;


				ft_putnbr(map->width);
				ft_putchar(' ');
				ft_putnbr(map->height);
				ft_putendl("");

	map->fdf.mlx = mlx_init();
	map->fdf.win = mlx_new_window(map->fdf.mlx, image->img_w + (GAP * 2), image->img_h + (GAP * 2), WIN_NAME);

	bits_per_pixel = 32;
	endian = 1; 
	size_line = 0;
	if(!(map->fdf.img = mlx_new_image(map->fdf.mlx, image->img_w , image->img_h)))
		ft_exit("error creation image");
	image->img_addr = mlx_get_data_addr(map->fdf.img, &bits_per_pixel, &size_line, &endian);


			ft_drawline_img(image, 0, 0, (image->img_w - 1), 0, 0x00FFFFFF);
			ft_drawline_img(image, (image->img_w - 1), 0, (image->img_w - 1), (image->img_h - 1), 0x00FFFFFF);
			ft_drawline_img(image, (image->img_w - 1), (image->img_h - 1), 0, (image->img_h - 1), 0x00FFFFFF);
			ft_drawline_img(image, 0, (image->img_h - 1), 0, 0, 0x00FFFFFF);
//			ft_drawline_img(image, 0, image->y_orig, image->x_orig, image->y_orig, 0x00FFFFFF);
//			ft_drawline_img(image, 0, map->highest * GAP * 3/4, image->x_orig, map->highest * GAP * 3/4, 0x00FFFFFF);
//			ft_drawline_img(image, 0, (map->highest * GAP * 3/4) + (map->height * GAP * 0.3), image->x_orig, (map->highest * GAP * 3/4) + (map->height * GAP * 0.3), 0x00FFFFFF);

//(void)data;
	ft_design_image(map, data, image);
	mlx_put_image_to_window(map->fdf.mlx, map->fdf.win, map->fdf.img, GAP, GAP);
	mlx_loop(map->fdf.mlx);
}

t_image		*ft_get_img_param(t_map *map)
{
	t_image		*img_param;
	int			gap;

	if (!(img_param = (t_image *)malloc(sizeof(*img_param))))
		ft_exit("error malloc t_image *image");
	map->k = 1;
	gap = GAP;

//	img_param->img_h = ((map->height*2) *gap * 0.3) + ((map->highest - map->lowest) * (gap * 3/4));
	img_param->img_h = (((map->height+5)*2) * gap * 0.3) + ((map->highest + fabs((double)map->lowest)) * (gap * 3/4));
	if (map->width > map->height)
	{
//		img_param->img_w = (map->width + 1) * gap;
		img_param->img_w = (map->width + 1) * gap;
	}
	else if (map->width <= map->height)
	{
//		img_param->img_w = (map->height + 1) * gap;
		img_param->img_w = (map->height + 1) * gap;
	}
	img_param->x_orig = gap;
	img_param->y_orig = (img_param->img_h - ((map->height+5) * gap * 0.3)) - (fabs((double)map->lowest) * gap * 3/4);
//	img_param->y_orig = (img_param->img_h - (map->height/2 * gap * 0.3) + (map->lowest * gap * 3/4)) - gap;
	img_param->gap = gap;


	return (img_param);
}

void		ft_graph_part(t_map *map, t_data *data)
{
	t_image		*img_param;

				ft_putendl(HIGHLIGHT"\nPHASE 3 --> CREATE WINDOW\n"RESET);
	(void)data;
	img_param = ft_get_img_param(map);
				ft_putstr("img_h = ");
				ft_putnbr(img_param->img_h);
				ft_putchar('\n');
				ft_putstr("img_w = ");
				ft_putnbr(img_param->img_w);
				ft_putendl("");
				ft_putstr("x_orig = ");
				ft_putnbr(img_param->x_orig);
				ft_putendl("");
				ft_putstr("y_orig = ");
				ft_putnbr(img_param->y_orig);
				ft_putendl("");
				ft_putstr("gap = ");
				ft_putnbr(img_param->gap);
				ft_putendl("");

	ft_createwindow(map, data, img_param);
}
