/*
** EPITECH PROJECT, 2019
** str_to_word_array.c
** File description:
** str_to_word_array.c
*/

#include "my.h"

int destroy_word_array(char **tab)
{
    for (int i = 0; tab[i] != NULL; i++)
        free(tab[i]);
    free(tab);
    return 0;
}

int my_show_array(char **tab)
{
    my_printf("[");
    for (size_t i = 0; tab[i] ; i++)
        my_printf("[%s]", tab[i]);
    my_printf("]\n");
}