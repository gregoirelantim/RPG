##
## EPITECH PROJECT, 2023
## RPG
## File description:
## my_pokemon
##

SRC	=	lib/pokemon.c	\

MAIN    =       lib/main.c

OBJ     =       $(SRC:.c=.o)

MIN     =       $(MAIN.:.c=.o)

NAME    =       my_pokemon

FLAGS	=	-Wall -Wextra -lncurses -l csfml-graphics -lcsfml-system -lcsfml-window

INCLUDE =       -I./include

all:    $(NAME)

$(NAME):        $(OBJ) $(MIN)
	gcc $(MAIN) $(SRC) -o $(NAME) $(FLAGS)

clean:
	rm -f $(OBJ)
	rm -f *~
	rm -f *.gc*

fclean: clean
	rm -f $(NAME)

re:	fclean all
