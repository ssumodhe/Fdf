void	ft_drawcercle(void *mlx, void *win,int x1, int y1, int colour)
{
	int x;
	int y;
	int d;

	x = x1;
	y = y1;
	d = 1 - y1;
	mlx_pixel_put(mlx, win, x, y, colour);
	while (y > x)
	{
		if (d < 0)
			d += 2 * x + 3;
		else
		{
			d += 2 * (x - y) + 5;
			y--;
		}
		x++;
		mlx_pixel_put(mlx, win, x, y, colour);
	}

}
