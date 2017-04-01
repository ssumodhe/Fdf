/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_fdf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssumodhe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/13 14:25:47 by ssumodhe          #+#    #+#             */
/*   Updated: 2017/04/01 18:12:37 by ssumodhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		ft_get_highest(t_data *data, t_map *map)
{
	t_data	*tmp_data;
	int		a;
	int		compare_h;
	int		compare_l;
	int		point;

	compare_h = 0;
	compare_l = 0;
	tmp_data = data;
	while (tmp_data->next != NULL)
	{
		a = 0;
		while (tmp_data->data_line[a])
		{
			point = ft_atoi(tmp_data->data_line[a]);
			if (point >= 0 && compare_h <= point)
				compare_h = point;
			if (point < 0 && compare_l >= point)
				compare_l = point;
			a++;
		}
		tmp_data = tmp_data->next;
	}
	map->highest = compare_h;
	map->lowest = compare_l;
}

int			ft_checkdata(char **data)
{
	int		a;
	int		b;
	int		nb;

	a = 0;
	nb = 0;
	while (data[a] != NULL)
	{
		b = 0;
		while (data[a][b] != '\0')
		{
			if ((data[a][b] < 48 || data[a][b] > 57) && \
					(data[a][b] < 65 || data[a][b] > 90) \
					&& (data[a][b] < 97 || data[a][b] > 122) \
					&& (data[a][b] != ',') && (data[a][b] != '-'))
				ft_exit(RED"map: incorrect"RESET);
			b++;
		}
		nb++;
		a++;
	}
	if (nb == 0 || nb == 1)
		ft_exit(RED"map: incorrect"RESET);
	return (nb);
}

t_map		*ft_parsemap(t_data *data)
{
	t_data	*tmp;
	t_map	*map;
	t_map	*tmp_map;
	int		compare;

	tmp = data;
	if ((map = (t_map *)malloc(sizeof(*map))) == NULL)
		ft_exit(RED"error malloc t_map *map"RESET);
	map->height = 0;
	compare = 0;
	while (tmp->next != NULL)
	{
		if (tmp->line[0] == '\n' || tmp->line[0] == '\0')
			ft_exit(RED"map: incorrect"RESET);
		map->width = ft_checkdata(tmp->data_line);
		if (compare != 0 && compare != map->width)
			ft_exit(RED"map: incorrect"RESET);
		compare = map->width;
		map->height++;
		tmp = tmp->next;
	}
	tmp_map = map;
	ft_get_highest(data, map);
	return (map);
}
