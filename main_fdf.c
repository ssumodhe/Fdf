/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_fdf.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssumodhe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/09 19:13:00 by ssumodhe          #+#    #+#             */
/*   Updated: 2017/03/09 19:20:31 by ssumodhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		main(int argc, char **argv)
{
	int		fd;

	if (argc != 2)
	{
		ft_putstr("usage: ./fdf source_file\n");
		return (0);
	}
	if ((fd = open(argv[1], O_RDWR)) < 0)
	{
		ft_putstr(RED"open: fail\n"RESET"Try another source file\n");
		return (0);
	}

	ft_getmap(fd);

	if (close(fd) < 0)
	{
		ft_putstr(RED"close: fail\n"RESET);
		return (0);
	}
	return (0);
}
