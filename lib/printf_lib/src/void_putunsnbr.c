/*
** EPITECH PROJECT, 2019
** my_putunsnbr.c
** File description:
** put_unsigned_number
*/

#include "my_printf.h"

void void_putunsnbr(int output, unsigned int nb)
{
    char deca[32] = {'0'};
    int len = (!nb) ? 1 : 0;
    int temp = 0;

    while (nb)
    {
        temp = nb % 10;
        deca[len] = temp + 48;
        nb /= 10;
        len++;
    }
    while (len--)
        write(output, &deca[len], 1);
}
