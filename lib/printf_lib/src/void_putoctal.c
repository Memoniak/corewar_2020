/*
** EPITECH PROJECT, 2019
** binary base my_printf
** File description:
** putbin.c
*/

#include "my_printf.h"

void void_putoctal(int output, int nb)
{
    char octa[16] = {'0'};
    int len = (!nb) ? 1 : 0;
    int temp  = 0;

    while (nb)
    {
        temp = nb % 8;
        octa[len] = temp + 48;
        nb /= 8;
        len++;
    }
    while (len--)
        write(output, &octa[len], 1);
}
