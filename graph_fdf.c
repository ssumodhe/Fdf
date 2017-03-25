/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graph_fdf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssumodhe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/13 17:28:01 by ssumodhe          #+#    #+#             */
/*   Updated: 2017/03/25 18:39:30 by ssumodhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		ft_key(int keycode, t_data *data)
{
	int		stock;
	if (keycode == 126)
	{
				ft_putstr("Keycode = ");
				ft_putnbr(keycode);
				ft_putendl("");
		stock = data->image->y_orig;
		data->image->y_orig = stock - data->image->gap;
		//mlx_destroy_image(image->fdf.mlx, image->fdf.img);
		ft_design_image(data, data->image);
	}
	return (0);
}

void		ft_createwindow(t_data *data, t_image *image)
{
	int bits_per_pixel;
	int endian;
	int size_line;

	image->fdf.mlx = mlx_init();
	image->fdf.win = mlx_new_window(image->fdf.mlx, image->img_w + (GAP * 2), image->img_h + (GAP * 2), WIN_NAME);

	bits_per_pixel = 32;
	endian = 1; 
	size_line = 0;
	if(!(image->fdf.img = mlx_new_image(image->fdf.mlx, image->img_w , image->img_h)))
		ft_exit("error creation image");
	image->img_addr = mlx_get_data_addr(image->fdf.img, &bits_per_pixel, &size_line, &endian);
	//Frame.
	ft_drawline_img(image, 0, 0, (image->img_w - 1), 0, 0x00FFFFFF);
	ft_drawline_img(image, (image->img_w - 1), 0, (image->img_w - 1), (image->img_h - 1), 0x00FFFFFF);
	ft_drawline_img(image, (image->img_w - 1), (image->img_h - 1), 0, (image->img_h - 1), 0x00FFFFFF);
	ft_drawline_img(image, 0, (image->img_h - 1), 0, 0, 0x00FFFFFF);

	ft_design_image(data, image);
	// Keycodes.
	mlx_key_hook(image->fdf.win, ft_key, data);

	mlx_put_image_to_window(image->fdf.mlx, image->fdf.win, image->fdf.img, GAP, GAP);
	mlx_loop(image->fdf.mlx);
}

t_image		*ft_get_img_param(t_map *map, float k)
{
	t_image		*img_param;
	int			gap;

	if (!(img_param = (t_image *)malloc(sizeof(*img_param))))
		ft_exit("error malloc t_image *image");
	gap = GAP/k;

	img_param->img_h = (((map->height+5)*2) * gap * 0.3) + ((map->highest + fabs((double)map->lowest)) * (gap * 3/4));
	if (map->width > map->height)
		img_param->img_w = (map->width + 1) * gap;
	else if (map->width <= map->height)
		img_param->img_w = (map->height + 1) * gap;
	img_param->x_orig = gap;
	img_param->y_orig = (img_param->img_h - ((map->height+5) * gap * 0.3)) - (fabs((double)map->lowest) * gap * 3/4);
	img_param->gap = gap;
	img_param->fdf = map->fdf;
	return (img_param);
}

void		ft_graph_part(t_map *map, t_data *data)
{
	t_image		*img_param;
	float			k;

				ft_putendl(HIGHLIGHT"\nPHASE 3 --> CREATE WINDOW\n"RESET);
	img_param = ft_get_img_param(map, 1);
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

	if (img_param->img_h > 1400)
	{
			ft_putendl("height is too high");
		k = (img_param->img_h / 1400);
		if (k == 1)
			k++;
			ft_putstr("k = ");
			ft_putnbr(k);
			ft_putchar('\n');
		img_param = ft_get_img_param(map, k);
	}
	if (img_param->img_w > 2560)
	{
			ft_putendl("width is too wide");
		k = (img_param->img_w / 2560);
		if (k == 1)
			k++;
			ft_putstr("k = ");
			ft_putnbr(k);
			ft_putchar('\n');
		img_param = ft_get_img_param(map, k);
	}
				ft_putchar('\n');
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


	data->image = img_param;
	ft_createwindow(data, img_param);
}
