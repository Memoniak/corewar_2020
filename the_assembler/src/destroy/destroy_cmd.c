/*
** EPITECH PROJECT, 2020
** destroy_cmd
** File description:
** destroys the command struct
*/

#include "corewar.h"

void destroy_command(cmd_t *command, int len)
{
    for (int i = 0; i < len; i++) {
        if (command[i].param1)
            free(command[i].param1);
        if (command[i].param2)
            free(command[i].param2);
        if (command[i].param3)
            free(command[i].param3);
        if (command[i].param4)
            free(command[i].param4);
    }
    free(command);
}
