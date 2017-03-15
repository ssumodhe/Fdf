/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssumodhe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/09 15:02:38 by ssumodhe          #+#    #+#             */
/*   Updated: 2017/03/15 19:04:49 by ssumodhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft/libft.h"
# include <mlx.h>
# include <fcntl.h>

# define WIN_NAME "My window without curtains"
# define GAP 50

typedef struct		s_fdf
{
	void	*mlx; //serveur
	void	*win; //fenetre
	void	*img; //image
	char	*img_addr;
}					t_fdf;

typedef struct		s_map
{
	int		height;
	int		width;
	t_fdf	fdf;
}					t_map;

typedef struct		s_data
{
	char 			*line;
	char			**data_line;
	t_map			*map;
	struct s_data	*next;
}					t_data;

void				ft_prog(int fd);
void				ft_exit(char *str);

t_data				*ft_getmap(int fd);
t_data				*ft_addnewdatalst();

t_map				*ft_parsemap(t_data *data);
int					ft_checkdata(char **data);

void				ft_createwindow(t_map *map, t_data *data);


#endif
