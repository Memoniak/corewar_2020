/*
** EPITECH PROJECT, 2020
** my_strcat.c
** File description:
** concats 2 params
*/

#include "my.h"

char *my_strcat(char *dest, char const *str)
{
    int len1 = my_strlen(dest);
    int len2 = my_strlen(str);
    char *temp = NULL;

    temp = my_strcpy(temp, dest);
    my_remalloc(&dest, len1 + len2 + 1);
    for (int i = 0; i != len1 + len2 + 1; i++) {
        if (i < len1)
            dest[i] = temp[i];
        else if (i < len1 + len2)
            dest[i] = str[i - len1];
        else
            dest[i] = '\0';
    }
    free(temp);
    return (dest);
}
