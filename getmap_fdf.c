/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getmap_fdf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssumodhe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/13 14:24:30 by ssumodhe          #+#    #+#             */
/*   Updated: 2017/03/13 16:48:15 by ssumodhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_data	*ft_addnewdatalst()
{
	t_data	*data;

	if ((data = (t_data *)malloc(sizeof(*data))) == NULL)
		ft_exit("error malloc t_data *data");
	data->line = NULL;
	data->data_line = NULL;
	data->map = NULL;
	data->next = NULL;
	return (data);
}


t_data	*ft_getmap(int fd)  // FONCTIONNEL + NORME
{
	char	*line;
	t_data	*data;
	t_data	*tmp_data;

			ft_putendl(HIGHLIGHT"\nPHASE 1 --> GET MAP\n"RESET);

	line = NULL;
	data = ft_addnewdatalst();
	tmp_data = data;
	while (get_next_line(fd, &line) == 1)
	{
		data->line = ft_strdup(line);
		ft_putendl(line);
		data->next = ft_addnewdatalst();
		data = data->next;
	}
	ft_putendl(GREEN"\ndata->lignes: OK"RESET);
	data = tmp_data;
	while (tmp_data->next != NULL)
	{
		tmp_data->data_line = ft_strsplit(tmp_data->line, ' ');
		tmp_data = tmp_data->next;	
	}
	ft_putendl(GREEN"data->cases: OK"RESET);
	return (data);
}

/*t_data	*ft_getmap(int fd)
{
	char	*line;
	t_data	*data;
	t_data	*tmp_data;
	int		a;

			ft_putendl(HIGHLIGHT"\nPHASE 1 --> GET MAP\n"RESET);

	line = NULL;
	data = ft_addnewdatalst();
	tmp_data = data;
	while (get_next_line(fd, &line) == 1)
	{
		data->line = ft_strdup(line);
		data->next = ft_addnewdatalst();
		data = data->next;
	}
	data = tmp_data;
	while (tmp_data->next != NULL)
	{
		tmp_data->data_line = ft_strsplit(tmp_data->line, ' ');
			ft_putstr(GREEN);
			ft_putendl(tmp_data->line);
			ft_putstr(RESET);
		a = 0;
		while (tmp_data->data_line[a] != NULL)
		{
			ft_putstr(RED);
			ft_putstr(tmp_data->data_line[a]);
			ft_putchar(' ');
			ft_putstr(RESET);
			a++;
		}
			ft_putchar('\n');
		tmp_data = tmp_data->next;	
	}
	return (data);
}*/
