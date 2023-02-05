/*
** EPITECH PROJECT, 2023
** TEST
** File description:
** test
*/

#include "../include/my.h"

int display_game(glo *all)
{
    while (sfRenderWindow_isOpen(WINDOW)) {
        sfRenderWindow_clear(WINDOW, sfBlack);
        while (sfRenderWindow_pollEvent(WINDOW, &EVENT))
            EVENT.type == sfEvtClosed ? sfRenderWindow_close(WINDOW) : 0;
        sfRenderWindow_display(WINDOW);
    }
    return 0;
}

int main_game(glo *all)
{
    display_game(all);
    return 0;
}

int menu_click(glo *all)
{
    sfVector2i mouse = sfMouse_getPositionRenderWindow(WINDOW);
    if (mouse.x >= 802 && mouse.x <= 1100
        && EVENT.type == sfEvtMouseButtonPressed) {
        if (mouse.y >= 730 && mouse.y <= 977) {
            main_game(all);
        }
    }
    return 0;
}

int display_menu(glo *all)
{
    while (sfRenderWindow_isOpen(WINDOW)) {
        sfRenderWindow_clear(WINDOW, sfWhite);
        while (sfRenderWindow_pollEvent(WINDOW, &EVENT))
            EVENT.type == sfEvtClosed ? sfRenderWindow_close(WINDOW) : 0;
        for (int i = 0; i < 2; i++)
            sfRenderWindow_drawSprite(WINDOW, IMAGES[i].sprite, NULL);
        sfRenderWindow_display(WINDOW);
        menu_click(all);
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
