/*
** EPITECH PROJECT, 2020
** fill_file
** File description:
** fill a file with getline
*/

#include "file.h"

size_t get_file_len(char const *filepath)
{
    FILE *fd = fopen(filepath, "r");
    char *buff = NULL;
    size_t first = 0;
    size_t len = 0;
    int res = 0;

    for (; res != -1; len++) {
        res = getline(&buff, &first, fd);
    }
    if (buff)
        free(buff);
    if (fd)
        fclose(fd);
    if (first <= 0 || len == 0)
        return 0;
    return --len;
}

char **get_file_ar(char const *filepath)
{
    FILE *fd = fopen(filepath, "r");
    size_t size = 0;
    int res = 1;
    char **arr_file = NULL;
    int len = get_file_len(filepath);

    if (len <= 0 || !fd)
        return NULL;
    arr_file = malloc(sizeof(char *) * (len + 1));
    arr_file[len] = NULL;
    for (int i = 0; i < len; i++) {
        arr_file[i] = NULL;
        res = getline(&arr_file[i], &size, fd);
        arr_file[i][res] = '\0';
        if (res == -1 || !arr_file[i])
            break;
    }
    fclose(fd);
    return arr_file;
}
