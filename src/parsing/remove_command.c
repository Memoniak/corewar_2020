/*
** EPITECH PROJECT, 2020
** remove_command
** File description:
** removes a command in the lsit
*/

#include "corewar.h"

cmd_t *remove_command(cmd_t *command, int pos, int len)
{
    cmd_t *new = malloc(sizeof(cmd_t) * (len + 1));
    int z = 0;

    for (int i = 0; i < len; i++) {
        if (i == pos && i + 1 != len)
            i++;
        printf("i = %i\n", i);
        new[z].code = command[i].code;
        new[z].index = command[i].index;
        new[z].param1 = my_strdup(command[i].param1);
        new[z].param2 = my_strdup(command[i].param2);
        new[z].param3 = my_strdup(command[i].param3);
        new[z].param4 = my_strdup(command[i].param4);
        z++;
    }
    destroy_command(command, len);
    return new;
}
