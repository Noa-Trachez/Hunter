/*
** EPITECH PROJECT, 2021
** B-MUL-100-LIL-1-1-myhunter-noa.trachez
** File description:
** window.h
*/

#ifndef WINDOW_H_
    #define WINDOW_H_
    #include "graph.h"

void display_window(window_t *window, info_game_t *info_game);
void create_window(window_t *window);
void display_anim(duck_t *duck, window_t *window, info_game_t *info_game);

#endif
