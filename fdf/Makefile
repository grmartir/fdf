FRAEMWORKS=-lmlx -framework OpenGL -framework AppKit
FLAGS=-Werror -Wextra -Wall
NAME=fdf
SRC= $(wildcard src/*.c)
OBJ=$(SRC:.c=.o)
LIBFT=libft/libft.a

all: comp $(NAME)

comp : 
	@make -C libft

$(NAME) : $(OBJ)
	cc  $(FLAGS) $(LIBFT) $(FRAEMWORKS) $(OBJ) -o $(NAME)

%.o : %.c
	cc $(FLAGS) -Imlx -c $< -o $@

clean:
	rm -rf $(OBJ)
	@make -C libft clean

fclean: clean
	rm -rf $(NAME)
	@make -C libft fclean

re: fclean all

.PHONY: all, comp, clean, fclean
