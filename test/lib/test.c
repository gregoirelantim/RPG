/*
** EPITECH PROJECT, 2023
** TEST
** File description:
** test
*/

#include "../include/my.h"

int animation_dresseur_down(glo *all)
{
    if (SPRITE[0].rectangle.left == 256)
        SPRITE[0].rectangle.left = 0;
    SPRITE[0].clock_time->time = sfClock_getElapsedTime(SPRITE[0].clock_time->clock);
    SPRITE[0].clock_time->seconds = SPRITE[0].clock_time->time.microseconds / 250000.0;
    if (SPRITE[0].clock_time->seconds > 1.0) {
        SPRITE[0].rectangle.left += 64;
        sfClock_restart(SPRITE[0].clock_time->clock);
    }
    sfSprite_setTextureRect(SPRITE[0].sprite, SPRITE[0].rectangle);

    return 0;
}

int player_move_right_left(glo *all, int nb, int sprite)
{
    SPRITE[sprite].pos.x += nb;
    return 0;
}

int player_move_up_down(glo *all, int nb, int sprite)
{
    SPRITE[sprite].pos.y += nb;
    return 0;
}

int player_move(glo *all)
{
    if (EVENT.key.code == 74)
        player_move_up_down(all, 5, 0);
    if (EVENT.key.code == 73)
        player_move_up_down(all, -5, 0);
    if (EVENT.key.code == 72)
        player_move_right_left(all, 7, 0);
    if (EVENT.key.code == 71)
        player_move_right_left(all, -7, 0);

    sfSprite_setPosition(SPRITE[0].sprite, SPRITE[0].pos);
    sfSprite_setTextureRect(SPRITE[0].sprite, SPRITE[0].rectangle);
    return 0;
}

int display_game(glo *all)
{
    char c;
    while (sfRenderWindow_isOpen(WINDOW)) {
        sfRenderWindow_clear(WINDOW, sfBlack);
        while (sfRenderWindow_pollEvent(WINDOW, &EVENT))
            EVENT.type == sfEvtClosed ? sfRenderWindow_close(WINDOW) : 0;
        sfRenderWindow_drawSprite(WINDOW, SPRITE[0].sprite, NULL);
        if (EVENT.type == sfEvtKeyPressed) {
            player_move(all);
            usleep(20000);
        }
        animation_dresseur_down(all);
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
