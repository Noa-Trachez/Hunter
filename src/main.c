/*
** EPITECH PROJECT, 2021
** B-MUL-100-LIL-1-1-myhunter-noa.trachez
** File description:
** main.c
*/

#include "../include/graph.h"
#include "../include/duck.h"
#include "../include/event.h"
#include "../include/window.h"
#include "../include/main.h"
#include "../include/display.h"

void game(window_t *window, duck_t *duck, info_game_t *info_game)
{
    sfEvent event;

    while (sfRenderWindow_isOpen(window->screen)) {
        sfRenderWindow_clear(window->screen, sfBlack);
        while (sfRenderWindow_pollEvent(window->screen, &event))
            event_manager(&event, window, duck, info_game);
        display_anim(duck, window, info_game);
        sfRenderWindow_display(window->screen);
    }
    sfRenderWindow_destroy(window->screen);
}

int usage(void)
{
    write(1, "This program is a video game based on DuckHunt\n", 47);
    write(1, "This video game is a one player game\n", 37);
    write(1, "The aim is to shoot all duck you see\n", 37);
    return (0);
}

int main(int ac, char **argv)
{
    window_t window;
    duck_t duck;
    info_game_t info_game;

    if (ac != 1) {
        if (my_strcmp(argv[1], "-h") == 0)
            return (usage());
        else
            return (84);
    }
    create_window(&window);
    create_state_of_game(&info_game);
    create_duck(&duck, &info_game);
    sfRenderWindow_setFramerateLimit(window.screen, 60);
    game(&window, &duck, &info_game);
    return (0);
}
