/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getcolour.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssumodhe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/23 17:46:58 by ssumodhe          #+#    #+#             */
/*   Updated: 2017/03/23 18:39:38 by ssumodhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

int			ft_atoi_base(const char *str, int str_base);

int			ft_getcolour(char *point)
{
	int		i;
	char	*tmp;
	char	*char_colour;
	int		int_colour;

	i = 0;
	tmp = point;
	int_colour = 0;
	while (tmp)
	{
		if (tmp[0] == ',' && tmp[2] == 'x')
		{
			if(tmp + 3)
			{
				tmp = tmp + 3;
				char_colour = tmp;
				int_colour = ft_atoi_base(char_colour, 16);
				return(int_colour);
			}
			else
				return(16777215);
		}
		tmp++;
	}
	return(int_colour);
}

int		main()
{
	char	str[] = "12,0xFFFFFF";
	int		colour;

	colour = ft_getcolour(str);
	printf("colour = %d\n", colour);
	return (0);
}
