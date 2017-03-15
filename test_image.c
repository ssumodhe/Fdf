/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_image.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssumodhe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/13 18:28:11 by ssumodhe          #+#    #+#             */
/*   Updated: 2017/03/15 13:05:50 by ssumodhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "libft/libft.h"

void	ft_pixel_put_img(char *image_addr, int x, int y)
{
	int		i;

	i = (4 * (x + (y * 200)));
	image_addr[i + 0] = 0xFF;
	image_addr[i + 1] = 0xFF;
	image_addr[i + 2] = 0xFF;
	image_addr[i + 3] = 0x00;

}

void	ft_drawline_img(char *image_addr,int x1, int y1, int x2, int y2, int colour)
{
	int		i;
	int		x;
	int		y;
	int		dx;
	int 	dy;
	int		xinc;
	int		yinc;
	int		cumul;

	(void)colour;
	x = x1;
	y = y1;
	dx = x2 - x1;
	dy = y2 - y1;
	xinc = (dx > 0) ? 1 : -1;
	yinc = (dy > 0) ? 1 : -1;
	dx = (dx < 0) ? -dx : dx;
	dy = (dy < 0) ? -dy : dy;

	ft_pixel_put_img(image_addr, x, y);
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
			ft_pixel_put_img(image_addr, x, y);
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
			ft_pixel_put_img(image_addr, x, y);
			i++;
		}
	}
}

typedef struct		s_fdf
{
	void	*mlx;
	void	*win;
	void	*image;
}					t_fdf;

int		main()
{
	t_fdf	fdf;
	char	*image_addr;
	int bits_per_pixel;
	int endian;
	int size_line;
	int	x;
	int	i;
	int y;

	fdf.mlx = mlx_init();
	fdf.win = mlx_new_window(fdf.mlx, 400 , 400, "my window");

	bits_per_pixel = 32;
	endian = 1; 
	size_line = 4;
	if(!(fdf.image = mlx_new_image(fdf.mlx, 200, 200)))
		return (0);
	image_addr = mlx_get_data_addr(fdf.image, &bits_per_pixel, &size_line, &endian);
	mlx_put_image_to_window(fdf.mlx, fdf.win, fdf.image, 10, 100);

	x = 5;
	y = 10;
	ft_pixel_put_img(image_addr, x, y);
	ft_drawline_img(image_addr, 5, 10, 90, 19, 0x00FFFFFF);
/*	i = (4 * (x + (y * 200)));
	image_addr[i + 0] = 0xFF;
	image_addr[i + 1] = 0xFF;
	image_addr[i + 2] = 0x00;*/

// Ligne du haut
	y = 0;
	x = 0;
		while (x < 200)
		{
			i = (4 * (x + (y * 200)));
			image_addr[i + 0] = 0xFF;
			image_addr[i + 1] = 0xFF;
			image_addr[i + 2] = 0xFF;
			x++;
		}
//Ligne du bas
	y = 199;
	x = 0;
		while (x < 200)
		{
			i = (4 * (x + (y * 200)));
			image_addr[i + 0] = 0xFF;
			image_addr[i + 1] = 0xFF;
			image_addr[i + 2] = 0xFF;
			x++;
		}
		
//Verticale droite
	y = 0;
	x = 0;
		while (y < 200)
		{
			i = (4 * (x + (y * 200)));
			image_addr[i + 0] = 0xFF;
			image_addr[i + 1] = 0xFF;
			image_addr[i + 2] = 0xFF;
			y++;
		}
//Verticale gauche
	y = 0;
	x = 199;
		while (y < 200)
		{
			i = (4 * (x + (y * 200)));
			image_addr[i + 0] = 0xFF;
			image_addr[i + 1] = 0xFF;
			image_addr[i + 2] = 0xFF;
			y++;
		}


// Rempli toute l'image.
/*	y = 0;
	while (y < 201)
	{
		x = 0;
		while (x < 201)
		{
			i = (4 * (x + (y * 200)));
			image_addr[i + 0] = 0xFF;
			image_addr[i + 1] = 0x00;
			image_addr[i + 2] = 0x00;
			x++;
		}
		y++;
	}*/

	mlx_string_put(fdf.mlx, fdf.win, 10, 10, 0x00FFFFFF, "Hello");

	mlx_loop(fdf.mlx);
}
