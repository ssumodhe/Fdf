/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssumodhe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/22 15:20:22 by ssumodhe          #+#    #+#             */
/*   Updated: 2017/02/23 17:53:57 by ssumodhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stdlib.h>
#include <stdio.h>
#include "libft/libft.h"

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

void	ft_put_roof(void *mlx, void *win, int x1, int y1, int x2, int y2, int colour)
{
	int		x;
	int		y;
	int		dx;
	int		dy;
	int		D;

	// gerer les cas particuliers
	dx = x2 - x1;
	dy = y2 - y1;
	D = (dy / dx);
	x = x1;
	y = y1;
	while (x <= x2)
	{
		mlx_pixel_put(mlx, win, x, y, colour);
		
		if (dy != 0)
			y = ((D * (x - x1)) + y1 + (1/2));


		x++;
	}
}

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
	if (keycode == 15)
		ft_put_sqr(param->mlx, param->win, x, y, 0x00FF0000);
	if (keycode == 13)
		ft_put_sqr(param->mlx, param->win, x, y, 0x00FFFFFF);
	if (keycode == 11)
		ft_put_sqr(param->mlx, param->win, x, y, 0x000000FF);
	if (keycode == 9)
		ft_put_sqr(param->mlx, param->win, x, y, 0x0000FF00);
	if (keycode == 126)
		ft_put_sqr(param->mlx, param->win, x, y - 10, 0x00FFFFFF);
	if (keycode == 125)
		ft_put_sqr(param->mlx, param->win, x, y + 10, 0x00FFFFFF);
	if (keycode == 123)
		ft_put_sqr(param->mlx, param->win, x - 10, y, 0x00FFFFFF);
	if (keycode == 124)
		ft_put_sqr(param->mlx, param->win, x + 10, y, 0x00FFFFFF);
	if (keycode == 53)
		exit(0);
	return (0);
}


int		main(int argc, char **argv)
{
	t_fdf	list;

/*	int bits_per_pixel;
	int endian;
	int size_line;
	char *data;*/

	int colour;
	int		a;
	int		b;

	if (argc != 1)
	{
		printf("Mauvais nombre d'arguments!!\n");
		return (0);
	}
	(void)argv;

	list.mlx = mlx_init();
	list.win = mlx_new_window(list.mlx, 400, 400, "my window without curtains");

	colour = 0x00FFFFFF;
/*	// Afficher les points/coins de la maison_test.
 	a = 200;
	b = 50;
	mlx_pixel_put(list.mlx, list.win, a, b, colour);
	a = 150;
	b = 150;
	mlx_pixel_put(list.mlx, list.win, a, b, colour);
	a = 250;
	b = 150;
	mlx_pixel_put(list.mlx, list.win, a, b, colour);
	a = 150;
	b = 250;
	mlx_pixel_put(list.mlx, list.win, a, b, colour);
	a = 250;
	b = 250;
	mlx_pixel_put(list.mlx, list.win, a, b, colour);
*/

    // Tracer des lignes droites entres des points.
	a = 150;
	b = 150;
	while (b <= 250)
	{
		mlx_pixel_put(list.mlx, list.win, a, b, colour);
		b++;
	}
	a = 150;
	b = 250;
	while (a <= 250)
	{
		mlx_pixel_put(list.mlx, list.win, a, b, colour);
		a++;
	}
	a = 250;
	b = 250;
	while (b >= 150)
	{
		mlx_pixel_put(list.mlx, list.win, a, b, colour);
		b--;
	}
	a = 250;
	b = 150;
	while (a >= 150)
	{
		mlx_pixel_put(list.mlx, list.win, a, b, colour);
		a--;
	}


	// Tracer des lignes diagonales entre des points.
	colour = 0x00FF0000;
	ft_put_roof(list.mlx, list.win, 150, 150, 200, 100, colour);
	ft_put_roof(list.mlx, list.win, 200, 100, 250, 150, colour);
	colour = 0x0000FF00;
	ft_put_roof(list.mlx, list.win, 150, 150, 200, 50, colour);
	ft_put_roof(list.mlx, list.win, 200, 50, 250, 150, colour);


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


/*	// Afficher un repere x, y et z.
	colour = 0x00FFFFFF;
	a = 200;
	while (a < 300)
	{
		mlx_pixel_put(list.mlx, list.win, a, 200, colour);
		a++;
	}
	b = 200;
	while (b > 100)
	{
		mlx_pixel_put(list.mlx, list.win, 200, b, colour);
		b--;
	}
	a = 200;
	b = 200;
	while (a > 100 && b < 260)
	{
		mlx_pixel_put(list.mlx, list.win, a, b, colour);
		a--;
		b++;
	}
*/

	// Gerer les interactions clavier->code
	mlx_key_hook(list.win, ft_key, &list);

	mlx_loop(list.mlx);
	return (0);
}
