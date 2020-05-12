/*
** EPITECH PROJECT, 2019
** revstr
** File description:
** reverse str
*/

#include "my.h"

char *my_revstr(char *str)
{
    char char_temp = '\0';
    int counter = 0;

    for (int i = 0; str[i]; i++)
        counter++;
    for (int i = 0; i < (counter / 2); i++) {
        char_temp = str[i];
        str[i] = str[counter - 1 - i];
        str[counter - 1 - i] = char_temp;
    }
    return (str);
}
