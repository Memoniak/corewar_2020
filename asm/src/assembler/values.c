/*
** EPITECH PROJECT, 2020
** values.c
** File description:
** convert instruction_values to decimal numbers
*/

#include "corewar.h"

int *values_to_deca(cmd_t *cmd)
{
    int *values = malloc(sizeof(int) * 4);

    values[0] = my_getnbr(cmd->param1);
    values[1] = my_getnbr(cmd->param2);
    values[2] = my_getnbr(cmd->param3);
    values[3] = my_getnbr(cmd->param4);
    return values;
}
