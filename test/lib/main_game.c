/*
** EPITECH PROJECT, 2023
** test
** File description:
** main_game
*/

#include "../include/my.h"

int display_game(glo *all)
{
    all->pos_x = 0;
    all->pos_y = 0;
    while (sfRenderWindow_isOpen(WINDOW)) {
        sfRenderWindow_clear(WINDOW, sfBlack);
        while (sfRenderWindow_pollEvent(WINDOW, &EVENT))
            EVENT.type == sfEvtClosed ? sfRenderWindow_close(WINDOW) : 0;
        map_load(all);
        //sfRenderWindow_drawSprite(WINDOW, SPRITE[0].sprite, NULL);
        map_move(all);
        //player_key_pressed(all);
        //usleep(2000);
        sfRenderWindow_display(WINDOW);
    }
    return 0;
}

int main_game(glo *all)
{
    init_perso_all(all);
    init_map_all(all);
    display_game(all);
    return 0;
}
