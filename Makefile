
FLAGS = -Wall -Werror -Wextra -lmlx -framework OpenGL -framework Appkit

NAME = fdf

LIBFT = libft/libft.a

LIBMLX = minilibx/libmlx.a

SRCS = main_fdf.c \
	   prog_fdf.c \
	   parsing_fdf.c \
	   getmap_fdf.c \
	   graph_fdf.c

OBJS = $(SRC:.c=.o)

all : $(NAME)
	@clang $(FLAGS) -o $(NAME) $(SRCS) $(LIBFT) $(LIBMLX)
	@echo "Fdf : \033[1;32mDONE\033[0m"

$(NAME) : $(LIBFT) $(LIBMLX)

$(LIBFT) :
	@make -C libft re

$(LIBMLX) :
	@make -C minilibx re

clean :
	@make -C libft clean
	@make -C minilibx clean

fclean : clean
	@make -C libft fclean
	@rm -rf $(NAME)

re : fclean all


