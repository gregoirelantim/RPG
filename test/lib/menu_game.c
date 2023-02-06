/*
** EPITECH PROJECT, 2023
** test
** File description:
** menu_game
*/

#include "../include/my.h"

int menu_click(glo *all, char c)
{
    sfVector2i mouse = sfMouse_getPositionRenderWindow(WINDOW);
    if (c == 'a')
        main_game(all);
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
    char c;
    while (sfRenderWindow_isOpen(WINDOW)) {
        sfRenderWindow_clear(WINDOW, sfWhite);
        while (sfRenderWindow_pollEvent(WINDOW, &EVENT))
            EVENT.type == sfEvtClosed ? sfRenderWindow_close(WINDOW) : 0;
        for (int i = 0; i < 2; i++)
            sfRenderWindow_drawSprite(WINDOW, IMAGES[i].sprite, NULL);
        sfRenderWindow_display(WINDOW);
        c = getch();
        menu_click(all, c);
    }
    return 0;
}

int test_menu(glo *all)
{
    init_menu(all);
    display_menu(all);
    return 0;
}
