/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_img_fdf.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssumodhe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/27 18:04:02 by ssumodhe          #+#    #+#             */
/*   Updated: 2017/03/30 19:38:43 by ssumodhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			ft_getcolour(char *point, char *img_colour)
{
	int		i;
	char	*tmp;
	char	*char_colour;
	int		int_colour;

	i = 0;
	tmp = point;
	while (tmp[0] != '\0')
	{
		if (tmp[0] == ',' && tmp[2] == 'x')
		{
			tmp = tmp + 3;
			char_colour = tmp;
			int_colour = ft_atoi_base(char_colour, 16);
			return(int_colour);
		}
		tmp++;
	}
	return(ft_atoi_base(img_colour, 16));
}

void		ft_getline(t_data *tmp, /*t_data *after,*/ t_image *image, t_ptcalc pc, t_drwln dl)
{
	if (tmp->data_line[dl.x+1])
	{		 //a - > b
		pc.x1 = dl.x_orig + (dl.repeat);
		pc.y1 = dl.y_orig - (dl.x * dl.gap * dl.coeff) - (dl.z * dl.coeff_alti);
		pc.x2 = dl.x_orig + (dl.repeat) + (dl.gap/2);
		pc.y2 = dl.y_orig - (dl.x * dl.gap * dl.coeff) - (dl.w * dl.coeff_alti) - (dl.gap * dl.coeff);
		ft_drawline_img(image, pc);
	}
	//d - > a
	pc.x1 = dl.x_orig + (dl.repeat);
	pc.y1 = dl.y_orig - (dl.x * dl.gap * dl.coeff) - (dl.z * dl.coeff_alti);
	pc.x2 = dl.x_orig + (dl.repeat)+ (dl.gap/2);
	pc.y2 = dl.y_orig - (dl.x * dl.gap * dl.coeff) - (dl.v * dl.coeff_alti) + (dl.gap * dl.coeff);
	ft_drawline_img(image, pc);
/*	if (after->next->next == NULL && tmp->data_line[dl.x+1])
	{		//c - > d
		//		w = w - w - z;
		dl.w = 0;
		dl.z = dl.v;
		pc.x1 = dl.x_orig + (dl.repeat) + (dl.gap/2);
		pc.y1 = dl.y_orig - (dl.x * dl.gap * dl.coeff) - (dl.z * dl.coeff_alti) +(dl.gap * dl.coeff);
		pc.x2 = dl.x_orig + (dl.repeat) + (dl.gap/2) + (dl.gap/2);
		pc.y2 = dl.y_orig - (dl.x * dl.gap * dl.coeff) - (dl.w * dl.coeff_alti);
		ft_drawline_img(image, pc);
	}*/
}

t_drwln		ft_getalti(t_data *tmp, t_data *after, t_drwln dl)
{
	//tmp + free(dl);
	dl.w = 0;
	dl.v = 0;
	dl.z = ft_atoi(tmp->data_line[dl.x]);
	if (tmp->data_line[dl.x + 1])
		dl.w = ft_atoi(tmp->data_line[dl.x + 1]);
	if (after->data_line[dl.x])
		dl.v = ft_atoi(after->data_line[dl.x]);
	dl.repeat = dl.x * (dl.gap/2); // Pour se deplacer de case en case.
	return (dl);
}

t_drwln		ft_init_drwln(t_image *image)
{
	t_drwln		dl;

	dl.x_orig = image->x_orig;
	dl.y_orig = image->y_orig;
	dl.gap = image->gap; // Taille de la diagonale d'une case. (ZOOM +/-)
	dl.coeff = image->coeff; // [0 ; 0.5] Oriente la vue du plan. (DESSUS/DESSOUS)
	dl.coeff_alti = image->coef_h;
	dl.y = 0;
	return (dl);
}

void		ft_design_image(t_data *data, t_image *image)
{
	t_data 		*tmp;
	t_data 		*after;
	t_drwln		dl;
	t_ptcalc	pc;

	dl = ft_init_drwln(image);
	tmp = data;
	after = data;
	after = after->next;
	while (tmp->next != NULL && after->next != NULL)
	{
		dl.x = 0;
		while (tmp->data_line && tmp->data_line[dl.x])
		{
			pc.colour = ft_getcolour(tmp->data_line[dl.x], image->colour);
			dl = ft_getalti(tmp, after, dl);
			ft_getline(tmp,/* after,*/ image, pc, dl);
			dl.x++;
		}
		dl.y++;
		tmp = tmp->next;
		after = after->next;
		dl.x_orig = image->x_orig + (dl.y * (dl.gap/2)); 
		dl.y_orig = image->y_orig + (dl.y * dl.gap * dl.coeff);
	}
}

/*
   void		ft_design_image(t_data *data, t_image *image)
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
   int		colour;
   ft_putendl(HIGHLIGHT"\nPHASE 4 --> DISPLAY IMAGE\n"RESET);

   x_orig = image->x_orig;
   y_orig = image->y_orig;
   gap = image->gap; // Taille de la diagonale d'une case. (ZOOM +/-)
   coeff = image->coeff; // [0 ; 0.5] Oriente la vue du plan. (DESSUS/DESSOUS)
   coeff_alti = image->coef_h;
   y = 0;
   tmp = data;
   after = data;
   after = after->next;
   while (tmp->next != NULL && after->next != NULL)
   {
   x = 0;
   while (tmp->data_line && tmp->data_line[x])
   {
   colour = ft_getcolour(tmp->data_line[x], image->colour);
   w = 0;
   v = 0;
   z = ft_atoi(tmp->data_line[x]);
   if (tmp->data_line[x + 1])
   w = ft_atoi(tmp->data_line[x + 1]);
   if (after->data_line[x])
   v = ft_atoi(after->data_line[x]);

   repeat = x * (gap/2); // Pour se deplacer de case en case.

   if (tmp->data_line[x+1])
   {		 //a - > b
   ft_drawline_img(image, x_orig + (repeat), y_orig - (x * gap * coeff) - (z * coeff_alti), x_orig + (repeat) + (gap/2), y_orig - (x * gap * coeff) - (w * coeff_alti) - (gap * coeff), colour);
   }
//d - > a
ft_drawline_img(image, x_orig + (repeat), y_orig - (x * gap * coeff) - (z * coeff_alti), x_orig + (repeat)+ (gap/2), y_orig - (x * gap * coeff) - (v * coeff_alti) + (gap * coeff), colour);
if (after->next->next == NULL && tmp->data_line[x+1])
{		//c - > d
//		w = w - w - z;
w = 0;
z = v;
ft_drawline_img(image, x_orig + (repeat) + (gap/2), y_orig - (x * gap * coeff) - (z * coeff_alti) +(gap * coeff), x_orig + (repeat) + (gap/2) + (gap/2), y_orig - (x * gap * coeff) - (w * coeff_alti), 0x00FF0000);

}

x++;
}
y++;
tmp = tmp->next;
after = after->next;
//Point de depart + repetition - Pour se deplacer de ligne en ligne avec le decalage.
x_orig = image->x_orig + (y * (gap/2)); 
y_orig = image->y_orig + (y * gap * coeff);
}
}*/
