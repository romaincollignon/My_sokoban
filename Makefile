##
## EPITECH PROJECT, 2017
## makefile
## File description:
## task01
##

SRC 	=	src/function/mini_printf.c \
			src/function/my_put_nbr.c \
			src/function/my_putchar.c \
			src/function/my_putstr.c \
			src/function/my_compute_power_rec.c \
			src/function/my_revstr.c \
			src/function/my_str_to_word_array.c \
			src/function.c \
			src/print_center.c \
			src/win_won.c \
			src/moove.c \
			src/function_moove.c \
			src/periph.c \
			src/init_struct.c \
			src/sokoban.c \
			src/main.c

OBJ	=	$(SRC:.c=.o)

CFLAGS = -Wall -Wextra -I ./include/

NAME	=	my_sokoban

all:	$(NAME)

$(NAME): $(OBJ)
	gcc $(OBJ) $(CFLAGS) -o $(NAME) -lncurses

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean all

debug :
	gcc $(SRC) -Wall -Wextra -I include -o $(NAME) -g $(CFLAGS)

.PHONY:	all clean fclean re
