/*
** EPITECH PROJECT, 2023
** test
** File description:
** map_draw
*/

#include "../include/my.h"

int centre_pokemon(glo *all)
{
    MAP[0].rectangle.top = 0;
    MAP[0].rectangle.left = 120;
    MAP[0].rectangle.width = 150;
    MAP[0].rectangle.height = 120;

    return 0;
}

int poke_shop(glo *all)
{
    MAP[0].rectangle.top = 0;
    MAP[0].rectangle.left = 0;
    MAP[0].rectangle.width = 120;
    MAP[0].rectangle.height = 120;

    return 0;
}

int map_condition(glo *all, int nb)
{
    if (nb == 1)
        poke_shop(all);
    if (nb == 2)
        centre_pokemon(all);
    return 0;
}

int reset_set_map(glo *all, int i)
{
    if (i == 0)
        MAP[0].pos.y += 20;
    else
        MAP[0].pos.y = 0;
    MAP[0].pos.x = 0;

    return 0;
}

int map_drawing(glo *all)
{
    sfSprite_setPosition(MAP[0].sprite, MAP[0].pos);
    sfSprite_setTextureRect(MAP[0].sprite, MAP[0].rectangle);
    sfRenderWindow_drawSprite(WINDOW, MAP[0].sprite, NULL);

    return 0;
}

int new_map_to_draw(glo *all, char **map)
{
    for (int i = 0; map[i] != NULL; i++) {
        for (int a = 0; map[i][a] != '\0'; a++) {
            if ((map[i][a] - 48 != 0) && (map[i][a] != '\n') && (map[i][a] != ' ')) {
                map_condition(all, map[i][a] - 48);
                map_drawing(all);
            }
            if (map[i][a] == '\n')
                reset_set_map(all, 0);
            if (map[i][a] == '0')
                MAP[0].pos.x += 50;
        }
    }
    reset_set_map(all, -1);
    return 0;
}

int draw_map(glo *all)
{
    char *map[10] =
        {"0 2 0 0 0 0 2 0 \n",
         "0 0 0 0 0 0 0 0 \n",
         "0 0 0 0 0 0 0 0 \n",
         "0 0 0 0 0 0 0 0 \n",
         "0 0 0 0 0 0 0 0 \n",
         "0 0 0 0 0 0 0 0 \n",
         "0 0 0 0 0 0 0 0 \n",
         "0 0 1 0 0 0 0 0 \n",
         "0 0 0 0 0 0 0 0 \n",
         NULL};

    new_map_to_draw(all, map);
    return 0;
}
