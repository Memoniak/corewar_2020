/*
** EPITECH PROJECT, 2020
** values_to_hexa.c
** File description:
** convert instruction_values to hexadecimal numbers
*/

#include "corewar.h"

static const char HEXA_NULL[] = "0x00 ";

static char *put_hexa_on_type(char *param, char *hexa)
{
    char *str = NULL;

    if (param[0] == 'r') {
        return hexa;
    } else if (param[0] == '%') {
        str = my_strcat(hexa, HEXA_NULL);
        str = my_strcat(str, HEXA_NULL);
        str = my_strcat(str, HEXA_NULL);
    } else
        str = my_strcat(hexa, HEXA_NULL);
    return str;
}

static char *get_value(char *param, char *hexa)
{
    char *str  = NULL;
    int   deca = my_getnbr(param);
    char *temp = deca_to_hexa(deca);

    if (deca > 0) {
        if (hexa)
            str = my_strcat(hexa, " ");
        str = put_hexa_on_type(param, str);
        str = my_strcat(str, temp);
    }
    free(temp);
    return str;
}

char *values_to_hexa(char *param1, char *param2, char *param3, char *param4)
{
    char *hexa = NULL;

    if (param1) {
        hexa = get_value(param1, hexa);
    } if (param2) {
        hexa = get_value(param2, hexa);
    } if (param3) {
        hexa = get_value(param3, hexa);
    } if (param4) {
        hexa = get_value(param4, hexa);
    }
    return hexa;
}
