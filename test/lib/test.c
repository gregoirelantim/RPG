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

int test(glo *all)
{
    test_menu(all);
    return 0;
}
