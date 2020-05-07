/*
** EPITECH PROJECT, 2020
** base_to_hexa.c
** File description:
** convert base number to hexadecimal number
*/

#include "corewar.h"

static const int HEXA_BASE = 16;
static const int DECA_BASE = 10;
static const char HEXA_CHAR[] = "0123456789abcdef";

char *deca_to_hexa(int deca)
{
    int value = (deca < 0) ? (-deca) : deca;
    char sign = (deca < 0) ? '-' : '\0';
    char *str = malloc(sizeof(char) * ((value / HEXA_BASE) + 6));
    int index = 0;

    while (value > 0) {
        str[index++] = HEXA_CHAR[value % HEXA_BASE];
        value /= HEXA_BASE;
    }
    if (index < 2)
        str[index++] = '0';
    str[index++] = 'x';
    str[index++] = '0';
    str[index++] = sign;
    str[index] = '\0';
    return (my_revstr(str));
}

int bin_to_deca(int bin)
{
    int deca = 0;
    int base = 1;
    int temp = 0;

    while (bin > 0) {
        temp = bin % DECA_BASE;
        deca += temp * base;
        bin /= DECA_BASE ;
        base *= 2;
    }
    return deca;
}
