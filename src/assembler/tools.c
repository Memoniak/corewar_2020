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

int get_type(char const *param, char *name)
{
    if (!param)
        return 0;
    if (param[1] == 'r')
        return 1;
    else if (param[1] == DIRECT_CHAR &&
             !my_strcmp(name, "zjmp") && !my_strcmp(name, "ldi") &&
             !my_strcmp(name, "fork") && !my_strcmp(name, "sti") &&
             !my_strcmp(name, "lfork") && !my_strcmp(name, "lldi"))
        return DIR_SIZE;
    return IND_SIZE;
}

int get_binary_type(char const *param)
{
    if (!param) {
        return 0;
    } if (param[1] == 'r') {
        return 1;
    } else if (param[1] == DIRECT_CHAR) {
        return 2;
    }
    return 3;
}

int is_typed(int code)
{
    if (!my_strcmp(OTM(code), "live") &&
        !my_strcmp(OTM(code), "zjmp") &&
        !my_strcmp(OTM(code), "fork") &&
        !my_strcmp(OTM(code), "lfork"))
        return 1;
    return 0;
}
