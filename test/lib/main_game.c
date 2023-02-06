/*
** EPITECH PROJECT, 2023
** test
** File description:
** main_game
*/

#include "../include/my.h"

int display_game(glo *all)
{
    int a;
    while (sfRenderWindow_isOpen(WINDOW)) {
        sfRenderWindow_clear(WINDOW, sfBlack);
        while (sfRenderWindow_pollEvent(WINDOW, &EVENT))
            EVENT.type == sfEvtClosed ? sfRenderWindow_close(WINDOW) : 0;
        sfRenderWindow_drawSprite(WINDOW, SPRITE[0].sprite, NULL);
        if (EVENT.type == sfEvtKeyPressed) {
            a = player_move(all);
            usleep(20000);
            animation_dresseur(all, a);
        }
        else
            stop_player_animation(all);
        sfRenderWindow_display(WINDOW);
    }
    return 0;
}

int main_game(glo *all)
{
    init_perso_all(all);
    display_game(all);
    return 0;
}
