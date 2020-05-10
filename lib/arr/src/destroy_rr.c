/*
** EPITECH PROJECT, 2020
** destroy_rr
** File description:
** destroys double array
*/

#include "arr.h"

void destroy_rr(char **arr)
{
    if (!arr)
        return;
    for (int i = 0; arr[i]; i++)
        free(arr[i]);
    free(arr);
}
