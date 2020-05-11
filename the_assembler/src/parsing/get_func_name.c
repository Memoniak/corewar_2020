/*
** EPITECH PROJECT, 2020
** get_func_name
** File description:
** gets a function name in .s lang
*/

#include "corewar.h"

char *get_func_name(char *str)
{
    char *name = NULL;

    if (!str)
        return NULL;
    for (int i = 0; str[i]; i++) {
        if (str[i] == LABEL_CHAR && str[i - 1] != DIRECT_CHAR) {
            name = malloc(sizeof(char) * i + 1);
            name = my_strncpy(name, str, i);
            return name;
        }
    }
    return name;
}
