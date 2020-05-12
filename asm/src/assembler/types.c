/*
** EPITECH PROJECT, 2020
** types.c
** File description:
** convert instruction_types to decimal numbers
*/

#include "corewar.h"

int types_to_deca(cmd_t *cmd)
{
    int deca = 0;

    deca += get_binary_type(cmd->param1);
    deca <<= 2;
    deca += get_binary_type(cmd->param2);
    deca <<= 2;
    deca += get_binary_type(cmd->param3);
    deca <<= 2;
    deca += get_binary_type(cmd->param4);
    return deca;
}
