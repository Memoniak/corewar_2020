/*
** EPITECH PROJECT, 2019
** my_putchar
** File description:
** Prints a char in console
*/

#include "my_printf.h"

void void_putchar(int output, int nb)
{
    char c = nb;

    write(output, &c, 1);
}
