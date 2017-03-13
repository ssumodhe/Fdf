/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_image.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssumodhe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/13 18:28:11 by ssumodhe          #+#    #+#             */
/*   Updated: 2017/03/13 18:59:16 by ssumodhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>

typedef struct		s_fdf
{
	void	*mlx;
	void	*win;
	void	*image;
}					t_fdf;

int		main()
{
	t_fdf	fdf;
	int bits_per_pixel;
	int endian;
	int size_line;
	int	x;

	fdf.mlx = mlx_init();
	fdf.win = mlx_new_window(fdf.mlx, 400 , 400, "my window");

	bits_per_pixel = 32;
	endian = 1; 
	size_line = 0;
	if(!(fdf.image = mlx_new_image(fdf.mlx, 200, 200)))
		return (0);

	mlx_put_image_to_window(fdf.mlx, fdf.win, fdf.image, 50, 50);
	x = 0;
	while (x < 170)
	{
		mlx_pixel_put(fdf.mlx, fdf.image, x, 10, 0x00FF0000);
		x++;
	}
	mlx_string_put(fdf.mlx, fdf.win, 10, 10, 0x00FFFFFF, "Hello");

	mlx_loop(fdf.mlx);
}
