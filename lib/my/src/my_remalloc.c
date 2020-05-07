/*
** EPITECH PROJECT, 2020
** my_realloc.c
** File description:
** realloc a string
*/

#include "my.h"

bool my_realloc(char **str, size_t size)
{
    size_t len = my_strlen(*str);
    char *temp = NULL;

    temp = malloc(sizeof(char) * (len + 1));
    if (!temp)
        return false;
    for (size_t i = 0; i != len; i++)
        temp[i] = (*str)[i];
    temp[len] = '\0';
    free(*str);
    *str = malloc(sizeof(char) * size + 1);
    if (!(*str))
        return false;
    for (size_t i = 0; temp[i]; i++)
        (*str)[i] = temp[i];
    (*str)[len] = '\0';
    free(temp);
    return true;
}
