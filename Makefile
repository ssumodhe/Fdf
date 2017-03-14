
FLAGS = -Wall -Werror -Wextra -lmlx -framework OpenGL -framework Appkit

NAME = fdf

LIBFT = libft/libft.a

LIBMLX = minilibx/libmlx.a

SRCS = 

OBJS = $(SRC:.c=.o)

all : $(NAME)

$(NAME) : $(LIBFT) $(LIBMLX)
	@clang $(FLAGS) $(SRCS) $(LIBFT) $(LIBMLX) -o $(NAME)

$(LIBFT) :
	@make -C libft re

$(LIBMLX) :
	@make -C minilibx re

clean :

