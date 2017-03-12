

#include "fdf.h"

void	ft_exit(char *str)
{
	ft_putendl(str);
	exit(1);
}

t_data	*ft_addnewdatalst()
{
	t_data	*data;

	if ((data = (t_data *)malloc(sizeof(*data))) == NULL)
		ft_exit("error malloc t_data *data");
	data->line = NULL;
	data->next = NULL;
	return (data);
}

void	ft_getmap(t_data	**data)
{
	t_data	*tmp_data;

	tmp_data = *data;
	while (tmp_data->next != NULL)
	{
		ft_putstr(GREEN);
		ft_putendl(tmp_data->line);
		ft_putstr(RESET);
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
//		ft_putendl(line);
		data->line = ft_strdup(line);
//		ft_putstr(YELLOW);
//		ft_putendl(data->line);
//		ft_putstr(RESET);
		data->next = ft_addnewdatalst();
		data = data->next;
	}
	data = tmp_data;
	ft_getmap(&data);

}
