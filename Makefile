# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ssumodhe <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/03/30 20:36:48 by ssumodhe          #+#    #+#              #
#    Updated: 2017/04/15 23:00:56 by ssumodhe         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FLAGS = -Wall -Werror -Wextra
FLAGSMLX = -lmlx -framework OpenGL -framework Appkit
EXEC = fdf
LIBFT = libft/libft.a
FDF = fdf.a
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

OBJS = $(SRCS:.c=.o)


all : $(EXEC)

$(EXEC) : $(OBJS) $(LIBFT)
	@ar rc $(FDF) $(OBJS)
	@clang $(FLAGS) $(FLAGSMLX) -o $@ $(LIBFT) $(FDF)
	@echo "Fdf: \033[1;32mDONE\033[0m"

$(LIBFT) :
	@make -C libft

%.o: %.c
	@clang $(FLAGS) -o $@ -c $<

clean :
	@make -C libft clean
	@rm -rf *.o
	@echo "Fdf: clean: \033[1;32mDONE\033[0m"

fclean : clean
	@make -C libft fclean
	@rm -rf $(FDF)
	@echo "Fdf: fclean: \033[1;32mDONE\033[0m"

re : fclean all
