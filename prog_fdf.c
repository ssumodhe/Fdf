

#include "fdf.h"

void	ft_exit(char *str)
{
	ft_putendl(str);
	exit(1);
}

void	ft_prog(int fd)
{
	t_data	*data;

	data = ft_getmap(fd);
}
