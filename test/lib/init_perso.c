/*
** EPITECH PROJECT, 2023
** test
** File description:
** init_perso.c
*/

#include "../include/my.h"

int init_perso_texture(glo *all)
{
    for (int i = 0; i < 1; i++) {
        sfSprite_setTexture(SPRITE[i].sprite, SPRITE[i].texture, sfTrue);
        sfSprite_setScale(SPRITE[i].sprite, SPRITE[i].scale);
	sfSprite_setPosition(SPRITE[i].sprite, SPRITE[i].pos);
        sfSprite_setTextureRect(SPRITE[i].sprite, SPRITE[0].rectangle);
    }
    return 0;
}

int init_perso_rect(glo *all)
{
    SPRITE[0].rectangle.top = 0;
    SPRITE[0].rectangle.left = 0;
    SPRITE[0].rectangle.width = 50;
    SPRITE[0].rectangle.height = 60;

    SPRITE[0].clock_time->clock = sfClock_create();
    return 0;
}

int init_perso_pos(glo *all)
{
    SPRITE[0].pos.x = 10;
    SPRITE[0].pos.y = 10;

    return 0;
}

int init_perso_scale(glo *all)
{
    SPRITE[0].scale.x = 1;
    SPRITE[0].scale.y = 1;

    return 0;
}

int init_perso_sprite(glo *all)
{
    for (int i = 0; i < 1; i++)
	SPRITE[i].sprite = sfSprite_create();

    return 0;
}

int init_perso_images(glo *all)
{
    SPRITE[0].texture = sfTexture_createFromFile("sprite/dresseur.png", NULL);

    return 0;
}

int init_perso_all(glo *all)
{
    init_perso_images(all);
    init_perso_sprite(all);
    init_perso_scale(all);
    init_perso_pos(all);
    init_perso_rect(all);
    init_perso_texture(all);

    return 0;
}
