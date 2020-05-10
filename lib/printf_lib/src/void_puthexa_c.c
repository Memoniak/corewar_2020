/*
** EPITECH PROJECT, 2019
** MAJ hexa base my_printf
** File description:
** putHEXA.c
*/

#include "my_printf.h"

void void_puthexa_c(int output, int nb)
{
    flags_t flags = {0, 0, '\0', 0, malloc(sizeof(int) + 1)};

    while (nb >= 16) {
        flags.quot = nb / 16;
        flags.rest = nb % 16;
        if (flags.rest <= 9)
            flags.c = flags.rest + 48;
        else
            flags.c = flags.rest + 55;
        flags.str[flags.i] = flags.c;
        nb = flags.quot;
        flags.i++;
    }
    if (nb <= 9)
        flags.c = nb + 48;
    else
        flags.c = nb + 55;
    flags.str[flags.i] = flags.c;
    write(output, my_revstr(flags.str), my_strlen(flags.str));
    free(flags.str);
}
