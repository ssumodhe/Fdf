/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keycode_2_fdf.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssumodhe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/28 17:07:27 by ssumodhe          #+#    #+#             */
/*   Updated: 2017/03/30 21:20:23 by ssumodhe         ###   ########.fr       */
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
			data->image->coef_h = data->image->gap * 3 /4;
			ft_createimage(data, data->image);
		}
	}
	if (keycode == 78)
	{
		gap = data->image->gap - 5;
		if (gap >= 10)
		{
			data->image->gap = gap;
			data->image->coef_h = data->image->gap * 3 /4;
			ft_createimage(data, data->image);
		}
	}
}

void	ft_key_updownview(int keycode, t_data *data)
{
	float		coeff;
	float		coeff_view;

	if (keycode == 125)
	{
		coeff = data->image->coeff - 0.1;
		printf("coeff = %.2f\n", coeff);
		if (coeff == -0.5)
		{
			data->image->coeff = coeff;
			data->image->coef_h = 0;
			printf("coef_h = %.2f\n", data->image->coef_h);
		}
		else if (coeff > -0.5)
		{
			data->image->coeff = coeff;
			coeff_view = 1 + data->image->coeff;
			printf("coeff_view = %.2f\n", coeff_view);
			data->image->coef_h = data->image->coef_h * coeff_view;
			printf("coef_h = %.2f\n", data->image->coef_h);
		}
	}
	ft_createimage(data, data->image);
}
