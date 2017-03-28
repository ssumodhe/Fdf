/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_img_2_fdf.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssumodhe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/28 19:18:28 by ssumodhe          #+#    #+#             */
/*   Updated: 2017/03/28 19:29:53 by ssumodhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		ft_pixel_put_img(t_image *img, int x, int y, int colour)
{
	int		i;

	if (x >= 0 && y >= 0 && x < img->img_w)
	{
		i = (4 * (x + (y * img->img_w)));
		if (i < (4 * img->img_w * img->img_h)-4)
		{
			img->img_addr[i + 0] = colour & 0x000000FF;
			img->img_addr[i + 1] = (colour >> 8) & 0x000000FF;
			img->img_addr[i + 2] = (colour >> 16) & 0x000000FF;
			img->img_addr[i + 3] = 0x00;
		}
	}
}
/*
void	ft_choose_side(int	dx, int dy, int x, int y, int xinc, int yinc, t_image *image, int colour)
{
	int i;
	int cumul;

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
			ft_pixel_put_img(image, x, y, colour);
			i++;
		}



	int		i;
	int		qinc;
	int		pinc;
	int		cumul;

	qinc = (dq > 0) ? 1 : -1;
	pinc = (dp > 0) ? 1 : -1;
	cumul = (dq / 2);
	i = 1;
	while (i <= dq)
	{
		x = x + qinc;
		cumul = cumul + dp;
		if (cumul >= dq)
		{
			cumul = cumul - dq;
			y = y + pinc;
		}
		ft_pixel_put_img(image, x, y, colour);
		i++;
	}
}*/

void		ft_drawline_img(t_image *image,int x1, int y1, int x2, int y2, int colour)
{
	int		i;
	int		x;
	int		y;
	int		dx;
	int 	dy;
	int		xinc;
	int		yinc;
	int		cumul;

	x = x1;
	y = y1;
	dx = x2 - x1;
	dy = y2 - y1;
	xinc = (dx > 0) ? 1 : -1;
	yinc = (dy > 0) ? 1 : -1;
	dx = (dx < 0) ? -dx : dx;
	dy = (dy < 0) ? -dy : dy;

	ft_pixel_put_img(image, x, y, colour);
	if (dx > dy)
//		ft_choose_side(dx, dy, x, y, xinc, yinc, image, colour);
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
			ft_pixel_put_img(image, x, y, colour);
			i++;
		}
	}
	else 
//		ft_choose_side(dy, dx, y, x, yinc, xinc, image, colour);
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
			ft_pixel_put_img(image, x, y, colour);
			i++;
		}
	}
}
