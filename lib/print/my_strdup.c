/*
** EPITECH PROJECT, 2019
** my_strdup
** File description:
** allocates memory and puts string
*/

#include <stdlib.h>

int my_strlen(char const *str);

int my_putstr(char const *str);

void my_putcher(char c);

char *my_strdup(char const *src)
{
    char *tab;
    int i = 0;
    int len = my_strlen(src);

    tab = malloc(sizeof(char) * (len + 1));
    for (i = 0; i < len; i++) {
        tab[i] = src[i];
    }
    tab[i] = '\0';
    return (tab);
}
