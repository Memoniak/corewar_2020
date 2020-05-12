/*
** EPITECH PROJECT, 2019
** int_to_str eval_expr
** File description:
** int_to_str.c
*/

#include "my.h"

int count_num(int nb)
{
    int counter = 0;

    for (int i = 1; i < 1000000001; i *= 10)
        if (nb >= i)
            counter++;
    return (counter);
}

char *intchar(int nb)
{
    int len = count_num((nb > 0) ? nb : -nb);
    char *str = malloc(sizeof(char) * (len + 2));
    char neg = '\0';

    if (nb < 0) {
        neg = '-';
        nb *= -1;
    } else if (!nb)
        return ("0");
    for (int i = 0; nb; i++) {
        str[i] = nb % 10 + '0';
        nb = nb / 10;
    }
    str[len] = neg;
    str[len + 1] = '\0';
    return (my_revstr(str));
}
