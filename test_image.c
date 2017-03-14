/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_image.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssumodhe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/13 18:28:11 by ssumodhe          #+#    #+#             */
/*   Updated: 2017/03/14 18:47:59 by ssumodhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "libft/libft.h"

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

	x = 0;
	y = 0;
	y++;
	if (x > 200 && y != 0)
	{
		i = 4 * (x/y) - 4;
	}
	else if (x != 0 && y != 0)
		i = 4 * x - 4;
	else
		i = 4 * x;
	image_addr[i + 0] = 0xFF;
	image_addr[i + 1] = 0xFF;
	image_addr[i + 2] = 0xFF;
	image_addr[i + 3] = 0x00;
	x = 0;
	y = 10;
	i = (((4 * x) - 4) + (y * 200));
	image_addr[i + 0] = 0x00;
	image_addr[i + 1] = 0x00;
	image_addr[i + 2] = 0xFF;
	image_addr[i + 3] = 0x00;


/*	x = 0;	// extreme gauche haute
	y = 0;
	i = (4 * 200 * y) - (4 * x - 4);
	if (i < 0)
		i = i * -1;
//	while (x < 170)
//	{	
		image_addr[i + 0] = 0xFF;
		image_addr[i + 1] = 0xFF;
		image_addr[i + 2] = 0xFF;
		image_addr[i + 3] = 0x00;
		ft_putnbr(x);
		ft_putendl("");
		// extreme droite haute
		x = 200;
		y = 0;
	i = (4 * 200 * y) - (4 * x - 4);
	if (i < 0)
		i = i * -1;
		image_addr[i + 0] = 0x00;
		image_addr[i + 1] = 0x00;
		image_addr[i + 2] = 0xFF;
		image_addr[i + 3] = 0x00;
	//	x = (4 * 200 * 200) - 4; 
	//	// extreme droite basse
	x = 0;	
	y = 200;
	i = (4 * 200 * y) - (4 * 200 * x - 4);
	if (i < 0)
		i = i * -1;
		image_addr[i + 0] = 0x00;
		image_addr[i + 1] = 0xFF;
		image_addr[i + 2] = 0x00;
		image_addr[i + 3] = 0x00;
//		x = (4 * 200 * 200) - (4 * 200); 
//		// extreme gauche basse
	x = 200;
	y = 200;
	i = (4 * 200 * y) - (4 * x - 4);
	if (i < 0)
		i = i * -1;
		image_addr[i + 0] = 0xFF;
		image_addr[i + 1] = 0x00;
		image_addr[i + 2] = 0x00;
		image_addr[i + 3] = 0x00;
	//	x = (4 * 200/2);
	//	image_addr[x + 0] = 0x00;
	//	image_addr[x + 1] = 0x00;
	//	image_addr[x + 2] = 0xFF;
	//	image_addr[x + 3] = 0x00;
//	}*/




	mlx_put_image_to_window(fdf.mlx, fdf.win, fdf.image, 10, 100);
	mlx_string_put(fdf.mlx, fdf.win, 10, 10, 0x00FFFFFF, "Hello");

	mlx_loop(fdf.mlx);
}
