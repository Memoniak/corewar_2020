/*
** EPITECH PROJECT, 2019
** my_memset.c
** File description:
** my_memset
*/

#include "my.h"

void *my_memset(void *ptr, int value, size_t count)
{
    char *ptr_2 = (char *)&ptr;

    for (size_t i = 0; i < count; i++)
        *(ptr_2 + i) = value;
    return ptr;
}