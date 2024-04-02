/*
** EPITECH PROJECT, 2021
** B-MUL-100-LIL-1-1-myhunter-noa.trachez
** File description:
** duck.h
*/

#ifndef DUCK_H_
    #define DUCK_H_
    #include "graph.h"

void create_duck(duck_t *duck, info_game_t *info_game);
void duck_touch_by_mouse(duck_t *duck);
void duck_dead(duck_t *duck);
void duck_alive(duck_t *duck);
void duck_pop(duck_t *duck);
void define_add_x_y(duck_t *duck);
void calc_deplacement(duck_t *duck);
void choose_direction(duck_t *duck);
void define_sens_duck(duck_t *duck);
void duck_fly_away(duck_t *duck);

#endif
