/*
** EPITECH PROJECT, 2021
** B-MUL-100-LIL-1-1-myhunter-noa.trachez
** File description:
** event.h
*/

#ifndef EVENT_H_
    #define EVENT_H_

void mouse_shoot(window_t *window, duck_t *duck, info_game_t *info_game);
void check_key_pressed(sfEvent *event, window_t *window);
void event_manager(sfEvent *event, window_t *window, duck_t *duck,
info_game_t *info);
int len_nb(unsigned long long source);
int my_strcmp(char const *s1, char const *s2);
char *unsigned_to_str(unsigned long long nbr);
char *my_revstr(char *str);
void create_state_of_game(info_game_t *info);

#endif
