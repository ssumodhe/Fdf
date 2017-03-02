/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssumodhe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/22 15:20:22 by ssumodhe          #+#    #+#             */
/*   Updated: 2017/03/01 14:18:51 by ssumodhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stdlib.h>
#include <stdio.h>
#include "libft/libft.h"

// Pour centrer l'image.
#define WINDOW_H 400
#define WINDOW_W 400

/* 
** Structures
*/

typedef struct		s_fdf
{
	void	*mlx;
	void	*win;
	void	*win_2;
	void	*image;
}					t_fdf;

/* 
** Variables Globales
*/

int		x = 150;
int		y = 150;


/* 
** Code
*/

void	ft_put_sqr(void *mlx, void *win, int x, int y, int colour)
{
	int		i;
	int		j;

	i = x;
	while (i < (x + 100))
	{
		j = y;
		while (j < (y + 100))
		{
			mlx_pixel_put(mlx, win, i, j, colour);
		//	colour++;
			j++;
		}
		i++;
	}
}


int		ft_key(int keycode, t_fdf *param)
{
	printf("key = %d\n", keycode);
	if (keycode == 15) // Touche R
		ft_put_sqr(param->mlx, param->win, x, y, 0x00FF0000);
	if (keycode == 13) // Touche W
		ft_put_sqr(param->mlx, param->win, x, y, 0x00FFFFFF);
	if (keycode == 11) // Touche B
		ft_put_sqr(param->mlx, param->win, x, y, 0x000000FF);
	if (keycode == 9) // Touche V
		ft_put_sqr(param->mlx, param->win, x, y, 0x0000FF00);
	if (keycode == 126) // Fleche haut
		ft_put_sqr(param->mlx, param->win, x, y - 10, 0x00FFFFFF);
	if (keycode == 125) // Fleche bas
		ft_put_sqr(param->mlx, param->win, x, y + 10, 0x00FFFFFF);
	if (keycode == 123) // Fleche gauche
		ft_put_sqr(param->mlx, param->win, x - 10, y, 0x00FFFFFF);
	if (keycode == 124) // Fleche droite
		ft_put_sqr(param->mlx, param->win, x + 10, y, 0x00FFFFFF);
	if (keycode == 53) // Esc
		exit(0);
	return (0);
}

void	ft_swap(int *a, int *b)
{
	int c;

	c = *a;
	a = b;
	b = &c;
}

void	ft_drawline(void *mlx, void *win,int x1, int y1, int x2, int y2, int colour)
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

	mlx_pixel_put(mlx, win, x, y, colour);
	if (dx > dy)
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
			mlx_pixel_put(mlx, win, x, y, colour);
			i++;
		}
	}
	else 
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
			mlx_pixel_put(mlx, win, x, y, colour);
			i++;
		}
	}
}

void	ft_drawcercle(void *mlx, void *win,int x1, int y1, int colour)
{
	int x;
	int y;
	int d;

	x = x1;
	y = y1;
	d = 1 - y1;
	mlx_pixel_put(mlx, win, x, y, colour);
	while (y > x)
	{
		if (d < 0)
			d += 2 * x + 3;
		else
		{
			d += 2 * (x - y) + 5;
			y--;
		}
		x++;
		mlx_pixel_put(mlx, win, x, y, colour);
	}

}

/*void	ft_drawline(void *mlx, void *win, int x1, int y1, int x2, int y2, int colour)
{
	int		x;
	int		y;
	int		dx;
	int		dy;
	int		D;

	x = x1;
	y = y1;
	if (x2 < x1 || y2 < y1)
	{
		printf("Je passe ici\n");
		ft_swap(&x1, &x2);
		ft_swap(&y1, &y2);
	}


	dx = x2 - x1;
	dy = y2 - y1;
//	D = (dy / dx);
	if (dx == 0 || dy == 0)
		D = 1;
	else
		D = (dy / dx);
//	x = x1;
//	y = y1;
	while (x <= x2)
	{
		mlx_pixel_put(mlx, win, x, y, colour);
		if (dy != 0)
			y = ((D * (x - x1)) + y1 + (1/2));
		x++;
	}
}*/



int		main(int argc, char **argv)
{
	t_fdf	list;

/*	int bits_per_pixel;
	int endian;
	int size_line;
	char *data;*/

	int colour;
//	int		a;
//	int		b;

	if (argc != 1)
	{
		printf("Mauvais nombre d'arguments!!\n");
		return (0);
	}
	(void)argv;

	list.mlx = mlx_init();
	list.win = mlx_new_window(list.mlx, WINDOW_H, WINDOW_W, "my window without curtains");


	// Tracer des lignes diagonales entre des points.
	colour = 0x00FFFFFF; // Blanc
	ft_drawline(list.mlx, list.win, 150, 150, 250, 150, colour);
	colour = 0x00458B74; // Vert Aqua
	ft_drawline(list.mlx, list.win, 250, 150, 300, 100, colour);
	colour = 0x004A708B; // Bleu
	ft_drawline(list.mlx, list.win, 300, 100, 200, 100, colour);
	colour = 0x00CDB5CD; // Rose
	ft_drawline(list.mlx, list.win, 200, 100, 200, 150, colour);
	colour = 0x00FFD700; // Gold
	ft_drawline(list.mlx, list.win, 200, 100, 200, 200, colour);
	colour = 0x00FFFFFF; // Blanc
	ft_drawline(list.mlx, list.win, 200, 200, 300, 200, colour);
	colour = 0x00458B74; // Vert Aqua
	ft_drawline(list.mlx, list.win, 200, 200, 150, 250, colour);
	colour = 0x004A708B; // Bleu
	ft_drawline(list.mlx, list.win, 150, 250, 250, 250, colour);
	colour = 0x00CDB5CD; // Rose
	ft_drawline(list.mlx, list.win, 250, 250, 200, 150, colour);
	colour = 0x00FFD700; // Gold
	ft_drawline(list.mlx, list.win, 200, 50, 250, 150, colour);
	colour = 0x00FFFFFF; // Blanc
	ft_drawline(list.mlx, list.win, 200, 200, 200, 110, colour);
	colour = 0x00458B74; // Vert Aqua
	ft_drawline(list.mlx, list.win, 200, 50, 200, 100, colour);


/*	colour = 0x00FFFFFF; // Blanc
	ft_putcercle(list.mlx, list.win, 200, 10, colour);*/



/*  // Pour les images.
	bits_per_pixel = 32; // MACOS force le bbp a 32 puisqu'il y a 8bits dans 1octet et 4 octets dans 1int
	endian = 1; // depart de lecture de l'int, si bigendian (1) depart a droite, sinon (0).
				// MACOS traite en bigendian.
	size_line = 0; // (int multiplie par le nbr d'octet dans l'int - 4)
	if(!(list.image = mlx_new_image(list.mlx, 10, 10)))
		exit(1);
	data = mlx_get_data_addr(list.image, &bits_per_pixel, &size_line, &endian);
	mlx_put_image_to_window(list.mlx, list.win, list.image, 200, 200);
*/


	// Gerer les interactions clavier->code
	mlx_key_hook(list.win, ft_key, &list);

	mlx_loop(list.mlx);
	return (0);
}
