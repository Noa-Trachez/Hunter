/*
** EPITECH PROJECT, 2021
** B-MUL-100-LIL-1-1-myhunter-noa.trachez
** File description:
** duck.c
*/

#include "../include/graph.h"
#include "../include/duck.h"
#include "../include/event.h"
#include "../include/window.h"
#include "../include/main.h"
#include "../include/display.h"

void create_duck(duck_t *duck, info_game_t *info_game)
{
    sfTexture *texture = sfTexture_createFromFile("img/bird.png", 0);

    duck->rectangle = (sfIntRect){0, 0, 166, 166};
    duck->position = (sfVector2f) {0, 470};
    duck->state = 2;
    duck->dist_travel = 500;
    duck->speed = 5.0;
    duck->dir_x = 0;
    duck->dir_y = 0;
    duck->can_rev = 0;
    duck->nbr_duck_alive = 10;
    duck->img = sfSprite_create();
    sfSprite_setTexture(duck->img, texture, sfFalse);
    sfSprite_setScale(duck->img, (sfVector2f){0.8, 0.8});
    sfSprite_setOrigin(duck->img, (sfVector2f){166 / 2, 166 / 2});
    duck->clock = sfClock_create();
    duck->info_game = info_game;
}

void duck_touch_by_mouse(duck_t *duck)
{
    sfClock_restart(duck->clock);
    duck->info_game->nb_of_ammo = 3;
    duck->state = 1;
    duck->rectangle.top += 166;
    if (duck->can_rev)
        sfSprite_rotate(duck->img, -90);
    else
        sfSprite_rotate(duck->img, 90);
    duck->dist_travel = 500;
    duck->info_game->score_nbr += SCORE;
    duck->nbr_duck_alive -= 1;
    duck->info_game->handle_nbr += 1;
    duck->info_game->nbr_duck_touch += 1;
}

void duck_fly_away(duck_t *duck)
{
    float seconds;
    sfTime time = sfClock_getElapsedTime(duck->clock);

    seconds = time.microseconds / 1000000.0;
    if (seconds < 2)
        sfSprite_rotate(duck->img, 270);
    else {
        duck->position.y -= 20;
        if (duck->can_rev)
            sfSprite_setRotation(duck->img, 90);
        else
            sfSprite_setRotation(duck->img, -90);
        if (duck->position.y < 0) {
            duck->state = 4;
            duck->nbr_duck_alive -= 1;
            duck->info_game->nb_of_ammo = 3;
            duck->info_game->handle_nbr += 1;
        }
    }
}

void duck_dead(duck_t *duck)
{
    duck->position.y += 5;
    if (duck->position.y > 600) {
        duck->rectangle.top -= 166;
        duck->state = 5;
        if (duck->can_rev)
            sfSprite_rotate(duck->img, 90);
        else
            sfSprite_rotate(duck->img, 270);
    }
}

void duck_alive(duck_t *duck)
{
    if (duck->info_game->nb_of_ammo == 0) {
        duck->state = 3;
        sfClock_restart(duck->clock);
    }
    duck->rectangle.left += 166;
    calc_deplacement(duck);
    choose_direction(duck);
    if (!duck->can_rev || duck->dir_x > 0)
        define_sens_duck(duck);
    duck->position.x += duck->dir_x;
    duck->position.y += duck->dir_y;
}
