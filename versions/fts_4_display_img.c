void	ft_pixel_put_img(t_map *map, int x, int y)
{
	int		i;

	//gerer les couleurs.

	i = (4 * (x + (y * (map->width * GAP))));
	map->fdf.img_addr[i + 0] = 0xFF;
	map->fdf.img_addr[i + 1] = 0xFF;
	map->fdf.img_addr[i + 2] = 0xFF;
	map->fdf.img_addr[i + 3] = 0x00;

}

void	ft_choose_side(int	dq, int dp, int x, int y, t_map *map)
{
	int		i;
	int		qinc;
	int		pinc;
	int		cumul;

	qinc = (dq > 0) ? 1 : -1;
	pinc = (dp > 0) ? 1 : -1;
	cumul = (dq / 2);
	i = 1;
	while (i <= dq)
	{
		x = x + qinc;
		cumul = cumul + dp;
		if (cumul >= dq)
		{
			cumul = cumul - dq;
			y = y + pinc;
		}
		ft_pixel_put_img(map, x, y);
		i++;
	}
}

void	ft_drawline_img(t_map *map,int x1, int y1, int x2, int y2, int colour)
{
	int		i;
	int		x;
	int		y;
	int		dx;
	int 	dy;
	int		xinc;
	int		yinc;
	int		cumul;

	(void)colour;
	x = x1;
	y = y1;
	dx = x2 - x1;
	dy = y2 - y1;
	xinc = (dx > 0) ? 1 : -1;
	yinc = (dy > 0) ? 1 : -1;
	dx = (dx < 0) ? -dx : dx;
	dy = (dy < 0) ? -dy : dy;

	ft_pixel_put_img(map, x, y);
	if (dx > dy)
//		ft_choose_side(dx, dy, x, y, map);
	{
		cumul = (dx / 2);
		i = 1;
		while (i <= dx)
		{
			x = x + xinc;
			cumul = cumul + dy;
			if (cumul >= dx)
			{
				cumul = cumul - dx;
				y = y + yinc;
			}
			ft_pixel_put_img(map, x, y);
			i++;
		}
	}
	else 
//		ft_choose_side(dy, dx, y, x, map);
	{
		cumul = (dy / 2);
		i = 1;
		while (i <= dy)
		{
			y = y + yinc;
			cumul = cumul + dx;
			if (cumul >= dy)
			{
				cumul = cumul - dy;
				x = x + xinc;
			}
			ft_pixel_put_img(map, x, y);
			i++;
		}
	}
}

/*
int			ft_getcolour(char *point)
{
	int		i;
	char	*tmp;
	char	*char_colour;
	int		*int_colour;

	i = 0;
	// Check si cet int fait blanc
	int_colour = 255 + 255 + 255; 
	while (tmp)
	{
		if (tmp[0] == ',' && tmp[2] == 'x')
		{
			char_colour = tmp;
			int_colour = ft_atoi_base(char_colour);
			return(int_colour);
		}
		tmp++;
	}
	return(int_colour);
}*/

void		ft_design_image(t_map *map, t_data *data)
{
	t_data *tmp;
	t_data *after;
	int	x;
	int	x_orig;
	int	y;
	int	y_orig;
	int z;
	int	w;
	int	v;
	int repeat;
	int gap;
	float coeff;
	float coeff_alti;
//	int		colour;

				ft_putendl(HIGHLIGHT"entree design image"RESET);
 	x_orig = ((map->width * GAP)/map->k / 8);
	y_orig = (((map->height * GAP) + (map->highest * GAP))/map->k / 2);
	gap = GAP; // Taille de la diagonale d'une case. (ZOOM +/-)
	coeff = 0.3; // [0 ; 0.5] Oriente la vue du plan. (DESSUS/DESSOUS)
	coeff_alti = gap * 3 / 4;
	y = 0;
	tmp = data;
	after = data;
	after = after->next;
				ft_putendl(HIGHLIGHT"tmp + after initialises"RESET);
	while (tmp->next != NULL && after->next != NULL)
	{
		x = 0;
		while (tmp->data_line && tmp->data_line[x])
		{
//			colour = ft_getcolour(tmp->data_line[x]);
				ft_putnbr(x);
				ft_putchar(' ');
				ft_putnbr(y);
				ft_putendl("");
			w = 0;
			v = 0;
			z = ft_atoi(tmp->data_line[x]);
			if (tmp->data_line[x + 1])
				w = ft_atoi(tmp->data_line[x + 1]);
			if (after->data_line[x])
				v = ft_atoi(after->data_line[x]);
			repeat = x * (gap/2);
			//a - > b
			ft_drawline_img(map, x_orig + (repeat), y_orig - (x * gap * coeff) - (z * coeff_alti), x_orig + (repeat) + (gap/2), y_orig  - (x * gap * coeff) - (w * coeff_alti) - (gap * coeff), 0x00FFFFFF);
			//d - > a
			ft_drawline_img(map, x_orig + (repeat)+ (gap/2), y_orig - (x * gap * coeff) - (v * coeff_alti) + (gap * coeff), x_orig + (repeat), y_orig - (x * gap * coeff) - (z * coeff_alti), 0x00FFFFFF);
				ft_putendl(RED"ici"RESET);
			x++;
		}
		y++;
		tmp = tmp->next;
		after = after->next;
		//Point de depart + repetition
//		x_orig = (((map->width * GAP)) / 8) + (y * (gap/2));
//		y_orig = (((map->height * GAP) + (map->highest * GAP)) / 2) + (y * gap * coeff);
		x_orig = (((map->width * GAP)/map->k) / 8) + (y * (gap/2));
		y_orig = (((map->height * GAP) + (map->highest * GAP))/map->k / 2) + (y * gap * coeff);
	}
}
