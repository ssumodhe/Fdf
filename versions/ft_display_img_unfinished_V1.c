/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_img.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssumodhe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/19 18:02:29 by ssumodhe          #+#    #+#             */
/*   Updated: 2017/03/19 18:39:07 by ssumodhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_display_img()
{
	int		colour;
//		colour = ft_getcolour(tmp->data_line[x]);
			w = 0;
			v = 0;
			z = ft_atoi(tmp->data_line[x]);
			if (tmp->data_line[x + 1])
				w = ft_atoi(tmp->data_line[x + 1]);
			if (after->data_line[x])
				v = ft_atoi(after->data_line[x]);
			repeat = x * (gap/2);
			//a - > b
			ft_drawline_img(map, x_orig + (repeat), y_orig - (x * gap * coeff) - (z * coeff_alti),\
				   	x_orig + (repeat) + (gap/2), y_orig  - (x * gap * coeff) - (w * coeff_alti) - (gap * coeff),\
				   	0x00FFFFFF);
//			//b - > c
//			ft_drawline_img(map, x_orig + (repeat)+ (gap/2), y_orig - (x * gap * coeff) - (gap * coeff),\
//				   	x_orig + (repeat) + gap, y_orig - (x * gap * coeff), 0x00FFFFFF);
//			//c - > d
//			ft_drawline_img(map, x_orig + (repeat)+ gap, y_orig - (x * gap * coeff),\
//				   	x_orig + (repeat) + (gap/2), y_orig - (x * gap * coeff) + (gap * coeff), 0x00FFFFFF);
			//d - > a
			ft_drawline_img(map, x_orig + (repeat)+ (gap/2), y_orig - (x * gap * coeff) - (v * coeff_alti) + (gap * coeff), \
					x_orig + (repeat), y_orig - (x * gap * coeff) - (z * coeff_alti), 0x00FFFFFF);
}
