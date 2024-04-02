/*
** EPITECH PROJECT, 2021
** B-MUL-100-LIL-1-1-myhunter-noa.trachez
** File description:
** display.c
*/

#include "../include/graph.h"
#include "../include/duck.h"
#include "../include/event.h"
#include "../include/window.h"
#include "../include/main.h"
#include "../include/display.h"

void display_duck(duck_t *duck, window_t *window)
{
    float seconds;
    sfTime time = sfClock_getElapsedTime(duck->clock);
    void (*state[4])(duck_t *) = {&duck_alive, &duck_dead, &duck_pop,
    &duck_fly_away};

    seconds = time.microseconds / 1000000.0;
    if (seconds < 4.8)
        state[duck->state](duck);
    else {
        duck->state = 3;
        sfClock_restart(duck->clock);
    }
    sfSprite_setPosition(duck->img, duck->position);
    sfSprite_setTextureRect(duck->img, duck->rectangle);
    sfRenderWindow_drawSprite(window->screen, duck->img, NULL);
}

void fly_away_sprite(info_game_t *info_game, duck_t *duck, window_t *window)
{
    int window_width = window->mode.width;
    float seconds;
    sfVector2f pos_fly_away = {window_width / 4, window->mode.height / 4};
    sfTime time = sfClock_getElapsedTime(duck->clock);

    sfSprite_setPosition(info_game->fly_away, pos_fly_away);
    if (duck->state == 3) {
        seconds = time.microseconds / 1000000.0;
        if (seconds < 2)
            sfRenderWindow_drawSprite(window->screen,
            info_game->fly_away, NULL);
    }
}

void display_event(info_game_t *info_game, duck_t *duck, window_t *window)
{
    int check_state = duck->state == 4 || duck->state == 5;
    int can_ctn = duck->nbr_duck_alive <= 0 && info_game->nbr_duck_touch > 3;

    fly_away_sprite(info_game, duck, window);
    if (check_state && duck->nbr_duck_alive > 0)
        duck->state = 2;
    else if (check_state && can_ctn) {
        info_game->round += 1;
        info_game->nbr_duck_touch = 0;
        info_game->handle_nbr = 0;
        duck->state = 2;
        duck->nbr_duck_alive = 10;
    }
}

void display_info_game(info_game_t *info_game, window_t *window)
{
    sfVector2f position_screen[3] = {{20, 520}, {660, 470}, {660, 540}};
    sfVector2i mouse_coor = sfMouse_getPositionRenderWindow(window->screen);
    sfVector2u scale = sfRenderWindow_getSize(window->screen);
    sfVector2f mouse = {mouse_coor.x * 800 / scale.x,
    mouse_coor.y * 600 / scale.y};
    char *score[3] = {unsigned_to_str(info_game->score_nbr),
    unsigned_to_str(info_game->round),
    unsigned_to_str(info_game->nb_of_ammo)};

    sfRenderWindow_drawSprite(window->screen, window->state, NULL);
    for (int i = 0; i < 3; i++) {
        sfText_setString(info_game->text, score[i]);
        sfText_setPosition(info_game->text, position_screen[i]);
        sfRenderWindow_drawText(window->screen, info_game->text, 0);
    }
    sfSprite_setPosition(window->cursor, mouse);
    sfRenderWindow_drawSprite(window->screen, window->cursor, NULL);
}
