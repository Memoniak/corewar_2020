/*
** EPITECH PROJECT, 2019
** str_to_word_array.c
** File description:
** str_to_word_array.c
*/

#include "my.h"
#include <stdlib.h>
#include <stdio.h>

static int count_nb_words(char *str, char sep)
{
    int i = 0;
    int count = 1;

    if (str[0] == '\0')
        return 0;

    while (str[i] != '\0')
    {
        if (str[i] == '\t' || str[i] == sep)
            count++;
        while (str[i] == '\t' || str[i] == sep)
            i++;
        i++;
    }
    return count;
}

static char *fill_arr(char *str, int *i, char sep)
{
    int j = 0;
    char *array = malloc(sizeof(char) * (my_strlen(str) + 1));

    if (array == NULL)
        return NULL;
    for (; str[*i] == sep || str[*i] == '\t'; (*i)++);
    for (; str[*i] != sep && str[*i] != '\t' && str[*i] != '\0'; (*i)++, j++)
        array[j] = str[*i];
    if (array[j - 1] == '\n')
        array[j - 1] = '\0';
    array[j] = '\0';
    return array;
}

char **my_str_to_word_array(char *str, char sep)
{
    int nb_words = count_nb_words(str, sep);
    char **array = malloc(sizeof(char *) * (nb_words + 1));
    int i = 0;
    int nb = 0;

    array[nb_words] = NULL;
    while (str[i] != '\0') {
        array[nb] = fill_arr(str, &i, sep);
        if (array[nb] == NULL)
            return NULL;
        nb++;
    }
    if (array[nb - 1][0] == '\0' ||
        array[nb - 1][0] == '\t' || array[nb - 1][0] == sep)
        array[nb - 1] = NULL;
    return array;
}
