/*
** EPITECH PROJECT, 2023
** test
** File description:
** player
*/

#include "../include/my.h"

int player_key_pressed(glo *all)
{
    int a;

    if (EVENT.type == sfEvtKeyPressed) {
        a = player_move(all);
        usleep(20000);
        animation_dresseur(all, a);
    } else
        stop_player_animation(all);
    sfRenderWindow_display(WINDOW);

    return 0;
}

int map_limit(glo *all, int nb, int i)
{
    if (i == 1) {
        if (SPRITE[0].pos.x + nb < -10 || SPRITE[0].pos.x + nb >= 1860)
            return 1;
    } else {
        if (SPRITE[0].pos.y + nb < 0 || SPRITE[0].pos.y + nb >= 1080)
            return 1;
    }
    return 0;
}
