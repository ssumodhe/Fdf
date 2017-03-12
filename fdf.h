/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssumodhe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/09 15:02:38 by ssumodhe          #+#    #+#             */
/*   Updated: 2017/03/09 19:22:27 by ssumodhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft/libft.h"
# include <fcntl.h>

typedef struct		s_data
{
	char 			*line;
	char			**data_line;
	struct s_data	*next;
}					t_data;

void				ft_prog(int fd);
void				ft_exit(char *str);

t_data				*ft_getmap(int fd);
t_data				*ft_addnewdatalst();

#endif
