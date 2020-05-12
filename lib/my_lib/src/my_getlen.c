/*
** EPITECH PROJECT, 2020
** my_getlen.c
** File description:
** get the length of a char tab
*/

#include "my.h"

int my_strlen(char const *str)
{
    int len = 0;

    if (!str)
        return 0;
    while (str[len])
        len++;
    return len;
}

int my_arrlen(char *array[])
{
    int len = 0;

    if (!array)
        return 0;
    while (array[len])
        len++;
    return len;
}
