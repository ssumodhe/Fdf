/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_img_fdf.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssumodhe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/27 18:04:02 by ssumodhe          #+#    #+#             */
/*   Updated: 2017/04/01 18:53:17 by ssumodhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		ft_getline_lastline(t_data *after, t_ptcalc pc, t_drwln dl)
{
	dl.w = ft_atoi(after->data_line[dl.x + 1]);
	dl.z = dl.v;
	pc.x1 = dl.x_orig + (dl.repeat) + (dl.gap / 2);
	pc.y1 = dl.y_orig - (dl.x * dl.gap * dl.coeff) - (dl.z * dl.coeff_alti)\
			+ (dl.gap * dl.coeff);
	pc.x2 = dl.x_orig + (dl.repeat) + (dl.gap / 2) + (dl.gap / 2);
	pc.y2 = dl.y_orig - (dl.x * dl.gap * dl.coeff) - (dl.w * dl.coeff_alti);
	ft_drawline_img(after->image, pc);
}

void		ft_getline(t_data *tmp, t_data *after, t_ptcalc pc, t_drwln dl)
{
	if (tmp->data_line[dl.x + 1])
	{
		pc.x1 = dl.x_orig + (dl.repeat);
		pc.y1 = dl.y_orig - (dl.x * dl.gap * dl.coeff) - (dl.z * dl.coeff_alti);
		pc.x2 = dl.x_orig + (dl.repeat) + (dl.gap / 2);
		pc.y2 = dl.y_orig - (dl.x * dl.gap * dl.coeff) - \
				(dl.w * dl.coeff_alti) - (dl.gap * dl.coeff);
		ft_drawline_img(tmp->image, pc);
	}
	pc.x1 = dl.x_orig + (dl.repeat);
	pc.y1 = dl.y_orig - (dl.x * dl.gap * dl.coeff) - (dl.z * dl.coeff_alti);
	pc.x2 = dl.x_orig + (dl.repeat) + (dl.gap / 2);
	pc.y2 = dl.y_orig - (dl.x * dl.gap * dl.coeff) - (dl.v * dl.coeff_alti) + \
			(dl.gap * dl.coeff);
	ft_drawline_img(tmp->image, pc);
	if (after->next->next == NULL && tmp->data_line[dl.x + 1])
	{
		after->image = tmp->image;
		ft_getline_lastline(after, pc, dl);
	}
}

t_drwln		ft_getalti(t_data *tmp, t_data *after, t_drwln dl)
{
	dl.w = 0;
	dl.v = 0;
	dl.z = ft_atoi(tmp->data_line[dl.x]);
	if (tmp->data_line[dl.x + 1])
		dl.w = ft_atoi(tmp->data_line[dl.x + 1]);
	if (after->data_line[dl.x])
		dl.v = ft_atoi(after->data_line[dl.x]);
	dl.repeat = dl.x * (dl.gap / 2);
	return (dl);
}

t_drwln		ft_init_drwln(t_image *image)
{
	t_drwln		dl;

	dl.x_orig = image->x_orig;
	dl.y_orig = image->y_orig;
	dl.gap = image->gap;
	dl.coeff = image->coeff;
	dl.coeff_alti = image->coef_h;
	dl.y = 0;
	return (dl);
}

void		ft_design_image(t_data *data, t_image *image)
{
	t_data		*tmp;
	t_data		*after;
	t_drwln		dl;
	t_ptcalc	pc;

	dl = ft_init_drwln(image);
	tmp = data;
	after = data;
	after = after->next;
	while (!(dl.x = 0) && tmp->next != NULL && after->next != NULL)
	{
		while (tmp->data_line && tmp->data_line[dl.x])
		{
			pc.colour = ft_getcolour(tmp->data_line[dl.x], image->colour);
			dl = ft_getalti(tmp, after, dl);
			ft_getline(tmp, after, pc, dl);
			dl.x++;
		}
		dl.y++;
		tmp->next->image = tmp->image;
		tmp = tmp->next;
		after = after->next;
		dl.x_orig = image->x_orig + (dl.y * (dl.gap / 2));
		dl.y_orig = image->y_orig + (dl.y * dl.gap * dl.coeff);
	}
}
