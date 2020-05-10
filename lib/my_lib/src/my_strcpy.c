/*
** EPITECH PROJECT, 2020
** my_strcpy.c
** File description:
** copy a string into a dest
*/

#include "my.h"

char *my_strcpy(char *dest, char *str)
{
    int len = my_strlen(str);

    dest = malloc(sizeof(char) * (len + 1));
    for (int i = 0; i != len; i++)
        dest[i] = str[i];
    dest[len] = '\0';
    return dest;
}

char **my_arrcpy(char **dest, char **arr)
{
    int length = my_arrlen(arr);
    int len = my_strlen(arr[0]);

    dest = malloc(sizeof(char *) * (length + 1));
    for (size_t i = 0; arr[i]; i++) {
        dest[i] = malloc(sizeof(char) * (len + 1));
        for (size_t j = 0; arr[i][j]; j++)
            dest[i][j] = arr[i][j];
        dest[i][len] = '\0';
    }
    dest[length] = NULL;
    return dest;
}
