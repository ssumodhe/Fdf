

#include "fdf.h"

t_data	*ft_addnewdatalst()
{
	t_data	*data;

	if ((data = (t_data *)malloc(sizeof(*data))) == NULL)
		ft_exit("error malloc t_data *data");
	data->line = NULL;
	data->data_line = NULL;
	data->next = NULL;
	return (data);
}

/*void	ft_getmap(t_data	**data)
{
	t_data	*tmp_data;
	int		a;

	tmp_data = *data; //check ordre
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
}

void	ft_getline(int fd)
{
	char	*line;
	t_data	*data;
	t_data	*tmp_data;
	int		a;

	a = 0;
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
	ft_getmap(&data);
}*/

/*
t_data	*ft_getmap(int fd)  // FONCTIONNEL + NORME
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
}*/

t_data	*ft_getmap(int fd)
{
	char	*line;
	t_data	*data;
	t_data	*tmp_data;
	int		a;

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
}
