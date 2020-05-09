/*
** EPITECH PROJECT, 2020
** types.c
** File description:
** convert instruction_types to decimal numbers
*/

#include "corewar.h"

static int getta_type(char *param)
{
    if (!param) {
        return 0;
    } if (param[0] == 'r') {
        return 1;
    } else if (param[0] == '%') {
        return 2;
    }
    return 3;
}

int types_to_deca(char *param1, char *param2, char *param3, char *param4)
{
    int deca = 0;

    deca += getta_type(param1);
    deca <<= 2;
    deca += getta_type(param2);
    deca <<= 2;
    deca += getta_type(param3);
    deca <<= 2;
    deca += getta_type(param4);
    return deca;
}
