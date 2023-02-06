/*
** EPITECH PROJECT, 2023
** Test
** File description:
** animation_player
*/

#include "../include/my.h"

int stop_player_animation(glo *all)
{
    SPRITE[0].rectangle.left = 0;
    sfSprite_setTextureRect(SPRITE[0].sprite, SPRITE[0].rectangle);

    return 0;
}

int animation_dresseur_direction(glo *all, int nb)
{
    SPRITE[0].rectangle.top = nb;
    if (SPRITE[0].rectangle.left == 256)
	SPRITE[0].rectangle.left = 0;
    SPRITE[0].clock_time->time =
        sfClock_getElapsedTime(SPRITE[0].clock_time->clock);
    SPRITE[0].clock_time->seconds =
        SPRITE[0].clock_time->time.microseconds / 250000.0;
    if (SPRITE[0].clock_time->seconds > 1.0) {
	SPRITE[0].rectangle.left += 64;
        sfClock_restart(SPRITE[0].clock_time->clock);
    }
    sfSprite_setTextureRect(SPRITE[0].sprite, SPRITE[0].rectangle);

    return 0;
}

int animation_dresseur(glo *all, int a)
{
    if (a == 1)
        animation_dresseur_direction(all, 0);
    if (a == 2)
        animation_dresseur_direction(all, 200);
    if (a == 3)
        animation_dresseur_direction(all, 128);
    if (a == 4)
        animation_dresseur_direction(all, 64);

    all->player.animation = a;

    return 0;
}
