/*
** EPITECH PROJECT, 2020
** count_commands
** File description:
** count_commands
*/

#include "assembler.h"

int count_cmd_len_first(char **arr, int pos)
{
    char *name = NULL;
    int len = 1;

    if (!arr[pos])
        return len;
    name = get_func_name(arr[pos]);
    while (!name) {
        pos++;
        if (!arr[pos])
            return len;
        name = get_func_name(arr[pos]);
        len++;
    }
    free(name);
    if (len > 1)
        len--;
    return len;
}

int count_cmd_len(char **arr, int pos)
{
    char *name = NULL;
    char *new = NULL;
    int len = 1;

    name = get_func_name(arr[pos++]);
    new = get_func_name(arr[pos]);
    while (my_strcmp(name, new) != 0 && arr[pos]) {
        if (new)
            free(new);
        if (arr[pos]) {
            pos++;
            len++;
            new = get_func_name(arr[pos]);
        }
    }
    free(name);
    free(new);
    return len;
}
