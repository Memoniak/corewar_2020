/*
** EPITECH PROJECT, 2019
** sum_arg my_printf
** File description:
** sum_stdarg.c
*/

#include "my_printf.h"

static print_t print_tab[13] = {
    {'c', &void_putchar}, {'i', &void_put_nbr},
    {'s', &void_putstr}, {'d', &void_put_nbr},
    {'x', &void_puthexa}, {'X', &void_puthexa_c},
    {'b', &void_putbin}, {'S', &void_putstr},
    {'u', &void_putunsnbr}, {'o', &void_putoctal},
    {'a', &void_put_word_array}, {'A', &void_putword_array},
    {'@', &void_putstr}
};

void my_printf(int output, char *str, ...)
{
    va_list ap;

    va_start(ap, str);
    for (ssize_t i = 0; i != my_strlen(str); i++)
        if (str[i] != '%')
            write(output, &(str[i]), 1);
        else if (str[i + 1] == '%') {
            i++;
            write(output, "%", 1);
            if (str[i + 1] == '\0' || str[i + 1] == '\n')
                return;
        } else {
            i++;
            for (int j = 0; j != REALSIZE(print_tab); j++)
                if (print_tab[j].car == str[i])
                    print_tab[j].ptr(output, va_arg(ap, void *));
        }
    va_end(ap);
}
