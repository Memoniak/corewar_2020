/*
** EPITECH PROJECT, 2020
** init_cmd_struct
** File description:
** inits the cmd struct
*/

#include "corewar.h"

void init_cmd_struct(cmd_t *commands, int len)
{
    for (int i = 0; i < len; i++) {
        commands[i].code = 0;
        commands[i].index = 0;
        commands[i].param1 = NULL;
        commands[i].param2 = NULL;
        commands[i].param3 = NULL;
        commands[i].param4 = NULL;
    }
}
