/*
** EPITECH PROJECT, 2023
** test
** File description:
** map_move
*/

#include "../include/my.h"

int map_move_right_left(glo *all, int nb)
{
    if ((all->pos_x + nb < 0) || (all->pos_x + nb > 500))
        return 0;
    all->pos_x += nb;
    return 0;
}

int map_move_up_down(glo *all, int nb)
{
    if ((all->pos_y + nb < 0) || (all->pos_y + nb > 1000))
	return 0;
    all->pos_y += nb;
    return 0;
}

int map_move(glo *all)
{
    if (EVENT.key.code == 74)
        map_move_up_down(all, 1);
    if (EVENT.key.code == 73)
        map_move_up_down(all, -1);
    if (EVENT.key.code == 72)
        map_move_right_left(all, 1);
    if (EVENT.key.code == 71)
        map_move_right_left(all, -1);

    return 0;
}
