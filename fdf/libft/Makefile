NAME = libft.a
SRC = $(shell find . -name '*.c' ! -name 'ft_lst*.c')
OBJ = $(SRC:.c=.o)
BONUS = $(shell find . -name 'ft_lst*.c')
BONUS_OBJ = $(BONUS:.c=.o)
CC = cc
FLAGS = -Wall -Werror -Wextra
AR = ar r
RM = rm -f

all : $(NAME)

%.o : %.c 
	$(CC) $(FLAGS) -c $< -o $@

$(NAME) : $(OBJ)
	$(AR) $(NAME) $(OBJ)

fclean		: clean
	$(RM)  $(NAME)

clean :
	$(RM) $(OBJ)

bonus: $(OBJ) $(BONUS_OBJ)
	$(AR) $(NAME) $(OBJ) $(BONUS_OBJ)
re: fclean all

.PHONY : all, clean, fclean, bonus, re
