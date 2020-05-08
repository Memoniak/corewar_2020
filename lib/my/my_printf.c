/*
** EPITECH PROJECT, 2019
** my_printf
** File description:
** somme qui depend de i
*/

#include <stdio.h>
#include <stdarg.h>
#include "my.h"
#include <stdlib.h>

static tab_func tab[11] = {{'s', &my_putstr},
                            {'c', &my_putchar},
                            {'i', &my_put_nbr},
                            {'d', &my_put_nbr},
                            {'S', &my_putstr_o},
                            {'b', &my_put_bin},
                            {'x', &my_put_hexa},
                            {'X', &my_put_maj_hexa},
                            {'p', &my_put_point},
                            {'o', &my_putnbr_o},
                            {'u', &my_putnbr_dec}};

static int my_put_conv(char *str, int count, va_list list )
{
    if (str[count + 1] == 'o')
        return my_put_point(va_arg(list, unsigned int));
    if (str[count + 1] == 'X')
        return my_put_maj_hexa_has(va_arg(list, unsigned int));
    if (str[count + 1] == 'x')
        return my_put_hexa_has(va_arg(list, unsigned int));
}

static int verif_flag(char s)
{
    int pos = 0;

    if (s == '%')
        return -2;
    if (s == '#')
        return -3;
    while (s != tab[pos].type && pos < 11)
        pos++;
    if (pos >= 11)
        return -1;
    else
        return pos;
}

static int except_flags(char *str, int pos, int count)
{
    if (pos == -1)
        count = unknow_flag(str, count);
    if (pos == -2) {
        my_putchar('%');
        count++;
        }
    if (pos == -3) {
        my_put_conv(str, count, list);
        count += 2;
    }
    return count;
}

static int display_flags(int count, char *str)
{
    int pos = 0;

    if ((str[count - 1] == '%')) {
        pos = verif_flag(str[count]);
        if (pos < 0) {
            count += except_flags(str, pos, count);
            return count;
        }
        else {
            tab[pos].ptr(va_arg(list, void *)) - 2;
            count++;
        }
    }
    return count;
}

int my_printf(const char *s, ...)
{
    char *str = my_strdup(s);
    int count = 0;
    int max = my_strlen(str);
    int i = 0;

    va_start(list, s);
    while (count < max) {
        i = display(str + count) + 1;
        count += i;
        count = display_flags(count, str);
    }
    va_end(list);
    free(str);
    return 0;
}
