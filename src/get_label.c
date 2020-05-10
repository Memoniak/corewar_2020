/*
** EPITECH PROJECT, 2020
** get_label.c
** File description:
** get label
*/

#include "asm.h"
#include <stdio.h>

static char *my_revstr(char *str)
{
    int len = my_strlen(str);
    char temp = 0;

    for (int i = 0; i < len / 2; i++) {
        temp = str[i];
        str[i] = str[len - 1 - i];
        str[len - 1 - i] = temp;
    }
    return str;
}

static int count_num(int nb)
{
    int counter = 0;
    int pow = 1;

    for (int i = 1; pow < 11; i *= 10, pow++)
        if (nb >= i)
            counter++;
    return (counter);
}

static char *intchar(int nb)
{
    int len = count_num(nb) + 1;
    char *str = malloc(sizeof(char) * len);
    int i = 0;
    char neg = '\0';

    for (int i = 0; i != len; i++)
        str[i] = '\0';
    if (nb < 0) {
        neg = '-';
        nb *= -1;
    } else if (!nb)
        return ("0");
    while (nb) {
        str[i] = nb % 10 + '0';
        nb = nb / 10;
        i++;
    }
    str[i] = neg;
    str[i + 1] = '\0';
    return (my_revstr(str));
}

char *replace_label(char *param, int nb)
{
    char *value = intchar(nb);
    char *result = malloc(sizeof(char) * (count_num(nb) + 2));

    if (!param)
        return NULL;
    result[0] = '%'; //DIRECT_CHAR
    result = my_strcat(result, value);
    free(value);
    return result;
}
