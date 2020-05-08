/*
** EPITECH PROJECT, 2019
** my_strcat
** File description:
** concatenates two strings
*/

#include <stdlib.h>

int my_strlen(char const *str);


char *my_strcat_p(char *dest, char const *src)
{
    int i = 0;
    int len = my_strlen(dest);
    int src_len = my_strlen(src);
    char *result = malloc(sizeof(char) * (len + src_len + 1));
    int z = 0;

    while (i < len) {
        result[i] = dest[i];
        i++;
    }
    while (z < src_len) {
        result[i] = src[z];
        i++;
        z++;
    }
    result[len + src_len] = '\0';
    return result;
}
