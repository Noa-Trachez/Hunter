/*
** EPITECH PROJECT, 2021
** B-MUL-100-LIL-1-1-myhunter-noa.trachez
** File description:
** main.h
*/

#ifndef MAIN_H_
    #define MAIN_H_
    #include "graph.h"

void create_state_of_game(info_game_t *info);
void display_duck(duck_t *duck, window_t *window);
void display_event(info_game_t *info_game, duck_t *duck, window_t *window);
void display_info_game(info_game_t *info_game, window_t *window);
void game(window_t *window, duck_t *duck, info_game_t *info_game);
int usage(void);
int main(int ac, char **argv);

#endif
