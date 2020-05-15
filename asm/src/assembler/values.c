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

    for (ssize_t i = 0; i != 4; i++)
        values[i] = 0;
    if (!(my_strlen(cmd->param1) >= 2 && cmd->param1[0] == DIRECT_CHAR &&
        cmd->param1[1] == LABEL_CHAR))
        values[0] = my_getnbr(cmd->param1);
    if (!(my_strlen(cmd->param2) == 2 && cmd->param2[0] == DIRECT_CHAR &&
        cmd->param2[1] == LABEL_CHAR))
        values[1] = my_getnbr(cmd->param2);
    if (!(my_strlen(cmd->param3) == 2 && cmd->param3[0] == DIRECT_CHAR &&
        cmd->param3[1] == LABEL_CHAR))
        values[2] = my_getnbr(cmd->param3);
    if (!(my_strlen(cmd->param4) == 2 && cmd->param4[0] == DIRECT_CHAR &&
        cmd->param4[1] == LABEL_CHAR))
        values[3] = my_getnbr(cmd->param4);
    return values;
}
