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
        printf("NAME = %s | POS = %i | %s\n", name, pos, arr[pos]);
        name = get_func_name(arr[pos]);
    }
    printf("LEN -%i\n", len);
    free(name);
    return len;
}

int count_cmd_len(char **arr, int pos)
{
    char *name = NULL;
    char *new = NULL;
    int len = 0;

    name = get_func_name(arr[pos]);
    new = get_func_name(arr[pos]);
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
