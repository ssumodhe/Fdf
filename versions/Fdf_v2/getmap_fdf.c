/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getmap_fdf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssumodhe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/13 14:24:30 by ssumodhe          #+#    #+#             */
/*   Updated: 2017/03/31 17:24:52 by ssumodhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		ft_checkcpt(int cpt)
{
	if (cpt == 0)
		ft_exit(RED"map: incorrect"RESET"\nNo data found.");
	else if (cpt == 1)
		ft_exit(RED"map: incorrect"RESET"\nNeed more data.");
}

t_data		*ft_addnewdatalst(void)
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

t_data		*ft_getmap(int fd)
{
	int		cpt;
	char	*line;
	t_data	*data;
	t_data	*tmp_data;

	cpt = 0;
	line = NULL;
	data = ft_addnewdatalst();
	tmp_data = data;
	while (get_next_line(fd, &line) == 1)
	{
		data->line = ft_strdup(line);
		ft_strdel(&line);
		data->next = ft_addnewdatalst();
		data = data->next;
		cpt++;
	}
	ft_checkcpt(cpt);
	data = tmp_data;
	while (tmp_data->next != NULL)
	{
		tmp_data->data_line = ft_strsplit(tmp_data->line, ' ');
		tmp_data = tmp_data->next;
	}
	return (data);
}
