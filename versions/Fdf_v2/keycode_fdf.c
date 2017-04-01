/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keycode_fdf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssumodhe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/27 19:21:17 by ssumodhe          #+#    #+#             */
/*   Updated: 2017/04/01 18:11:25 by ssumodhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		ft_key_colour(int keycode, t_data *data)
{
	if (keycode == 5)
		data->image->colour = CHAR_GREEN;
	if (keycode == 11)
		data->image->colour = CHAR_BLUE;
	if (keycode == 13)
		data->image->colour = CHAR_WHITE;
	if (keycode == 15)
		data->image->colour = CHAR_RED;
	if (keycode == 16)
		data->image->colour = CHAR_YELLOW;
	ft_createimage(data, data->image);
}

void		ft_key_vertinhori(int keycode, t_data *data)
{
	int		stock;

	if (keycode == 84)
	{
		stock = data->image->y_orig;
		data->image->y_orig = stock + data->image->gap;
	}
	if (keycode == 86)
	{
		stock = data->image->x_orig;
		data->image->x_orig = stock - data->image->gap;
	}
	if (keycode == 88)
	{
		stock = data->image->x_orig;
		data->image->x_orig = stock + data->image->gap;
	}
	if (keycode == 91)
	{
		stock = data->image->y_orig;
		data->image->y_orig = stock - data->image->gap;
	}
	ft_createimage(data, data->image);
}

void		ft_key_diag(int keycode, t_data *data)
{
	if (keycode == 83)
	{
		data->image->y_orig = data->image->y_orig + data->image->gap;
		data->image->x_orig = data->image->x_orig - data->image->gap;
	}
	if (keycode == 85)
	{
		data->image->y_orig = data->image->y_orig + data->image->gap;
		data->image->x_orig = data->image->x_orig + data->image->gap;
	}
	if (keycode == 89)
	{
		data->image->y_orig = data->image->y_orig - data->image->gap;
		data->image->x_orig = data->image->x_orig - data->image->gap;
	}
	if (keycode == 92)
	{
		data->image->y_orig = data->image->y_orig - data->image->gap;
		data->image->x_orig = data->image->x_orig + data->image->gap;
	}
	ft_createimage(data, data->image);
}

void		ft_key_init(t_data *data)
{
	int gap;

	gap = (GAP / data->map->k);
	data->image->gap = gap;
	data->image->img_h = (((data->map->height + 5) * 2) * gap * 0.3) + \
			((data->map->highest + fabs((double)data->map->lowest)) * \
			(gap * 3 / 4));
	if (data->map->width > data->map->height)
		data->image->img_w = (data->map->width + 1) * gap;
	else if (data->map->width <= data->map->height)
		data->image->img_w = (data->map->height + 1) * gap;
	data->image->x_orig = gap;
	data->image->y_orig = (data->image->img_h - \
			((data->map->height + 5) * gap * 0.3)) - \
			(fabs((double)data->map->lowest) * gap * 3 / 4);
	data->image->coeff = 0.3;
	data->image->coef_h = gap * 3 / 4;
	data->image->colour = CHAR_WHITE;
	ft_createimage(data, data->image);
}

int			ft_key(int keycode, t_data *data)
{
	mlx_destroy_image(data->image->fdf.mlx, data->image->fdf.img);
	if (keycode == 53)
		exit(0);
	if (keycode <= 16)
		ft_key_colour(keycode, data);
	if (keycode == 69 || keycode == 78)
		ft_key_zoom(keycode, data);
	if (keycode == 82 || keycode == 87)
		ft_key_init(data);
	if (keycode == 84 || keycode == 86 || keycode == 88 || keycode == 91)
		ft_key_vertinhori(keycode, data);
	if (keycode == 83 || keycode == 85 || keycode == 89 || keycode == 92)
		ft_key_diag(keycode, data);
	if (keycode == 125)
		ft_key_downview(data);
	if (keycode == 126)
		ft_key_upview(data);
	else
		ft_createimage(data, data->image);
	return (0);
}
