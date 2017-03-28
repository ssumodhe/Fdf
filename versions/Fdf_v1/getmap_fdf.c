/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getmap_fdf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssumodhe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/13 14:24:30 by ssumodhe          #+#    #+#             */
/*   Updated: 2017/03/27 18:01:50 by ssumodhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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
	char	*line;
	t_data	*data;
	t_data	*tmp_data;

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
		tmp_data = tmp_data->next;
	}
	return (data);
}
