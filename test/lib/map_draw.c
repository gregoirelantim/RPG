/*
** EPITECH PROJECT, 2023
** test
** File description:
** map_draw
*/

#include "../include/my.h"

int fleurs_1(glo *all)
{
    MAP[0].rectangle.top = 0;
    MAP[0].rectangle.left = 450;
    MAP[0].rectangle.width = 30;
    MAP[0].rectangle.height = 30;

    return 0;
}

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

int herbe(glo *all)
{
    MAP[1].rectangle.top = 0;
    MAP[1].rectangle.left = 0;
    MAP[1].rectangle.width = 30;
    MAP[1].rectangle.height = 30;

    return 1;
}

int map_condition(glo *all, int nb)
{
    if (nb == 4)
        return herbe(all);
    if (nb == 1)
        return poke_shop(all);
    if (nb == 2)
        return centre_pokemon(all);
    if (nb == 3)
        return fleurs_1(all);

    return 0;
}

int reset_set_map(glo *all, int i)
{
    if (i == 0) {
        MAP[0].pos.y += 20;
        MAP[1].pos.y += 20;
    } else {
        MAP[0].pos.y = 0;
        MAP[1].pos.y = 0;
    }
    MAP[0].pos.x = 0;
    MAP[1].pos.x = 0;

    return 0;
}

int map_drawing(glo *all, int i)
{
    sfSprite_setPosition(MAP[i].sprite, MAP[i].pos);
    sfSprite_setTextureRect(MAP[i].sprite, MAP[i].rectangle);
    sfRenderWindow_drawSprite(WINDOW, MAP[i].sprite, NULL);

    return 0;
}

int new_map_to_draw(glo *all, char **map)
{
    for (int i = 0; map[i] != NULL; i++) {
        for (int a = 0; map[i][a] != '\0'; a++) {
            if ((map[i][a] - 48 != 0) && (map[i][a] != '\n') && (map[i][a] != ' ')) {
                map_drawing(all, map_condition(all, map[i][a] - 48));
            }
            if (map[i][a] == '\n')
                reset_set_map(all, 0);
            if (map[i][a] == '0') {
                MAP[0].pos.x += 50;
                MAP[1].pos.x += 50;
            }
        }
    }
    reset_set_map(all, -1);
    return 0;
}

int draw_map(glo *all, char **map)
{
    new_map_to_draw(all, map);
    return 0;
}

int map_load(glo *all)
{
    int y = all->pos_y;
    int x = all->pos_x;
    char **mini_map = malloc(sizeof(char *) * 10);
    char *map[200] =
        {"--------------------------------------------------------------------------------------------------------------",
         "- 0 2 0 0 0 0 2 0 0 0 0 0 0 0 0 0 0 3 0 3 0 2 0 0 0 0 2 0 0 0 0 0 0 0 0 0 0 3 0 3 0 2 0 0 0 0 0 4 0 0 0 2 0 0\n",
         "- 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0\n",
         "- 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0\n",
         "- 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0\n",
         "- 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 2 0 0 0 0 0 0 0\n",
         "- 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0\n",
         "- 0 0 0 0 0 0 0 0 0 0 0 0 4 0 4 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0\n",
         "- 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0\n",
         "- 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0\n",
         NULL};
    for (int i = 0; i < 10; i++) {
        mini_map[i] = malloc(sizeof(char) * 99);
        for (int a = 0; a < 98; a++) {
            mini_map[i][a] = map[y][x++];
        }
        mini_map[i][98] = '\0';
        y++;
        x = 0;
    }
    mini_map[10] = NULL;

    draw_map(all, mini_map);
    return 0;
}
