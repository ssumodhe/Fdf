void	ft_pixel_put_img(char *image_addr, int x, int y)
{
	int		i;

	i = (4 * (x + (y * 200)));
	image_addr[i + 0] = 0xFF;
	image_addr[i + 1] = 0xFF;
	image_addr[i + 2] = 0xFF;
	image_addr[i + 3] = 0x00;

}
