/*
** EPITECH PROJECT, 2023
** TEST
** File description:
** test
*/

#include "../include/my.h"

int display_menu(glo *all)
{
    while (sfRenderWindow_isOpen(WINDOW)) {
        sfRenderWindow_clear(WINDOW, sfWhite);
        while (sfRenderWindow_pollEvent(WINDOW, &EVENT))
            EVENT.type == sfEvtClosed ? sfRenderWindow_close(WINDOW) : 0;
//        sfRenderWindow_drawSprite(WINDOW, IMAGES[0].sprite, NULL);
        sfRenderWindow_display(WINDOW);
    }
    return 0;
}

int test_menu(glo *all)
{
    init_menu(all);
    display_menu(all);
    return 0;
}

int test(glo *all)
{
    test_menu(all);
    return 0;
}
