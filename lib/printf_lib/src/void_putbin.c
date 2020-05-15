/*
** EPITECH PROJECT, 2019
** binary base my_printf
** File description:
** putbin.c
*/

#include "my_printf.h"

void void_putbin(int output, int nb)
{
    char bina[16] = {'0'};
    int len = (!nb) ? 1 : 0;
    int temp  = 0;

    while(nb)
    {
        temp = nb % 2;
        bina[len] = temp + 48;
        nb /= 2;
        len++;
    }
    while (len--)
        write(output, &bina[len], 1);
}
