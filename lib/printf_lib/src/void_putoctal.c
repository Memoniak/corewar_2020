/*
** EPITECH PROJECT, 2019
** binary base my_printf
** File description:
** putbin.c
*/

#include "my_printf.h"

void void_putoctal(int output, unsigned int nb)
{
    unsflags_t flags = {0, 0, '\0', 0, malloc(sizeof(unsigned int) + 1)};

    while (nb >= 8) {
        flags.quot = nb / 8;
        flags.rest = nb % 8;
        flags.str[flags.i] = flags.rest + 48;
        nb = flags.quot;
        flags.i++;
    }
    flags.rest = nb % 8;
    flags.str[flags.i] = flags.rest + 48;
    write(output, my_revstr(flags.str), my_strlen(flags.str));
    free(flags.str);
}
