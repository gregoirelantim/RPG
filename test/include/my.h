/*
** EPITECH PROJECT, 2023
** TEST
** File description:
** my.h
*/

#ifndef TEST_H
    #define TEST_H
    #include <stdlib.h>
    #include <stdio.h>
    #include <unistd.h>
    #include <fcntl.h>
    #include <string.h>
    #include <ncurses.h>
    #include <signal.h>
    #include <SFML/Window.h>
    #include <SFML/System.h>
    #include <SFML/Graphics.h>
    #include <time.h>

    #define WINDOW all->setting.window
    #define EVENT all->setting.event
    #define IMAGES all->images
    #define SPRITE all->perso

typedef struct {
    int animation;
} Player;

typedef struct {
    sfClock *clock;
    sfTime time;
    float seconds;
} Time;

typedef struct {
    sfVideoMode mode;
    sfRenderWindow* window;
    sfEvent event;
} Parameter;

typedef struct {
    sfTexture* texture;
    sfSprite *sprite;
    sfVector2f scale;
    sfVector2f pos;
    sfVector2f size;
} Image;

typedef struct {
    sfTexture* texture;
    sfSprite *sprite;
    sfVector2f scale;
    sfVector2f pos;
    sfVector2f size;
    sfIntRect rectangle;
    sfClock *clock;
    sfTime time;
    float seconds;
    Time clock_time[2];
} Perso;

typedef struct {
    Parameter setting;
    Image images[2];
    Perso perso[3];
    Time *clock_time;
    Player player;
} glo;

int test(glo *all);
int test_menu(glo *all);
int init_window(glo *all);
int init_menu(glo *all);
int init_menu_images(glo *all);
int init_menu_pos(glo *all);
int init_menu_scale(glo *all);
int init_menu_sprite(glo *all);
int init_menu_texture(glo *all);
int display_menu(glo *all);
int init_perso_all(glo *all);
int stop_player_animation(glo *all);
int animation_dresseur_direction(glo *all, int nb);
int animation_dresseur(glo *all, int a);
int player_move(glo *all);
int player_move_up_down(glo *all, int nb, int sprite);
int player_move_right_left(glo *all, int nb, int sprite);
int menu_click(glo *all, char c);
int display_menu(glo *all);
int test_menu(glo *all);
int main_game(glo *all);
int display_game(glo *all);

#endif
