/*
** EPITECH PROJECT, 2019
** my_strcat.c
** File description:
** concactene deux chaînes
*/

#include <stdio.h>

int my_strlen(char *str);

char *my_strncat(char *dest, char const *str, int n)
{
    int dest_len = my_strlen(dest);
    int i = 0;

    while (i < n && str[i] != '\0') {
        dest[dest_len + i] = str[i];
        i++;
    }
    dest[dest_len + i] = '\0';
    return dest;
}

char *my_strcat(char *dest, char const *str)
{
    int dest_len = my_strlen(dest);
    int i = 0;

    while (str[i] != '\0') {
        dest[dest_len + i] = str[i];
        i++;
    }
    dest[dest_len + i] = '\0';
    return dest;
}
