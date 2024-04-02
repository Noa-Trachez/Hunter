/*
** EPITECH PROJECT, 2021
** B-MUL-100-LIL-1-1-myhunter-noa.trachez
** File description:
** graph.h
*/

#ifndef GRAPH_H_
    #define GRAPH_H_
    #include <SFML/Graphics.h>
    #include <SFML/Window.h>
    #include <stdio.h>
    #include <stdlib.h>
    #include <math.h>
    #include <time.h>
    #include <string.h>
    #include <unistd.h>
    #define SCORE 500

typedef struct {
    sfVideoMode mode;
    sfRenderWindow *screen;
    sfIntRect rectangle;
    sfSprite *img;
    sfSprite *cursor;
    sfSprite *state;
    sfClock *clock;
} window_t;

typedef struct {
    sfSprite *fly_away;
    sfSprite *handle;
    sfText *text;
    sfFont *font;
    sfClock *clock;
    sfVector2f position_sprite;
    unsigned int round;
    unsigned long long score_nbr;
    int nb_of_ammo;
    int handle_nbr;
    int nbr_duck_touch;
} info_game_t;

typedef struct {
    sfSprite *img;
    sfIntRect rectangle;
    sfVector2f position;
    sfClock *clock;
    int state;
    int dist_travel;
    double speed;
    int dir_x;
    int dir_y;
    int can_rev;
    int nbr_duck_alive;
    info_game_t *info_game;
} duck_t;

#endif
