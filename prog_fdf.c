/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prog_fdf.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssumodhe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/13 14:26:16 by ssumodhe          #+#    #+#             */
/*   Updated: 2017/03/20 14:52:03 by ssumodhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_exit(char *str)
{
	ft_putendl(str);
	exit(1);
}

void	ft_prog(int fd)
{
	t_data	*data;
	t_map	*map;

	data = ft_getmap(fd);
	map = ft_parsemap(data);
	ft_graph_part(map, data);
}
