/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keycode_2_fdf.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssumodhe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/28 17:07:27 by ssumodhe          #+#    #+#             */
/*   Updated: 2017/04/01 18:10:43 by ssumodhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_key_zoom(int keycode, t_data *data)
{
	int		gap;

	if (keycode == 69)
	{
		gap = data->image->gap + 5;
		if (gap <= 300)
		{
			data->image->gap = gap;
			data->image->coef_h = data->image->gap * 3 / 4;
			ft_createimage(data, data->image);
		}
	}
	if (keycode == 78)
	{
		gap = data->image->gap - 5;
		if (gap >= 5)
		{
			data->image->gap = gap;
			data->image->coef_h = data->image->gap * 3 / 4;
			ft_createimage(data, data->image);
		}
	}
}

void	ft_key_upview(t_data *data)
{
	float		coeff;
	float		coeff_view;

	coeff = data->image->coeff + 0.1;
	if (coeff == 0.5)
	{
		data->image->coeff = coeff;
		data->image->coef_h = 0;
	}
	else if (coeff < 0.5)
	{
		data->image->coeff = coeff;
		coeff_view = 1 - data->image->coeff;
		if (data->image->coef_h != 0)
			data->image->coef_h = data->image->coef_h * coeff_view;
		else
			data->image->coef_h = (data->image->gap * 3 / 4) * coeff_view;
	}
	ft_createimage(data, data->image);
}

void	ft_key_downview(t_data *data)
{
	float		coeff;
	float		coeff_view;

	coeff = data->image->coeff - 0.1;
	if (coeff == -0.49999997019767761230468750000000)
	{
		data->image->coeff = coeff;
		data->image->coef_h = 0;
	}
	else if (coeff > -0.49999997019767761230468750000000)
	{
		data->image->coeff = coeff;
		coeff_view = 1 + data->image->coeff;
		if (data->image->coef_h != 0)
			data->image->coef_h = data->image->coef_h * coeff_view;
		else
			data->image->coef_h = (data->image->gap * 3 / 4) * coeff_view;
	}
	ft_createimage(data, data->image);
}
