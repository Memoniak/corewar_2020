/*
** EPITECH PROJECT, 2020
** types_to_hexa.c
** File description:
** convert instruction_types to hexadecimal numbers
*/

#include "corewar.h"

static char *get_type(char *param, char *binary)
{
    char *str = NULL;

    if (!param) {
        str = my_strcat(binary, "00");
        return str;
    } if (param[0] == 'r') {
        str = my_strcat(binary, "01");
    } else if (param[0] == '%') {
        str = my_strcat(binary, "10");
    } else
        str = my_strcat(binary, "11");
    return str;
}

char *types_to_hexa(char *param1, char *param2, char *param3, char *param4)
{
    char *binary = NULL;
    int   deca   = 0;
    char *hexa   = NULL;

    binary = get_type(param1, binary);
    binary = get_type(param2, binary);
    binary = get_type(param3, binary);
    binary = get_type(param4, binary);
    if (binary) {
        deca = bin_to_deca(my_getnbr(binary));
        hexa = deca_to_hexa(deca);
        free(binary);
    }
    return hexa;
}
