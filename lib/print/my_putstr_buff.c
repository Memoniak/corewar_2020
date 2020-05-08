/*
** EPITECH PROJECT, 2019
** my_putstr
** File description:
** display string one by one
*/

#include <stdlib.h>

void my_putchar(char c);

int my_strlen(char const *str);

char *my_putstr_b(char const *str)
{
    char *result = malloc(sizeof(char) * my_strlen(str) + 2);
    int i = 0;

    for (int i = 0; i < my_strlen(str) + 2; i++)
        result[i] = '\0';
    for (i = 0; i < my_strlen(str); i++) {
        result[i] = str[i];
    }
    result[i + 1] = '\0';
    return result;
}
