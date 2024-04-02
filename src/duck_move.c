/*
** EPITECH PROJECT, 2021
** B-MUL-100-LIL-1-1-myhunter-noa.trachez
** File description:
** duck_move.c
*/

#include "../include/graph.h"
#include "../include/duck.h"
#include "../include/event.h"
#include "../include/window.h"
#include "../include/main.h"
#include "../include/display.h"

void define_add_x_y(duck_t *duck)
{
    int random_in_teta;
    int speed = duck->info_game->round - 1 + 5;

    srand(time( NULL ));
    random_in_teta = rand() % 361;
    duck->dir_x = sin(random_in_teta) * speed;
    duck->dir_y = cos(random_in_teta) * speed;
    if (duck->dir_y == 0)
        duck->dir_y += 4;
    if (duck->dir_x == 0)
        duck->dir_x += 4;
}

void define_sens_duck(duck_t *duck)
{
    if (duck->dir_x < 0) {
        sfSprite_scale(duck->img, (sfVector2f){-1, 1});
        duck->can_rev = 1;
    } else if (duck->dir_x > 0 && duck->can_rev) {
        sfSprite_scale(duck->img, (sfVector2f){-1, 1});
        duck->can_rev = 0;
    }
}

void calc_deplacement(duck_t *duck)
{
    if (duck->dist_travel > 400) {
        define_add_x_y(duck);
        duck->dist_travel = 0;
    }
    if (duck->dir_x > 0)
        duck->dist_travel += duck->dir_x;
    else
        duck->dist_travel -= duck->dir_x;
    if (duck->dir_y > 0)
        duck->dist_travel += duck->dir_y;
    else
        duck->dist_travel -= duck->dir_y;
}

void choose_direction(duck_t *duck)
{
    if (duck->rectangle.left == 1992)
        duck->rectangle.left = 0;
    if (duck->position.x > 700 && duck->dir_x > 0)
        duck->dir_x *= -1;
    if (duck->position.x < 50 && duck->dir_x < 0)
        duck->dir_x *= -1;
    if (duck->position.y < 50 && duck->dir_y < 0)
        duck->dir_y *= -1;
    if (duck->position.y > 350 && duck->dir_y > 0)
        duck->dir_y *= -1;
}

void duck_pop(duck_t *duck)
{
    srand(time( NULL ));
    duck->position.x = (rand() % 301) + 300;
    duck->position.y = 470;
    duck->state = 0;
    sfSprite_setRotation(duck->img, 0);
    sfClock_restart(duck->clock);
}
