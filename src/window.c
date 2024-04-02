/*
** EPITECH PROJECT, 2021
** B-MUL-100-LIL-1-1-myhunter-noa.trachez
** File description:
** window.c
*/

#include "../include/graph.h"
#include "../include/duck.h"
#include "../include/event.h"
#include "../include/window.h"
#include "../include/main.h"
#include "../include/display.h"

void create_window(window_t *window)
{
    sfTexture *texture = sfTexture_createFromFile("img/spritesheet.png", 0);
    sfTexture *texture_state = sfTexture_createFromFile("img/state.png", 0);
    sfTexture *cross = sfTexture_createFromFile("img/cross.png", 0);

    window->rectangle = (sfIntRect){0, 0, 3500, 240};
    window->mode = (sfVideoMode){800, 600, 32};
    window->screen = sfRenderWindow_create(window->mode, "Duck Hunt",
    sfDefaultStyle, NULL);
    window->img = sfSprite_create();
    window->state = sfSprite_create();
    window->cursor = sfSprite_create();
    sfSprite_setTexture(window->cursor, cross, sfTrue);
    sfSprite_setTexture(window->img, texture, sfTrue);
    sfSprite_setTexture(window->state, texture_state, sfTrue);
    sfSprite_setPosition(window->state, (sfVector2f){0, 480});
    sfSprite_setScale(window->img, (sfVector2f){1.6, 2});
    sfSprite_setScale(window->state, (sfVector2f){1, 0.62});
    sfSprite_setScale(window->cursor, (sfVector2f){0.15, 0.15});
    window->clock = sfClock_create();
}

void display_handle_state(window_t *window, info_game_t *info_game)
{
    sfIntRect sprite = {388, 0, 194, 196};
    sfVector2f sprite_pos = {180, 0};

    for (int i = 0; i < 10; i++) {
        sfSprite_setTextureRect(info_game->handle, sprite);
        sfSprite_setPosition(info_game->handle, sprite_pos);
        sfRenderWindow_drawSprite(window->screen, info_game->handle, NULL);
        sprite_pos.x += 40;
    }
    sprite_pos = (sfVector2f ){180, 0};
    sprite.left -= 195;
    for (int i = 0; i < info_game->handle_nbr; i++) {
        sfSprite_setTextureRect(info_game->handle, sprite);
        sfSprite_setPosition(info_game->handle, sprite_pos);
        sfRenderWindow_drawSprite(window->screen, info_game->handle, NULL);
        sprite_pos.x += 40;
    }
}

void display_window(window_t *window, info_game_t *info_game)
{
    float seconds;
    sfTime time = sfClock_getElapsedTime(window->clock);

    seconds = time.microseconds / 10000.0;
    if (seconds > 15) {
        window->rectangle.left -= 500;
        if (window->rectangle.left < 0)
            window->rectangle.left = 3500;
        sfClock_restart(window->clock);
    }
    sfRenderWindow_setMouseCursorVisible(window->screen, 0);
    sfSprite_setTextureRect(window->img, window->rectangle);
    sfRenderWindow_drawSprite(window->screen, window->img, NULL);
    display_handle_state(window, info_game);
}

void display_game_over(window_t *window, info_game_t *info_game)
{
    sfRenderWindow_setMouseCursorVisible(window->screen, sfTrue);
    sfRenderWindow_clear(window->screen, sfBlack);
    sfText_setString(info_game->text, " Game OVER\nYour Score is :");
    sfText_setPosition(info_game->text, (sfVector2f){250, 200});
    sfText_setColor(info_game->text, sfRed);
    sfRenderWindow_drawText(window->screen, info_game->text, 0);
    sfText_setString(info_game->text, unsigned_to_str(info_game->score_nbr));
    sfText_setPosition(info_game->text, (sfVector2f){300, 300});
    sfRenderWindow_drawText(window->screen, info_game->text, 0);
}

void display_anim(duck_t *duck, window_t *window, info_game_t *info_game)
{
    int stop = duck->nbr_duck_alive <= 0 && info_game->nbr_duck_touch <= 3;
    int check_state = duck->state == 4 || duck->state == 5;

    if (!(check_state && stop)) {
        display_window(window, info_game);
        if (duck->state < 4)
            display_duck(duck, window);
        display_event(info_game, duck, window);
        display_info_game(info_game, window);
    } else
        display_game_over(window, info_game);
}
