/*
** EPITECH PROJECT, 2020
** get_file_content.c
** File description:
** put a file content in a string
*/

#include "my.h"

char *put_getline(char *str, char const *buff, int buff_len)
{
    size_t len = my_strlen(str);

    if (!my_remalloc(&str, len + buff_len + 1))
        return NULL;
    for (size_t i = 0; buff[i]; i++)
        str[i + len] = buff[i];
    str[buff_len + len] = '\0';
    return str;
}

bool get_file(char **str, char const *filepath)
{
    FILE *fd = NULL;
    char *buff = NULL;
    size_t seed = 0;
    int len = 0;

    fd = fopen(filepath, "r");
    if (!fd)
        return false;
    while (len != -1) {
        len = getline(&buff, &seed, fd);
        if (len != -1)
            *str = put_getline(*str, buff, len);
    }
    if (!(*str))
        return false;
    free(buff);
    fclose(fd);
    return true;
}
