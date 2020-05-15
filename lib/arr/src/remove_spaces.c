/*
** EPITECH PROJECT, 2020
** remove spaces
** File description:
** removes the spaces of a string
*/

#include "arr.h"

int my_strlen(char const *str);

char *my_memset(int len, char *str);

char *remove_tabs(char *str)
{
    int z = 0;
    char *tmp = malloc(sizeof(char) * (my_strlen(str) + 1));

    tmp = my_memset(my_strlen(str), tmp);
    for (int i = 0; str[i]; i++) {
        if (str[i] == '\\' && str[i + 1] == 't') {
            tmp[z++] = ' ';
            i += 2;
        }
        tmp[z] = str[i];
        z++;
    }
    tmp[z] = '\0';
    return tmp;

}

char *remove_spaces(char *str)
{
    int z = 0;
    char *tmp = malloc(sizeof(char) * (my_strlen(str) + 1));

    tmp = my_memset(my_strlen(str), tmp);
    for (int i = 0; str[i]; i++) {
        if (str[i] != ' ') {
            tmp[z] = str[i];
            z++;
        }
    }
    tmp[z] = '\0';
    free(str);
    return tmp;
}

char *remove_first_spaces(char *str)
{
    int z = 0;
    char *tmp = malloc(sizeof(char) * (my_strlen(str) + 1));
    int i = 0;

    if (!str || str[0] == '\n' || str[0] == '\0') {
        free(tmp);
        return "\0";
    }
    tmp = my_memset(my_strlen(str), tmp);
    while (str[i] == ' ' || str[i] == 9 || str[i] == '\n')
        i++;
    for (; str[i]; i++) {
        tmp[z] = str[i];
        z++;
    }
    tmp[z] = '\0';
    free(str);
    return tmp;
}
