/*
** EPITECH PROJECT, 2019
** hexa base my_printf
** File description:
** puthexa.c
*/

#include "my_printf.h"

void void_puthexa(int output, int nb)
{
    char hexa[16] = {'0'};
    int len = (!nb) ? 1 : 0;
    int temp  = 0;

    while (nb)
    {
        temp = nb % 16;
        if (temp < 10)
            hexa[len] = temp + 48;
        else
            hexa[len] = temp + 87;
        nb /= 16;
        len++;
    }
    while (len--)
        write(output, &hexa[len], 1);
}
