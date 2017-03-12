/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_fdf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssumodhe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/09 15:25:29 by ssumodhe          #+#    #+#             */
/*   Updated: 2017/03/09 19:22:16 by ssumodhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_exit(char *str)
{
	ft_putendl(str);
	exit(1);
}

void	check_chr(char *line)
{
	int i;

	i = 0;
	while (line[i] != '\0')
	{
		if ((line[i] < 48 || line[i] > 57) && (line[i] < 65 || line[i] > 90) \
				&& (line[i] < 97 || line[i] > 122) \
				&& (line[i] != ',') && (line[i] != ' '))
		{
			ft_putstr(RED);//
			ft_putendl(line);//
			ft_putstr(GREEN);//
			ft_putchar('<');//
			ft_putchar(line[i]);//
			ft_putchar('>');//
			ft_putstr(RESET);//
			ft_exit(RED"map incorrect"RESET);
		}
		i++;
	}
}

void	ft_getmap(int fd)
{
	char	*line;
	t_map	*map;
	int		a;
	int		b;

	line = NULL;
	if ((map = (t_map *)malloc(sizeof(*map))) == NULL)
		ft_exit("error malloc t_map *map");
	map->line = NULL;
	map->next = NULL;
	while (get_next_line(fd, &line) == 1)
	{
		ft_putendl(line);

		check_chr(line);

		map->line = ft_strsplit(line, ' ');
		a = 0;
		while (map->line[a] != NULL)
		{
			b = 0;
			while (map->line[a][b] != '\0')
			{
				ft_putstr(GREEN);
				ft_putchar(map->line[a][b]);
				ft_putstr(RESET);
				b++;
			}
			ft_putchar(' ');
			a++;
		}
		ft_putchar('\n');


		ft_strdel(&line);
	}
}
