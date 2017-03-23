/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssumodhe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/09 15:02:38 by ssumodhe          #+#    #+#             */
/*   Updated: 2017/03/23 20:21:02 by ssumodhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft/libft.h"
# include "minilibx/mlx.h"
# include <fcntl.h>
# include <math.h>

# define WIN_NAME "My window without curtains"
# define GAP 25

typedef struct		s_image
{
	int		img_h;
	int		img_w;
	int		x_orig;
	int		y_orig;
	int		gap;
	char	*img_addr;
}					t_image;

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
	int		highest;
	int		lowest;
	int		k;
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

void				ft_graph_part(t_map *map, t_data *data);
void				ft_createwindow(t_map *map, t_data *data, t_image *image);

void				ft_design_image(t_map *map, t_data *data, t_image *image);
int					ft_getcolour(char *point);
void				ft_drawline_img(t_image *image, int x1, int y1, int x2, int y2, int colour);
void				ft_choose_side(int dx, int dy, int x, int y, int xinc, int yinc, t_image *image, int colour);
void				ft_pixel_put_img(t_image *img, int x, int y, int colour);
int					ft_atoi_base(const char *str, int str_base);

#endif
