/*
** EPITECH PROJECT, 2020
** str_to_word_array.c
** File description:
** transform a string to a word array
*/

#include "my.h"

int word_count(char const *str, char c)
{
    int flag = 1;
    int counter = 0;

    for (int move = 0; str[move]; move++) {
        if (flag && str[move] >= 32 && str[move] < 126 && str[move] != c) {
            flag = 0;
            counter++;
        } else if (str[move] == c)
            flag = 1;
    }
    return (counter);
}

int next_len(char const *str, char c)
{
    int move = 0;
    int counter = 0;

    for (; str[move] == c && str[move] && str[move] != '\n'; move++);
    for (; str[move] >= 32 && str[move] < 126 && str[move] != c; move++)
        counter++;
    return (counter);
}

char **word_array(char const *str, char c)
{
    int move = 0;
    int next_length;
    int length = word_count(str, c);
    char **array = malloc(sizeof(char *) * (length + 1));

    if (!array || !str)
        return NULL;
    for (int i = 0; i != length; i++) {
        while (!(str[move] >= 32 && str[move] < 126 && str[move] != c))
            move++;
        next_length = next_len(str + move, c);
        array[i] = malloc(sizeof(char) * (next_length + 1));
        if (!array[i])
            return NULL;
        for (int j = 0; j != next_length; j++, move++)
            array[i][j] = str[move];
        array[i][next_length] = '\0';
    }
    array[length] = NULL;
    return (array);
}

void free_array(char **array)
{
    for (size_t i = 0; array[i]; i++)
        free(array[i]);
    free(array);
}
