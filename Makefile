##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## Makefile
##

SRC	=	src/main.c \
		src/duck.c \
		src/duck_move.c \
		src/event.c \
		src/len_nb.c \
		src/window.c \
		src/display.c

OBJ	=	$(SRC:.c=.o)

NAME	=	my_hunter

CSFML	=	-lcsfml-graphics -lcsfml-system \
			-lcsfml-audio

all:	$(NAME)

$(NAME):	$(OBJ)
	gcc -o $(NAME) $(OBJ) $(CSFML) -lm

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean all
