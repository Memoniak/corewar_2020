/*
** EPITECH PROJECT, 2019
** my_strdup
** File description:
** allocates memory and puts string
*/

#include "my.h"

char *my_strndup(char *dest, char *src, int n)
{
    if (!dest)
        dest = malloc(sizeof(char) * (n + 1));
    for (int i = 0; i < n; i++)
        dest[i] = src[i];
    dest[n] = '\0';
    return dest;
}

char *my_strdup_w_no_spaces(char const *src)
{
    char *tab;
    int len;
    int z = 0;

    if (!src)
        return NULL;
    len = my_strlen(src);
    tab = malloc(sizeof(char) * (len + 1));
    for (int i = 0; i < len; i++) {
        if (src[i] != ' ' && src[i] != 9) {
            tab[z] = src[i];
            z++;
        }
    }
    tab[z] = '\0';
    return tab;
}

char *my_strdup_start_no_sp(char const *src, int pos)
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
    for (int i = pos; src[i]; i++) {
        if (src[i] != ' ' && src[i] != 9) {
            tab[z++] = src[i];
        }
    }
    tab[z] = '\0';
    return tab;
}

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
