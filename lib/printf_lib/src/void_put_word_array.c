/*
** EPITECH PROJECT, 2020
** void_put_word_array.c
** File description:
** print a word array
*/

#include "my_printf.h"

void void_put_word_array(int output, char **array)
{
    for (int i = 0; array[i]; i++) {
        write(output, array[i], my_strlen(array[i]));
        write(output, "\n", 1);
    }
}
