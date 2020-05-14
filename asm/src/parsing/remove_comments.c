/*
** EPITECH PROJECT, 2020
** remove_comments
** File description:
** remove_comments
*/

#include "corewar.h"

char *remove_commented(char *line, int pos)
{
    int len = my_strlen(line);
    char *new = malloc(sizeof(char) * (len + 1));
    int i = 0;

    for (; i < pos - 1; i++) {
        new[i] = line[i];
    }
    new[i] = '\0';
    free(line);
    return new;
}

char **remove_empty_lines(char **file_arr, int len)
{
    char **new = malloc(sizeof(char *) * (len + 1));
    int z = 0;

    for (int i = 0; i < len; i++) {
        if (check_line(file_arr[i])) {
            new[z] = my_strdup(file_arr[i]);
            z++;
        }
    }
    new[z] = NULL;
    free_array(file_arr);
    return new;
}

char **remove_comments(char **file_arr, int len)
{
    for (int i = 0; file_arr[i]; i++) {
        for (int j = 0; file_arr[i][j]; j++) {
            if (file_arr[i][j] == COMMENT_CHAR) {
                file_arr[i] = remove_commented(file_arr[i], j);
            }
        }
    }
    file_arr = remove_empty_lines(file_arr, len);
    return file_arr;
}
