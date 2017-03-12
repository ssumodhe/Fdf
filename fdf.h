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
	struct s_data	*next;
}					t_data;

void				ft_getline(int fd);

#endif
