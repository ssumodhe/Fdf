/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_fdf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssumodhe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/13 14:25:47 by ssumodhe          #+#    #+#             */
/*   Updated: 2017/03/20 18:05:30 by ssumodhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*int		ft_checkdata(char **data)
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
			if ((data[a][b] < 48 || data[a][b] > 57) && (data[a][b] < 65 || data[a][b] > 90) \
					&& (data[a][b] < 97 || data[a][b] > 122) \
					&& (data[a][b] != ',') && (data[a][b] != '-'))
				ft_exit(RED"map incorrect"RESET);
			ft_putstr(GREEN);
			ft_putchar(data[a][b]);
			b++;
		}
		nb++;
			ft_putstr(RED"------>");
			ft_putnbr(nb);
			ft_putstr(RESET"\n");
		a++;
	}
	if (nb == 0)
		ft_exit(RED"map incorrect"RESET);
	return (nb);
}

void	ft_parsemap(t_data	*data)
{
	t_data	*tmp;
	int		nb_width;
	int		compare;
	int		nb_height;

				ft_putendl(HIGHLIGHT"\nPHASE 2 --> PARSING\n"RESET);

	tmp = data;
	nb_height = 0;
	compare = 0;
	while (tmp->next != NULL)
	{
		ft_putstr(YELLOW"line --> ");
		ft_putchar('<');
		ft_putstr(tmp->line);
		ft_putchar('>');
		ft_putchar('\n');
		ft_putstr(RESET);
		if (tmp->line[0] == '\n' || tmp->line[0] == '\0')
			ft_exit(RED"map incorrect"RESET);
		nb_width = ft_checkdata(tmp->data_line);
		
		//Verifie qu'il y ait bien le meme nombre de point par ligne.
		
		if (compare != 0 && compare != nb_width)
			ft_exit(RED"map incorrect"RESET);
		compare = nb_width;
		nb_height++;
		tmp = tmp->next;
	}
	ft_putendl(GREEN"map: OK\n"RESET);
}*/

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

int		ft_checkdata(char **data)
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
			if ((data[a][b] < 48 || data[a][b] > 57) && (data[a][b] < 65 || data[a][b] > 90) \
					&& (data[a][b] < 97 || data[a][b] > 122) \
					&& (data[a][b] != ',') && (data[a][b] != '-'))
				ft_exit(RED"map: incorrect"RESET);
			b++;
		}
		nb++;
		a++;
	}
	if (nb == 0)
		ft_exit(RED"map: incorrect"RESET);
	return (nb);
}

t_map	*ft_parsemap(t_data	*data)
{
	t_data	*tmp;
	t_map	*map;
	t_map	*tmp_map;
	int		compare;

				ft_putendl(HIGHLIGHT"\nPHASE 2 --> PARSING\n"RESET);

	tmp = data;
	if ((map = (t_map *)malloc(sizeof(* map))) == NULL)
		ft_exit(RED"error malloc t_map *map"RESET);
	map->height = 0;
	compare = 0;
	while (tmp->next != NULL)
	{
		// dire que tmp->line[0] si != '-' ou d'un chiffre : mauvais
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

	ft_putstr("high point = ");
	ft_putnbr(map->highest);
	ft_putchar('\n');
	ft_putstr("low point = ");
	ft_putnbr(map->lowest);
	ft_putchar('\n');

	ft_putendl(GREEN"map: OK\n"RESET);
	return (map);
}
