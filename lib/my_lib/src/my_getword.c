/*
** EPITECH PROJECT, 2020
** my_getword.c
** File description:
** get the next word
*/

#include "my.h"

int next_word(char const *str)
{
    int count = 0;

    for (int i = 0; str[i] != ' ' && str[i] != '\n' && str[i]; i++)
        count++;
    return count;
}

char *my_getword(char const *str)
{
    int len = next_word(str);
    char *buff = malloc(sizeof(char) * (len + 1));
    int i = 0;

    for (; str[i] == ' ' && str[i]; i++);
    for (; i != len; i++)
        buff[i] = str[i];
    buff[len] = '\0';
    return buff;
}
