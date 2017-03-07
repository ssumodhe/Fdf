/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssumodhe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/22 15:20:22 by ssumodhe          #+#    #+#             */
/*   Updated: 2017/03/07 18:20:15 by ssumodhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stdlib.h>
#include <stdio.h>
#include "libft/libft.h"

// Pour centrer l'image.
#define WINDOW_H 600
#define WINDOW_W 400
#define GAP 20

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


int		main(int argc, char **argv)
{
	t_fdf	list;
	int		**tab;
	int		x;
	int		y;
	int		z;
	int		x_orig;
	int		y_orig;
	int		nb_line;
	int		nb_col;
	int		largeur;
	int		hauteur;
	int 	colour;
	int		gap;
	float	coeff;
//	int		a;
//	int		b;

/*	int bits_per_pixel;
	int endian;
	int size_line;
	char *data;*/

	colour = 0x00FFFFFF; // Blanc

	if (argc != 1)
	{
		printf("Mauvais nombre d'arguments!!\n");
		return (0);
	}
	(void)argv;

	
	list.mlx = mlx_init();
	list.win = mlx_new_window(list.mlx, WINDOW_H, WINDOW_W, "my window without curtains");
	
// Generer un tableau.
	if ((tab = (int **)malloc(sizeof(int *) * (2 + 1))) == NULL)
		return (0);
	y = 0;
	while (y < 3)
	{
		if ((tab[y] = (int *)malloc(sizeof(int) * (4 + 1))) == NULL)
			return (0);
		x = 0;
		while (x < 5)
		{
			tab[y][x] = 0;
			x++;
		}
		y++;
	}

	y = 0;
	while (y < 3)
	{
		x = 0;
		while (x < 5)
		{
			printf("%d ", tab[y][x]);
			x++;
		}
		printf("\n");
		y++;
	}

// Generer le plan.
//	colour = 0x0000868B;
	colour = 0x00FFFFFF;
	hauteur = 10;
	largeur = 10;
	nb_line = 1;
	nb_col = 1;
	x_orig = 0; // Deplace le plan sur l'axe horizontal. (GAUCHE/DROITE)
	y_orig = 200; // Deplace le plan sur l'axe vertical. (HAUT/BAS)
	gap = 50; // Taille de la diagonale d'une case. (ZOOM +/-)
	coeff = 0.15; // [0 ; 0.5] Oriente la vue du plan. (DESSUS/DESSOUS)
	z = 10;
	y = y_orig;
	x = x_orig;
	while (nb_line <= hauteur)
	{
		nb_col = 1;
		while (nb_col <= largeur)
		{
		//	ft_drawline(list.mlx, list.win, x, y, x + gap, y, colour);
		//	ft_drawline(list.mlx, list.win, x + (gap/2), y, x + (gap/2), y - (gap/3), colour);
			if (nb_col == 2)
			{
				ft_drawline(list.mlx, list.win, x, y, x + (gap/2), y - (gap * coeff) - (z + gap), colour);
				ft_drawline(list.mlx, list.win, x + (gap/2), y - (gap * coeff) - (z + gap), x + gap, y - (z + gap), 0x0000FF00);
				ft_drawline(list.mlx, list.win, x + gap, y - (z + gap), x + (gap/2), y + (gap * coeff), 0x00FF0000);
				ft_drawline(list.mlx, list.win, x + (gap/2), y + (gap * coeff), x, y, colour);
			}
			if (nb_col == 3)
			{
				ft_drawline(list.mlx, list.win, x, y - (z + gap), x + (gap/2), y - (gap * coeff), colour);
				ft_drawline(list.mlx, list.win, x + (gap/2), y - (gap * coeff), x + gap, y, 0x0000FF00);
				ft_drawline(list.mlx, list.win, x + gap, y, x + (gap/2), y + (gap * coeff) - (z +gap), 0x00FF0000);
				ft_drawline(list.mlx, list.win, x + (gap/2), y + (gap * coeff) - (z + gap), x, y - (z + gap), 0x00FFC125);
			}
	

			if (nb_col != 3 && nb_col != 2)
			{
				ft_drawline(list.mlx, list.win, x, y, x + (gap/2), y - (gap * coeff), colour);
				ft_drawline(list.mlx, list.win, x + (gap/2), y - (gap * coeff), x + gap, y, colour);
				ft_drawline(list.mlx, list.win, x + gap, y, x + (gap/2), y + (gap * coeff), colour); //important pour la derniere diagonale
				ft_drawline(list.mlx, list.win, x + (gap/2), y + (gap * coeff), x, y, colour);
			}
			x = x + (gap * 1/2);
			y = y - (gap * coeff);
			nb_col++;
		colour = colour + 1340000;
		}
		x = x_orig + (gap * 1/2 * nb_line);
		y = y_orig + (gap * coeff * nb_line);
		nb_line++;
	}

	//Repere


	// Plan droit

	x_orig = 300;
	y_orig = 300;
	hauteur = 3;
	largeur = 5;
	colour = 0x008B5A2B;
	y = y_orig;
	while (y < (y_orig + (hauteur * GAP)))
	{
		x = x_orig;
		while (x < (x_orig + (largeur * GAP)))
		{
			if ((y + GAP) < (y_orig + (hauteur * GAP)))
			{
				colour = 0x00FF0000; // Red
				ft_drawline(list.mlx, list.win, x, y, x, (y + GAP), colour);
			}
			if ((x + GAP) < (x_orig + (largeur * GAP)))
			{
				colour = 0x0000FF00; // Green
				ft_drawline(list.mlx, list.win, x, y, (x + GAP), y, colour);
			}
			x = x + GAP;
		}
		y = y + GAP;
	}

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
