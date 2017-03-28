int			ft_key(int keycode, t_data *data)
{
	int		stock;

//	ft_putstr("Keycode = ");
//	ft_putnbr(keycode);
//	ft_putendl("");
	mlx_destroy_image(data->image->fdf.mlx, data->image->fdf.img);
	if (keycode == 5)
	{
		data->image->colour = CHAR_GREEN;
		ft_createimage(data, data->image);
	}
	if (keycode == 11)
	{
		data->image->colour = CHAR_BLUE;
		ft_createimage(data, data->image);
	}
	if (keycode == 13)
	{
		data->image->colour = CHAR_WHITE;
		ft_createimage(data, data->image);
	}
	if (keycode == 15)
	{
		data->image->colour = CHAR_RED;
		ft_createimage(data, data->image);
	}
	if (keycode == 16)
	{
		data->image->colour = CHAR_YELLOW;
		ft_createimage(data, data->image);
	}
	if (keycode == 53)
		exit(0);
	if (keycode == 83)
	{
		stock = data->image->y_orig;
		data->image->y_orig = stock + data->image->gap;
		stock = data->image->x_orig;
		data->image->x_orig = stock - data->image->gap;
		ft_createimage(data, data->image);
	}
	if (keycode == 84)
	{
		stock = data->image->y_orig;
		data->image->y_orig = stock + data->image->gap;
		ft_createimage(data, data->image);
	}
	if (keycode == 85)
	{
		stock = data->image->y_orig;
		data->image->y_orig = stock + data->image->gap;
		stock = data->image->x_orig;
		data->image->x_orig = stock + data->image->gap;
		ft_createimage(data, data->image);
	}
	if (keycode == 86)
	{
		stock = data->image->x_orig;
		data->image->x_orig = stock - data->image->gap;
		ft_createimage(data, data->image);
	}
/*	if (keycode == 87)
	{
		data->image->x_orig = data->image->gap;
		data->image->y_orig = (data->image->img_h - ((data->map->height+5) * data->image->gap * 0.3)) - (fabs((double)data->map->lowest) * data->image->gap * 3/4);
		ft_createimage(data, data->image);
	}*/
	if (keycode == 88)
	{
		stock = data->image->x_orig;
		data->image->x_orig = stock + data->image->gap;
		ft_createimage(data, data->image);
	}
	if (keycode == 89)
	{
		stock = data->image->y_orig;
		data->image->y_orig = stock - data->image->gap;
		stock = data->image->x_orig;
		data->image->x_orig = stock - data->image->gap;
		ft_createimage(data, data->image);
	}
	if (keycode == 91)
	{
		stock = data->image->y_orig;
		data->image->y_orig = stock - data->image->gap;
		ft_createimage(data, data->image);
	}
	if (keycode == 92)
	{
		stock = data->image->y_orig;
		data->image->y_orig = stock - data->image->gap;
		stock = data->image->x_orig;
		data->image->x_orig = stock + data->image->gap;
		ft_createimage(data, data->image);
	}
/*	if (keycode == 126)
	{
		stock = data->image->coeff;
		data->image->coeff = stock;
		ft_createimage(data, data->image);
	}*/
	else
		ft_createimage(data, data->image);
	return (0);
}
