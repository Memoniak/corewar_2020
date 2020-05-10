/*
** EPITECH PROJECT, 2020
** my_strcat.c
** File description:
** concats 2 params
*/

#include "my.h"

int custom_strlen(char *str, char limit)
{
    int len = 0;

    while (str[len] != limit && str[len] != '\0')
        len++;
    return len;
}
