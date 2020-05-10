/*
** EPITECH PROJECT, 2020
** process.c
** File description:
** run the current process
*/

#include "my.h"

bool my_strcmp(char const *first, char const *second)
{
    if (my_strlen(first) != my_strlen(second))
        return false;
    for (int i = 0; first[i]; i++)
        if (first[i] != second[i])
            return false;
    return true;
}
