/*
** EPITECH PROJECT, 2023
** test
** File description:
** init_images
*/

#include "../include/my.h"

int init_menu_texture(glo *all)
{
    for (int i = 0; i < 6; i++) {
        sfSprite_setTexture(IMAGES[i].sprite, IMAGES[i].texture, sfTrue);
	sfSprite_setScale(IMAGES[i].sprite, IMAGES[i].scale);
        if (i != 0) {
            sfSprite_setPosition(IMAGES[i].sprite, IMAGES[i].pos);
	}
    }
    return 0;
}

int init_menu_sprite(glo *all)
{
    for (int i = 0; i < 6; i++)
        IMAGES[i].sprite = sfSprite_create();

    return 0;
}

int init_menu_scale(glo *all)
{
    IMAGES[0].scale.x = 3.65;
    IMAGES[0].scale.y = 2.2;

    IMAGES[1].scale.x = 0.25;
    IMAGES[1].scale.y = 0.25;

    IMAGES[2].scale.x = 0.5;
    IMAGES[2].scale.y = 0.5;

    IMAGES[3].scale.x = 0.5;
    IMAGES[3].scale.y = 0.5;

    IMAGES[4].scale.x = 0.5;
    IMAGES[4].scale.y = 0.5;

    IMAGES[5].scale.x = 0.1;
    IMAGES[5].scale.y = 0.1;
    return 0;
}

int init_menu_pos(glo *all)
{
    IMAGES[1].pos.x = 900;
    IMAGES[1].pos.y = 540;

    IMAGES[2].pos.x = 100;
    IMAGES[2].pos.y = 300;

    IMAGES[3].pos.x = 700;
    IMAGES[3].pos.y = 400;

    IMAGES[4].pos.x = 1300;
    IMAGES[4].pos.y = 400;

    IMAGES[5].pos.x = 840;
    IMAGES[5].pos.y = 400;

    return 0;
}

int init_menu_images(glo *all)
{
    IMAGES[0].texture = sfTexture_createFromFile("lib/back_ground_menu.png", NULL);
    IMAGES[1].texture = sfTexture_createFromFile("lib/bouton_start.jpg", NULL);
    IMAGES[2].texture = sfTexture_createFromFile("lib/main.jpg", NULL);
    IMAGES[3].texture = sfTexture_createFromFile("lib/poing.jpg", NULL);
    IMAGES[4].texture = sfTexture_createFromFile("lib/cisceaux.jpg", NULL);
    IMAGES[5].texture = sfTexture_createFromFile("lib/play.jpg", NULL);
    return 0;
}

int init_menu(glo *all)
{
    init_window(all);
/*    init_menu_images(all);
    init_menu_sprite(all);
    init_menu_scale(all);
    init_menu_pos(all);
    init_menu_texture(all);*/
    return 0;
}

int init_window(glo *all)
{
    all->setting.mode.bitsPerPixel = 32;
    all->setting.mode.width = 1920;
    all->setting.mode.height = 1080;
    all->setting.window = sfRenderWindow_create
        (all->setting.mode, "MY_POKEMON", sfResize | sfClose, NULL);

    return 0;
}
