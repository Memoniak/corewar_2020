/*
** EPITECH PROJECT, 2019
** init_tables
** File description:
** init tables
*/

#include "printf.h"

char *init_buffer(void)
{
    char *buffer = malloc(sizeof(char) * 4048);

    for (int i = 0; i < 4048; i++)
        buffer[i] = '\0';
    return buffer;
}

char *init_cpy(char *buffer)
{
    char *cpy = malloc(sizeof(char) * my_strlen(buffer) + 2);

    for (int i = 0; i < my_strlen(buffer) + 1; i++)
        cpy[i] = '\0';
    return cpy;
}

int *init_padded_num(void)
{
    int *padded_num = malloc(sizeof(int) * 2);

    padded_num[0] = 0;
    padded_num[1] = 0;
    return padded_num;
}
