/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keycode_2_fdf.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssumodhe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/28 17:07:27 by ssumodhe          #+#    #+#             */
/*   Updated: 2017/03/28 18:00:05 by ssumodhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*void	ft_key_zoom(int keycode, t_data *data)
{
	if (keycode == 78)
	{
		data->image->gap = data->image->gap - 5;
		if (data->image->gap >= 10)
			ft_createimage(data, data->image);
	}
}*/

void	ft_key_updownview(int keycode, t_data *data)
{
	float		coeff_view;

	if (keycode == 125)
	{
		data->image->coeff = data->image->coeff - 0.1;
		printf("coeff = %.2f\n", data->image->coeff);
		if (data->image->coeff == -0.5)
		{
			data->image->coef_h = 0;
			printf("coef_h = %.2f\n", data->image->coef_h);
		}
		else if (data->image->coeff > -0.5)
		{
			coeff_view = 1 + data->image->coeff;
			printf("coeff_view = %.2f\n", coeff_view);
			data->image->coef_h = data->image->coef_h * coeff_view;
			printf("coef_h = %.2f\n", data->image->coef_h);
		}
	}
	ft_createimage(data, data->image);
}
