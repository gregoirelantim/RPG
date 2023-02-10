/*
** EPITECH PROJECT, 2023
** test
** File description:
** init_map
*/

#include "../include/my.h"

int init_map_scale(glo *all)
{
    MAP[0].scale.x = 1;
    MAP[0].scale.y = 1;

    MAP[1].scale.x = 1;
    MAP[1].scale.y = 1;

    return 0;
}

int init_map_pos(glo *all)
{
    MAP[0].pos.x = 2;
    MAP[0].pos.y = 2;

    return 0;
}

int init_map_rect(glo *all)
{
    MAP[0].rectangle.top = 0;
    MAP[0].rectangle.left = 120;
    MAP[0].rectangle.width = 150;
    MAP[0].rectangle.height = 120;

    return 0;
}

int init_map_images(glo *all)
{
    MAP[0].texture = sfTexture_createFromFile("map/set_2.png", NULL);
    MAP[1].texture = sfTexture_createFromFile("map/set_3.png", NULL);

    return 0;
}

int init_map_texture(glo *all)
{
    for (int i = 0; i < 2; i++) {
        sfSprite_setTexture(MAP[i].sprite, MAP[i].texture, sfTrue);
        sfSprite_setScale(MAP[i].sprite, MAP[i].scale);
	sfSprite_setPosition(MAP[i].sprite, MAP[i].pos);
        sfSprite_setTextureRect(MAP[i].sprite, MAP[i].rectangle);
    }
    return 0;
}

int init_map_sprite(glo *all)
{
    for (int i = 0; i < 2; i++)
        MAP[i].sprite = sfSprite_create();

    return 0;
}

int init_map_all(glo *all)
{
    init_map_images(all);
    init_map_sprite(all);
    init_map_scale(all);
    init_map_pos(all);
    init_map_rect(all);
    init_map_texture(all);

    return 0;
}
