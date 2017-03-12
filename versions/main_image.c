/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssumodhe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/22 15:20:22 by ssumodhe          #+#    #+#             */
/*   Updated: 2017/02/23 12:32:39 by ssumodhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stdlib.h>
#include <stdio.h>

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
** Code ttt
*/

void	 ft_put_sqr(void *mlx, void *win, int x, int y, int colour)
{
	int		i;
	int		j;

	i = x;

//	colour = 123;

//	x = 150;
	while (i < (x + 100))
	{
		j = y;
//		y = 150;
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
		exit(1);
	return (0);
}


int		main(void)
{
//	void	*mlx;
//	void	*win;
	t_fdf	list;
	int		a;
	int bits_per_pixel;
	int endian;
	int size_line;
	char *data;
/*int		x = 150;
int		y = 150;*/

	list.mlx = mlx_init();
	list.win = mlx_new_window(list.mlx, 400, 400, "my window without curtains");
//	list.win_2 = mlx_new_window(list.mlx, 400, 400, "my window");


//	ft_put_sqr(list.mlx, list.win, x, y, 0x004682B4);


/*	list.image = mlx_new_image(list.mlx, 120, 120);
	mlx_pixel_put(list.mlx, list.image, 20, 20, 0x0046682B4);
	mlx_put_image_to_window(list.mlx, list.win, list.image, 0, 0);*/


	bits_per_pixel = 32; // MACOS force le bbp a 32 puisqu'il y a 8bits dans 1octet et 4 octets dans 1int
	endian = 1; // depart de lecture de l'int, si bigendian (1) depart a droite, sinon (0).
				// MACOS traite en bigendian.
	size_line = 0; // (int multiplie par le nbr d'octet dans l'int - 4)
	if(!(list.image = mlx_new_image(list.mlx, 10, 10)))
		exit(1);
//	mlx_pixel_put(list.mlx, list.image, 20, 20, 0x0046682B4);
	data = mlx_get_data_addr(list.image, &bits_per_pixel, &size_line, &endian);
	a = 0;
	/*
	while (a < 5)
	{
		if (a % 4 == 0)
			data[a] = 0xFF;
		else
			data[a] = 0xFF;
		a++;

	}
	*/
	
	data[0] = 0x00;
	data[1] = 0x00;
	data[2] = 0xFF;
	data[3] = 0x00;

	data[36] = 0x00;
	data[37] = 0x00;
	data[38] = 0xFF;
	data[39] = 0x00;

	data[360] = 0xFF;
	data[361] = 0xFF;
	data[362] = 0xFF;
	data[363] = 0x00;

	data[396] = 0x00;
	data[397] = 0xFF;
	data[398] = 0x00;
	data[399] = 0x00;

	
//	mlx_pixel_put(list.mlx, list.image, 20, 20, 0x0046682B4);
	mlx_put_image_to_window(list.mlx, list.win, list.image, 200, 200);



	mlx_key_hook(list.win, ft_key, &list);



	mlx_loop(list.mlx);
	return (0);
}
