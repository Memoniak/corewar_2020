/*
** EPITECH PROJECT, 2019
** my_strdup
** File description:
** allocate the memory and cpy la string dinnée en arg
*/

#include <stdlib.h>

int my_strlen(char const *str);

char *my_strdup(char const *src)
{
    int len = my_strlen(src);
    char *str = malloc(sizeof(char) * (len + 1));
    int i = 0;

    if (str == 0)
        return 0;
    while (i <= len) {
        str[i] = src[i];
        i++;
    }
    str[len] = '\0';
    return str;
}
