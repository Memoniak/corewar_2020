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
    int len = -1;

    if (!arr[pos])
        return len;
    name = get_func_name(arr[pos]);
    while (!name) {
        pos++;
        if (!arr[pos])
            return len;
        len++;
        name = get_func_name(arr[pos]);
    }
    free(name);
    return len;
}

int count_cmd_len(char **arr, int pos)
{
    char *name = NULL;
    char *new = NULL;
    int len = 0;

    name = get_func_name(arr[pos]);
    new = get_func_name(arr[pos++]);
    printf("name= %s | new = %s\n", name, new);
    while (my_strcmp(name, new) && arr[pos]) {
        if (new)
            free(new);
        pos++;
        len++;
        new = get_func_name(arr[pos]);
        if (!new)
            new = my_strcpy(new, name);
    }
    printf("len = %i\n", len);
    free(name);
    free(new);
    return len;
}
