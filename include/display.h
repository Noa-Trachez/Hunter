/*
** EPITECH PROJECT, 2021
** B-MUL-100-LIL-1-1-myhunter-noa.trachez
** File description:
** display.h
*/

#ifndef DISPLAY_H_
    #define DISPLAY_H_
    #include "graph.h"

void display_duck(duck_t *duck, window_t *window);
void fly_away_sprite(info_game_t *info_game, duck_t *duck, window_t *window);
void display_event(info_game_t *info_game, duck_t *duck, window_t *window);
void display_info_game(info_game_t *info_game, window_t *window);

#endif
