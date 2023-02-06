##
## EPITECH PROJECT, 2023
## RPG
## File description:
## test
##

SRC	=	lib/init_menu.c	\
		lib/init_perso.c	\
		lib/test.c	\
		lib/main_game.c	\
		lib/menu_game.c	\
		lib/player_animation.c	\
		lib/player_move.c	\
		lib/player.c	\

MAIN    =       lib/main.c

OBJ     =       $(SRC:.c=.o)

MIN     =       $(MAIN.:.c=.o)

NAME    =       test

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
