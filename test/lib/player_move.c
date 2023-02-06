/*
** EPITECH PROJECT, 2023
** test
** File description:
** player_move
*/

#include "../include/my.h"

int player_move_right_left(glo *all, int nb, int sprite)
{
    if (map_limit(all, nb, 1) == 1)
        return 1;
    SPRITE[sprite].pos.x += nb;
    return 0;
}

int player_move_up_down(glo *all, int nb, int sprite)
{
    if (map_limit(all, nb, 2) == 1)
	return 1;
    SPRITE[sprite].pos.y += nb;
    return 0;
}

int player_move(glo *all)
{
    int a = 0;

    if (EVENT.key.code == 74) {
        player_move_up_down(all, 5, 0);
        a = 1;
    }
    if (EVENT.key.code == 73) {
        player_move_up_down(all, -5, 0);
        a = 2;
    }
    if (EVENT.key.code == 72) {
        player_move_right_left(all, 7, 0);
        a = 3;
    }
    if (EVENT.key.code == 71) {
        player_move_right_left(all, -7, 0);
        a = 4;
    }
    sfSprite_setPosition(SPRITE[0].sprite, SPRITE[0].pos);
    sfSprite_setTextureRect(SPRITE[0].sprite, SPRITE[0].rectangle);
    return a;
}
