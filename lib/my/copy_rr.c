/*
** EPITECH PROJECT, 2020
** copy rr
** File description:
** copy rr
*/

#include <stdlib.h>

char *my_strdup(char const *str);

char **copy_rr(char **tab)
{
    char **res;
    int len = 0;

    for (int i = 0; tab[i]; i++)
        len++;
    res = malloc(sizeof(char *) * (len + 1));
    res[len] = NULL;
    for (int i = 0; i < len; i++) {
        res[i] = my_strdup(tab[i]);
    }
    return res;
}
