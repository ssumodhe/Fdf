void		ft_design_image(t_map *map, t_data *data)
{
//	t_data *tmp;
//	t_data *after;
	int	x;
//	int x_max;
	int	x_orig;
	int	y;
//	int y_max;
	int	y_orig;
	int z;
	int repeat;
	int gap;
	float coeff;
	float coeff_alti;

	(void)data;

	x_orig = ((map->width * GAP) / 8);
	y_orig = ((map->height * GAP) / 3);
	gap = 50; // Taille de la diagonale d'une case. (ZOOM +/-)
	coeff = 0.3; // [0 ; 0.5] Oriente la vue du plan. (DESSUS/DESSOUS)
	coeff_alti = coeff * gap;

	y = 0;
	while (y < 4)
	{
		x = 0;
		while (x < 5)
		{
			z = 0;
			repeat = x * (gap/2);
			ft_drawline_img(map, x_orig + (repeat), y_orig - (x * gap * coeff),\
				   	x_orig + (repeat) + (gap/2), y_orig  - (x * gap * coeff)- (gap * coeff), 0x00FFFFFF);
			ft_drawline_img(map, x_orig + (repeat)+ (gap/2), y_orig - (x * gap * coeff) - (gap * coeff),\
				   	x_orig + (repeat) + gap, y_orig - (x * gap * coeff), 0x00FFFFFF);
			ft_drawline_img(map, x_orig + (repeat)+ gap, y_orig - (x * gap * coeff),\
				   	x_orig + (repeat) + (gap/2), y_orig - (x * gap * coeff) + (gap * coeff), 0x00FFFFFF);
			ft_drawline_img(map, x_orig + (repeat)+ (gap/2), y_orig - (x * gap * coeff) + (gap * coeff),\
				   	x_orig + (repeat), y_orig - (x * gap * coeff), 0x00FFFFFF);

		x++;
		}
	y++;
	//Point de depart + repetition
	x_orig = ((map->width * GAP) / 8) + (y * (gap/2));
	y_orig = ((map->height * GAP) / 3) + (y * gap * coeff);
	}


/*	tmp = data;
	x_orig = ((map->width * GAP) / 4);
	y_orig = ((map->height * GAP) * 3 / 4);
//	x_orig = 50; // Deplace le plan sur l'axe horizontal. (GAUCHE/DROITE)
//	y_orig = 100; // Deplace le plan sur l'axe vertical. (HAUT/BAS)
	gap = 10; // Taille de la diagonale d'une case. (ZOOM +/-)
	coeff = 0.15; // [0 ; 0.5] Oriente la vue du plan. (DESSUS/DESSOUS)
	coeff_alti = coeff * gap;
	y = y_orig;
	x = x_orig;
//	y = 0;
//	while (tmp->next != NULL)
//	{
		x = 0;
		gap = 10;
//		while (tmp->data_line && tmp->data_line[x])
//		{
		//	z = ft_atoi(tmp->data_line[x]);
				z = 0;
				ft_drawline_img(map, x, y, x + (gap/2), y - (gap * coeff) - (z + gap), 0x00FFFFFF);
				ft_drawline_img(map, x + (gap/2), y - (gap * coeff) - (z + gap), x + gap, y - (z + gap), 0x0000FF00);
				ft_drawline_img(map, x + gap, y - (z + gap), x + (gap/2), y + (gap * coeff), 0x00FF0000);
				ft_drawline_img(map, x + (gap/2), y + (gap * coeff), x, y, 0x00FFFFFF);

		//	if (nb_col != 3 && nb_col != 2)
		//	{
		//		ft_drawline_img(map, x, y, x + (gap/2), y - (gap * coeff), 0x00FFFFFF);
			//	ft_drawline_img(map, x + (gap/2), y - (gap * coeff), x + gap, y, 0x00FFFFFF);
			//	ft_drawline_img(map, x + gap, y, x + (gap/2), y + (gap * coeff), 0x00FFFFFF); //important pour la derniere diagonale
		//		ft_drawline_img(map, x + (gap/2), y + (gap * coeff), x, y, 0x00FFFFFF);
		//	}
				
			x++;
			gap = gap + 10;
	//	}
		y = y + map->width;
//		y = y + (gap * coeff);
//		tmp = tmp->next;
//	}*/



/*
	x_orig = ((map->width * GAP) / 4);
	y_orig = ((map->height * GAP) / 4);
	y_max = 0;
	tmp = data;
	while (tmp->next != NULL)
	{
		x_max = 0;
		gap = 0;
		while (tmp->data_line && tmp->data_line[x_max])
		{
			ft_pixel_put_img(map, x_orig + x_max + gap, (y_orig + y_max - ft_atoi(tmp->data_line[x_max])));
			x_max++;
			gap = gap + 10;
		}
		y_max = y_max + 20;
		tmp = tmp->next;
	}
*/



}
