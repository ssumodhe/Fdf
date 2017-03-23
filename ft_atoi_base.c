/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssumodhe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/13 13:34:49 by ssumodhe          #+#    #+#             */
/*   Updated: 2017/03/23 18:10:43 by ssumodhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int		ft_atoi_base(const char *str, int str_base)
{
	int		i;
	int		j;
	int		k;

	i = 0;
	j = 0;
	k = 1;

	if (str_base > 16 || str_base < 2)
		return (0);


	i = 0;
	while (str[i] != '\0' && str[i] == ' ') //isspace ' ' '\n' '\t' '\a' '\b' '\v' '\f' '\r'
		i++;
	if (str[i] == '+')
		i++;
	else if (str[i] == '-')
	{
		k = -1;
		i++;
	}

	while (str[i] != '\0')
	{
		if (/*str_base <= 10 && */str[i] >= '0' && str[i] <= '9')
		{
			j = (j * str_base) + (str[i] - '0');
		}
		else if (str_base > 10 && str[i] >= 'a' && str[i] <= 'z')
		{
			j = (j * str_base) + (str[i] - 'a') + 10;
		}
		else if (str_base > 10 && str[i] >= 'A' && str[i] <= 'Z')
		{
			j = (j * str_base) + (str[i] - 'A') + 10;
		}

		i++;
	}

	return (j * k);
}

/*
int		main(int argc, char **argv)
{
	if (argc != 3)
		return (0);

	printf("%d\n", ft_atoi_base(argv[1], atoi(argv[2])));
	return (0);
}*/
