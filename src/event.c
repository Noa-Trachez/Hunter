/*
** EPITECH PROJECT, 2021
** B-MUL-100-LIL-1-1-myhunter-noa.trachez
** File description:
** event.c
*/

#include "../include/graph.h"
#include "../include/duck.h"
#include "../include/event.h"
#include "../include/window.h"
#include "../include/main.h"
#include "../include/display.h"

void create_state_of_game(info_game_t *info)
{
    sfTexture *texture_fly = sfTexture_createFromFile("img/fly_away.png", 0);
    sfTexture *handle_text = sfTexture_createFromFile("img/button.png", 0);

    info->text = sfText_create();
    info->font = sfFont_createFromFile("img/fast99.ttf");
    info->fly_away = sfSprite_create();
    info->handle = sfSprite_create();
    info->handle_nbr = 0;
    info->position_sprite = (sfVector2f){190, 0};
    sfText_setFont(info->text, info->font);
    sfText_setCharacterSize(info->text, 50);
    sfSprite_setTexture(info->fly_away, texture_fly, sfTrue);
    sfSprite_setTexture(info->handle, handle_text, sfTrue);
    sfSprite_setScale(info->fly_away, (sfVector2f){0.3, 0.3});
    sfSprite_setScale(info->handle, (sfVector2f){0.2, 0.2});
    info->nb_of_ammo = 3;
    info->round = 1;
    info->score_nbr = 0;
    info->nbr_duck_touch = 0;
    info->clock = sfClock_create();
}

void mouse_shoot(window_t *window, duck_t *duck, info_game_t *info_game)
{
    int is_on_same_x;
    int is_on_same_y;
    int pos_duckX = duck->position.x;
    int pos_duckY = duck->position.y;
    sfVector2i mouse = sfMouse_getPositionRenderWindow(window->screen);
    sfVector2u scale = sfRenderWindow_getSize(window->screen);

    mouse.x = mouse.x * 800 / scale.x;
    mouse.y = mouse.y * 600 / scale.y;
    is_on_same_x = pos_duckX - 60 <= mouse.x && pos_duckX + 60 >= mouse.x;
    is_on_same_y = pos_duckY - 60 <= mouse.y && pos_duckY + 40 >= mouse.y;
    if (is_on_same_x && is_on_same_y)
        duck_touch_by_mouse(duck);
    else
        info_game->nb_of_ammo -= 1;
}

void event_manager(sfEvent *event, window_t *window, duck_t *duck,
info_game_t *info)
{
    if (event->type == sfEvtClosed)
        sfRenderWindow_close(window->screen);
    if (event->type == sfEvtKeyPressed)
        if (event->key.code == sfKeyEscape)
            sfRenderWindow_close(window->screen);
    if (event->type == sfEvtMouseButtonPressed)
        if (event->mouseButton.button == sfMouseLeft && duck->state == 0)
            mouse_shoot(window, duck, info);
}
