# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ssumodhe <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/03/30 20:36:48 by ssumodhe          #+#    #+#              #
#    Updated: 2017/04/01 16:13:27 by ssumodhe         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FLAGS = -Wall -Werror -Wextra -lmlx -framework OpenGL -framework Appkit

NAME = fdf

LIBFT = libft/libft.a

SRCS = main_fdf.c \
	   prog_fdf.c \
	   parsing_fdf.c \
	   getmap_fdf.c \
	   graph_fdf.c \
	   display_img_fdf.c \
	   display_img_2_fdf.c \
	   keycode_fdf.c \
	   keycode_2_fdf.c \
	   display_win_fdf.c

OBJS = $(SRC:.c=.o)


all : $(NAME)

$(NAME) : $(LIBFT)
	@clang $(FLAGS) -o $(NAME) $(SRCS) $(LIBFT)
	@echo "Fdf: \033[1;32mDONE\033[0m"

$(LIBFT) :
	@make -C libft re

%.o: %.c
	@clang $(FLAGS) -o $< -c $@

clean :
	@make -C libft clean

fclean : clean
	@make -C libft fclean
	@rm -rf $(NAME)
	@echo "Fdf: fclean: \033[1;32mDONE\033[0m"

re : fclean all
