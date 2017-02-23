#include <mlx.h>

int		main(void)
{
	void	*mlx;
	void	*win;
	//Toujorus appeler mlx_init au debut de l'execution
	//Il renvoie un pointeur qui sert d'identifiant pour la connection avec le serveur graphique.
	mlx = mlx_init();
	//Pour ouvrir un nouvelle fenetre: mlx_new_window.
	//Il renvoie egalement un pointeur qui sert d'identifiant. Ainsi il est possible d'ouvrir plusieurs fenetre simultanement.
	win = mlx_new_window(mlx, 400, 400, "mlx 42");
	//Pour que la fenetre reste, il faut faire appelle a mlx_loop, qui prend l'identifiant de la connextion en argument.
	//Cependant, il ne rend pas pas la main, c'est a dire qu'il faut prevoir un moyen d'exit le programme.
	mlx_loop(mlx);
	return (0);
}
