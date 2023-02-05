/*
** EPITECH PROJECT, 2023
** test
** File description:
** init_images
*/

#include "../include/my.h"

int init_menu_texture(glo *all)
{
    for (int i = 0; i < 2; i++) {
        sfSprite_setTexture(IMAGES[i].sprite, IMAGES[i].texture, sfTrue);
	sfSprite_setScale(IMAGES[i].sprite, IMAGES[i].scale);
        sfSprite_setPosition(IMAGES[i].sprite, IMAGES[i].pos);
    }
    return 0;
}

int init_menu_sprite(glo *all)
{
    for (int i = 0; i < 2; i++)
        IMAGES[i].sprite = sfSprite_create();

    return 0;
}

int init_menu_scale(glo *all)
{
    IMAGES[0].scale.x = 3.3;
    IMAGES[0].scale.y = 1.97;

    IMAGES[1].scale.x = 0.3;
    IMAGES[1].scale.y = 0.3;

    return 0;
}

int init_menu_pos(glo *all)
{
    IMAGES[0].pos.x = -1000;
    IMAGES[0].pos.y = 2;

    IMAGES[1].pos.x = 800;
    IMAGES[1].pos.y = 700;
    
    return 0;
}

int init_menu_images(glo *all)
{
    IMAGES[0].texture = sfTexture_createFromFile("menu_img/menu.jpg", NULL);
    IMAGES[1].texture = sfTexture_createFromFile("menu_img/menu_bouton.png", NULL);
    
    return 0;
}

int init_menu(glo *all)
{
    init_window(all);
    init_menu_images(all);
    init_menu_sprite(all);
    init_menu_scale(all);
    init_menu_pos(all);
    init_menu_texture(all);

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
