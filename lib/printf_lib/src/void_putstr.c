/*
** EPITECH PROJECT, 2019
** my_putstr.c
** File description:
** afficher une chaine de caracteres
*/

#include "my_printf.h"

void void_putstr(int output, char const *str)
{
    if (!str)
        return;
    for (int i = 0; str[i]; i++)
        write(output, &str[i], 1);
}
