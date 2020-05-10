/*
** EPITECH PROJECT, 2019
** my_strdup
** File description:
** allocates memory and puts string
*/

#include "my.h"

char *my_strdup_start(char const *src, int pos)
{
    int len = 0;
    char *tab;
    int z = 0;
    int tmp = pos;

    if (!src)
        return NULL;
    while (src[pos++])
        len++;
    pos = tmp;
    tab = malloc(sizeof(char) * len + 1);
    for (int i = pos; src[i]; i++)
        tab[z++] = src[i];
    tab[z] = '\0';
    return tab;
}

char *my_strdup(char const *src)
{
    char *tab;
    int i = 0;
    int len;

    if (!src)
        return NULL;
    len = my_strlen(src);
    tab = malloc(sizeof(char) * (len + 1));
    for (i = 0; i < len; i++) {
        tab[i] = src[i];
    }
    tab[i] = '\0';
    return (tab);
}
