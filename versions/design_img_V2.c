void		ft_design_image(t_map *map, t_data *data)
{
	t_data *tmp;
//	t_data *after;
	int	x;
	int	x_orig;
	int	y;
	int	y_orig;
	int z;
	int	w;
	int repeat;
	int gap;
	float coeff;
	float coeff_alti;

	x_orig = ((map->width * GAP) / 8);
	y_orig = ((map->height * GAP) / 2);
	gap = 50; // Taille de la diagonale d'une case. (ZOOM +/-)
	coeff = 0.3; // [0 ; 0.5] Oriente la vue du plan. (DESSUS/DESSOUS)
	coeff_alti = coeff * gap;
	y = 0;
	tmp = data;
	while (tmp->next != NULL)
	{
		x = 0;
		while (tmp->data_line && tmp->data_line[x])
		{
			w = 0;
			z = ft_atoi(tmp->data_line[x]);
			if (tmp->data_line[x + 1])
				w = ft_atoi(tmp->data_line[x + 1]);
			repeat = x * (gap/2);
			//a - > b
			ft_drawline_img(map, x_orig + (repeat), y_orig - (x * gap * coeff) - (z * coeff_alti),\
				   	x_orig + (repeat) + (gap/2), y_orig  - (x * gap * coeff)- (gap * coeff), 0x00FFFFFF);
			//b - > c
			ft_drawline_img(map, x_orig + (repeat)+ (gap/2), y_orig - (x * gap * coeff) - (gap * coeff),\
				   	x_orig + (repeat) + gap, y_orig - (x * gap * coeff), 0x00FFFFFF);
			//c - > d
			ft_drawline_img(map, x_orig + (repeat)+ gap, y_orig - (x * gap * coeff),\
				   	x_orig + (repeat) + (gap/2), y_orig - (x * gap * coeff) + (gap * coeff), 0x00FFFFFF);
			//d - > a
			ft_drawline_img(map, x_orig + (repeat)+ (gap/2), y_orig - (x * gap * coeff) + (gap * coeff),\
				   	x_orig + (repeat), y_orig - (x * gap * coeff) - (z * coeff_alti), 0x00FFFFFF);
			x++;
		}
		y++;
		tmp = tmp->next;
		//Point de depart + repetition
		x_orig = ((map->width * GAP) / 8) + (y * (gap/2));
		y_orig = ((map->height * GAP) / 2) + (y * gap * coeff);
	}
}
