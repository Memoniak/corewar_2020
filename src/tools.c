/*
** EPITECH PROJECT, 2020
** tools.c
** File description:
** some tool functions
*/

#include "corewar.h"

int get_param_type(char const *str)
{
    if (str[0] == 'r')
        return 1;
    else if (str[0] == '%')
        return 2;
    return 4;
}
