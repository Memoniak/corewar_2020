/*
** EPITECH PROJECT, 2019
** my_put_nbr.c
** File description:
** afficher un nombre sur la sortie output
*/

#include "my_printf.h"

void void_put_nbr(int output, int nb)
{
    char deca[16] = {'0'};
    int len = (!nb) ? 1 : 0;
    int temp = 0;
    char sign = (nb < 0) ? '-' : '\0';

    nb = (nb < 0) ? (-nb) : nb;
    while (nb)
    {
        temp = nb % 10;
        deca[len] = temp + 48;
        nb /= 10;
        len++;
    }
    write(output, &sign, 1);
    while (len--)
        write(output, &deca[len], 1);
}
