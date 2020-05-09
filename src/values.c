/*
** EPITECH PROJECT, 2020
** values.c
** File description:
** convert instruction_values to decimal numbers
*/

#include "corewar.h"

int *values_to_deca(char *param1, char *param2, char *param3, char *param4)
{
    int *values = malloc(sizeof(int) * 4);

    values[0] = my_getnbr(param1);
    values[1] = my_getnbr(param2);
    values[2] = my_getnbr(param3);
    values[3] = my_getnbr(param4);
    return values;
}
