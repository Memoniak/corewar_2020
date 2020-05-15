/*
** EPITECH PROJECT, 2020
** count_commands
** File description:
** count_commands
*/

#include "corewar.h"

int count_cmd_len_first(char **arr, int pos)
{
    char *name = NULL;
    int len = 0;

    if (!arr[pos])
        return 0;
    name = get_func_name(arr[pos]);
    while (!name) {
        pos++;
        len++;
        if (!arr[pos])
            return len;
        name = get_func_name(arr[pos]);
    }
    free(name);
    return len;
}

int count_cmd_len(char **arr, int pos)
{
    char *name = get_func_name(arr[pos]);
    char *new = get_func_name(arr[pos]);
    int len = 0;

    if (!check_line(arr[pos] + my_strlen(name))) {
        pos++;
        len++;
    }
    while (my_strcmp(name, new) && arr[pos]) {
        if (new)
            free(new);
        pos++;
        len++;
        new = get_func_name(arr[pos]);
        if (!new)
            new = my_strcpy(new, name);
    }
    free(name);
    return len;
}
