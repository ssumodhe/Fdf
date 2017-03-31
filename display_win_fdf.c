/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_win_fdf.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssumodhe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/30 19:21:00 by ssumodhe          #+#    #+#             */
/*   Updated: 2017/03/31 16:24:33 by ssumodhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		ft_putguide_views(t_image *im)
{
	mlx_string_put(im->fdf.mlx, im->fdf.win, im->img_w + (GAP * 2), GAP + 280, \
			0x00FFFFFF, "zoom in  : key +");
	mlx_string_put(im->fdf.mlx, im->fdf.win, im->img_w + (GAP * 2), GAP + 295, \
			0x00FFFFFF, "zoom out : key -");
}

void		ft_putguide_colours(t_image *im)
{
	mlx_string_put(im->fdf.mlx, im->fdf.win, im->img_w + (GAP * 2), GAP + 180, \
			0x00FF0000, "red    : key r");
	mlx_string_put(im->fdf.mlx, im->fdf.win, im->img_w + (GAP * 2), GAP + 195, \
			0x0000868B, "blue   : key b");
	mlx_string_put(im->fdf.mlx, im->fdf.win, im->img_w + (GAP * 2), GAP + 210, \
			0x00FFD700, "yellow : key y");
	mlx_string_put(im->fdf.mlx, im->fdf.win, im->img_w + (GAP * 2), GAP + 225, \
			0x0000FF00, "green  : key g");
	mlx_string_put(im->fdf.mlx, im->fdf.win, im->img_w + (GAP * 2), GAP + 240, \
			0x00FFFFFF, "white  : key w");
}

void		ft_putguide_moves(t_image *im)
{
	mlx_string_put(im->fdf.mlx, im->fdf.win, im->img_w + (GAP * 2), GAP + 35, \
			0x00FFFFFF, "up    : key 8");
	mlx_string_put(im->fdf.mlx, im->fdf.win, im->img_w + (GAP * 2), GAP + 50, \
			0x00FFFFFF, "down  : key 2");
	mlx_string_put(im->fdf.mlx, im->fdf.win, im->img_w + (GAP * 2), GAP + 65, \
			0x00FFFFFF, "left  : key 4");
	mlx_string_put(im->fdf.mlx, im->fdf.win, im->img_w + (GAP * 2), GAP + 80, \
			0x00FFFFFF, "right : key 6");
	mlx_string_put(im->fdf.mlx, im->fdf.win, im->img_w + (GAP * 2), GAP + 95, \
			0x00FFFFFF, "diag up left    : key 7");
	mlx_string_put(im->fdf.mlx, im->fdf.win, im->img_w + (GAP * 2), GAP + 110, \
			0x00FFFFFF, "diag down left  : key 1");
	mlx_string_put(im->fdf.mlx, im->fdf.win, im->img_w + (GAP * 2), GAP + 125, \
			0x00FFFFFF, "diag up right   : key 9");
	mlx_string_put(im->fdf.mlx, im->fdf.win, im->img_w + (GAP * 2), GAP + 140, \
			0x00FFFFFF, "diag down right : key 3");
}

void		ft_putguide(t_image *im)
{
	mlx_string_put(im->fdf.mlx, im->fdf.win, im->img_w + (GAP * 2), GAP, \
			0x00FFFFFF, "Manual:");
	mlx_string_put(im->fdf.mlx, im->fdf.win, im->img_w + (GAP * 2), GAP + 20, \
			0x00FFFFFF, " - moves");
	ft_putguide_moves(im);
	mlx_string_put(im->fdf.mlx, im->fdf.win, im->img_w + (GAP * 2), GAP + 165, \
			0x00FFFFFF, " - colours");
	ft_putguide_colours(im);
	mlx_string_put(im->fdf.mlx, im->fdf.win, im->img_w + (GAP * 2), GAP + 265, \
			0x00FFFFFF, " - views");
	ft_putguide_views(im);
	mlx_string_put(im->fdf.mlx, im->fdf.win, im->img_w + (GAP * 2), GAP + 320, \
			0x00FFFFFF, "reset : key 0 or key 5");
	mlx_string_put(im->fdf.mlx, im->fdf.win, im->img_w + (GAP * 2), GAP + 335, \
			0x00FFFFFF, "quit  : esc");
}

void		ft_putframe(t_image *image)
{
	t_ptcalc	pc;

	pc.x1 = 0;
	pc.y1 = 0;
	pc.x2 = (image->img_w - 1);
	pc.y2 = 0;
	pc.colour = 0x00FFFFFF;
	ft_drawline_img(image, pc);
	pc.x1 = (image->img_w - 1);
	pc.y1 = 0;
	pc.x2 = (image->img_w - 1);
	pc.y2 = (image->img_h - 1);
	ft_drawline_img(image, pc);
	pc.x1 = (image->img_w - 1);
	pc.y1 = (image->img_h - 1);
	pc.x2 = 0;
	pc.y2 = (image->img_h - 1);
	ft_drawline_img(image, pc);
	pc.x1 = 0;
	pc.y1 = (image->img_h - 1);
	pc.x2 = 0;
	pc.y2 = 0;
	ft_drawline_img(image, pc);
}
