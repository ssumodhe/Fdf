/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssumodhe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/09 15:02:38 by ssumodhe          #+#    #+#             */
/*   Updated: 2017/04/01 18:56:09 by ssumodhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft/libft.h"
# include <mlx.h>
# include <fcntl.h>
# include <math.h>

# define WIN_NAME "My window without curtains"
# define GAP 25
# define CHAR_WHITE "0x00FFFFFF"
# define CHAR_BLUE "0x0000868B"
# define CHAR_RED "0x00FF0000"
# define CHAR_GREEN "0x0000FF00"
# define CHAR_YELLOW "0x00FFD700"

typedef struct		s_drwln
{
	int		x;
	int		y;
	int		x_orig;
	int		y_orig;
	int		z;
	int		w;
	int		v;
	int		repeat;
	int		gap;
	float	coeff;
	float	coeff_alti;
}					t_drwln;

typedef struct		s_ptcalc
{
	int		x1;
	int		y1;
	int		x2;
	int		y2;
	int		colour;
	int		x;
	int		y;
	int		dx;
	int		dy;
	int		xinc;
	int		yinc;
}					t_ptcalc;

typedef struct		s_fdf
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*img_addr;
}					t_fdf;

typedef struct		s_image
{
	int		img_h;
	int		img_w;
	int		x_orig;
	int		y_orig;
	int		gap;
	float	coeff;
	float	coeff_view;
	float	coef_h;
	char	*colour;
	char	*img_addr;
	t_fdf	fdf;
}					t_image;

typedef struct		s_map
{
	int		height;
	int		width;
	int		highest;
	int		lowest;
	float	k;
	t_fdf	fdf;
}					t_map;

typedef struct		s_data
{
	char			*line;
	char			**data_line;
	t_map			*map;
	t_image			*image;
	struct s_data	*next;
}					t_data;

void				ft_prog(int fd);
void				ft_exit(char *str);

t_data				*ft_getmap(int fd);
t_data				*ft_addnewdatalst();

t_map				*ft_parsemap(t_data *data);
int					ft_checkdata(char **data);

t_image				*ft_get_img_param(t_map *map, float k);
void				ft_graph_part(t_map *map, t_data *data);
void				ft_createwindow(t_data *data, t_image *image);
void				ft_createimage(t_data *data, t_image *image);

void				ft_design_image(t_data *data, t_image *image);
t_drwln				ft_init_drwln(t_image *image);
t_drwln				ft_getalti(t_data *tmp, t_data *after, t_drwln dl);
void				ft_getline(t_data *tmp, t_data *after, t_ptcalc pc, \
						t_drwln dl);
void				ft_getline_lastline(t_data *after, t_ptcalc pc, \
						t_drwln dl);

int					ft_getcolour(char *point, char *img_colour);
void				ft_drawline_img(t_image *image, t_ptcalc pc);
void				ft_choose_side_x(t_ptcalc pc, t_image *image);
void				ft_choose_side_y(t_ptcalc pc, t_image *image);
void				ft_pixel_put_img(t_image *img, int x, int y, int colour);

int					ft_key(int keycode, t_data *data);
void				ft_key_colour(int keycode, t_data *data);
void				ft_key_vertihori(int keycode, t_data *data);
void				ft_key_diag(int keycode, t_data *data);
void				ft_key_init(t_data *data);

void				ft_key_upview(t_data *data);
void				ft_key_downview(t_data *data);
void				ft_key_zoom(int keycode, t_data *data);

void				ft_putframe(t_image *image);
void				ft_putguide(t_image *im);
void				ft_putguide_moves(t_image *im);
void				ft_putguide_colours(t_image *im);

#endif
