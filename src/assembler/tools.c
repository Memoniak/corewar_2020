/*
** EPITECH PROJECT, 2020
** tools.c
** File description:
** some tool functions
*/

#include "corewar.h"

int power(int nb, int pow)
{
    if (!pow)
        return 1;
    return (nb * power(nb, pow - 1));
}

int get_param_type(char const *param)
{
    if (!param)
        return 0;
    if (param[0] == 'r')
        return 1;
    else if (param[0] == DIRECT_CHAR)
        return 2;
    return 4;
}

int get_binary_type(char const *param)
{
    if (!param) {
        return 0;
    } if (param[0] == 'r') {
        return 1;
    } else if (param[0] == DIRECT_CHAR) {
        return 2;
    }
    return 3;
}
