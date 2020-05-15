/*
** EPITECH PROJECT, 2020
** parser dots
** File description:
** parses the path variable
*/

#include "arr.h"

int my_strlen(char *str);

char *my_strdup(char *str);

static char *set_memory(char *tab, int len)
{
    for (int i = 0; i < len; i++)
        tab[i] = '\0';
    return tab;
}

static char **init_table(char **tab, char *str, char seperator)
{
    int nb_words = 1;

    for (int i = 0; str[i]; i++)
        if (str[i] == seperator && i != 0 && str[i + 1] != '\0')
            nb_words++;
    tab = malloc(sizeof(char *) * (nb_words + 1));
    for (int i = 0; i < nb_words; i++) {
        tab[i] = malloc(sizeof(char) * (my_strlen(str) + 1));
        tab[i] = set_memory(tab[i], (my_strlen(str) + 1));
    }
    tab[nb_words] = NULL;
    return tab;
}

static char **copy_into_tab(char **res, char *str, char seperator)
{
    int z = 0;
    int j = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == seperator && i != 0 && str[i + 1] != '\0') {
            if (res[z][j - 1] == '\n')
                res[z][j - 1] = '\0';
            res[z++][j] = '\0';
            j = 0;
            i++;
        }
        res[z][j++] = str[i];
    }
    if (res[z][j - 1] == '\n')
        res[z][j - 1] = '\0';
    res[z][j] = '\0';
    return res;
}

char **my_parser(char *str, char seperator)
{
    char **res = NULL;

    res = init_table(res, str, seperator);
    if (res == NULL)
        return NULL;
    res = copy_into_tab(res, str, seperator);
    if (res[0][0] == '\0') {
        res[0] = my_strdup(str);
        res[0][my_strlen(str)] = '\0';
    }
    return res;
}
