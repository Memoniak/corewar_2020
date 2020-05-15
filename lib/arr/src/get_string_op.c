/*
** EPITECH PROJECT, 2020
** get_string_between
** File description:
** get_string_op
*/

#include "arr.h"

char *get_string_inbetween(char *str, char op)
{
    char *res;
    int len = 0;
    int check = 0;
    int z = 0;

    while (str[len++]);
    res = malloc(sizeof(char) * len);
    for (int i = 0; str[i]; i++) {
        if (str[i] == op && !check) {
            i++;
            check = 1;
        } else if (str[i] == op && check)
            check = 0;
        if (check)
            res[z++] = str[i];
    }
    res[z] = '\0';
    return res;
}
