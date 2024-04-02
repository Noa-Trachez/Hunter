/*
** EPITECH PROJECT, 2021
** B-MUL-100-LIL-1-1-myhunter-noa.trachez
** File description:
** len_nb.c
*/

#include "../include/graph.h"
#include "../include/duck.h"
#include "../include/event.h"
#include "../include/window.h"
#include "../include/main.h"
#include "../include/display.h"

int len_nb(unsigned long long source)
{
    unsigned int len = 0;

    for (; source > 0; len++)
        source /= 10;
    return (len);
}

int my_strcmp(char const *s1, char const *s2)
{
    int range = 0;

    while (s1[range] == s2[range] && s1[range] != '\0' && s2[range] != '\0') {
        range += 1;
    }
    return (s1[range] - s2[range]);
}

char *my_revstr(char *str)
{
    int len = 0;
    int end;
    int temp;

    while (str[len] != '\0') {
        len += 1;
    }
    end = len - 1;
    for (int range = 0; range < (len / 2); range++) {
        temp = str[range];
        str[range] = str[end];
        str[end] = temp;
        end -= 1;
    }
    str[len] = '\0';
    return (str);
}

char *unsigned_to_str(unsigned long long nbr)
{
    int len = 0;
    char *result;
    int i = 0;

    if (nbr == 0)
        return ("0");
    len = len_nb(nbr);
    result = malloc(sizeof(char) * len + 1);
    result[len] = '\0';
    while (len > 0) {
        result[i] = nbr % 10 + 48;
        nbr /= 10;
        len--;
        i++;
    }
    my_revstr(result);
    return (result);
}
