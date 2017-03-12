#include <mlx.h>
#include <unistd.h>
#include <stdio.h>

int		ft_my_key(int keycode, void *param)
{
	(void)param;
	printf("key event %d\n", keycode);
	return (0);
}

int		main(void)
{
	void	*mlx;
	void	*win;
	int		colour;
	int		x;
	int		y;

	//Toujorus appeler mlx_init au debut de l'execution
	//Il renvoie un pointeur qui sert d'identifiant pour la connection avec le serveur graphique.
	mlx = mlx_init();


	//Pour ouvrir un nouvelle fenetre: mlx_new_window.
	//Il renvoie egalement un pointeur qui sert d'identifiant. Ainsi il est possible d'ouvrir plusieurs fenetre simultanement.
	win = mlx_new_window(mlx, 400, 400, "mlx 42");
	//Pour que la fenetre reste, il faut faire appelle a mlx_loop, qui prend l'identifiant de la connextion en argument.
	

	//Pour afficher qqchose sur la fenetre ouverte, on utilise la fonction mlx_pixel_put : on lui donne la connexion, la fenetre, les coordonees du pixel et une couleur (en int | code en RGB sur l'int)
	x = 50;
	y = 100;
	colour = 0x00AA0000;
	while (x < 150)
	{
		mlx_pixel_put(mlx, win, x, y, colour);
//		colour++;
		x++;
	}
	printf("colour = %d\n", colour);
	x = 250;
	y = 100;
	while (x < 350)
	{
		mlx_pixel_put(mlx, win, x, y, colour);
//		colour++;
		x++;
	}
	x = 100;
	y = 300;
	while (x < 300)
	{
		mlx_pixel_put(mlx, win, x, y, colour);
//		colour++;
		x++;
	}

	//Pour ajouter la gestion des evenements, IL FAUT ABSOLUMENT ETRE DANS mlx_loop, dans le cas contraire, il n'y aura pas de gestion d'evenements.
	mlx_key_hook(win, ft_my_key, 0);


	//Cependant, mlx_loop ne rend pas la main, c'est a dire qu'il faut prevoir un moyen d'exit le programme.
	mlx_loop(mlx);
	return (0);
}
