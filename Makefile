NAME = libftprintf.a
SRC = ft_printf.c csdu.c xp.c
FLAGS = -Wall -Wextra -Werror
RM = /bin/rm -f
OBJ = $(SRC:.c=.o)
$(NAME): $(OBJ)
	gcc -c $(FLAGS) $(SRC)
	ar rcs $(NAME) $(OBJ)

all: $(NAME)
clean:
	$(RM) $(OBJ)
fclean: clean 
	$(RM) $(NAME)
re: fclean all
.PHONY: all clean fclean re