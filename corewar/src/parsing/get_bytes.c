/*
** EPITECH PROJECT, 2020
** get_bytes.c
** File description:
** get n bytes from buf
*/

#include "corewar.h"

int get_next_nbytes(char **buf, int nb, int code)
{
    int result = **buf;
    int typed = (code != 9 && code != 12 && code != 15) ? 0 : 1;

    for (ssize_t i = 1; i < nb; i++)
    {
        result <<= 8;
        result += *(*buf + i);
    }
    if (typed)
        result %= power(2, 8);
    return result % IDX_MOD;
}

int get_nbytes(char **buf, int nb)
{
    int result = **buf;

    for (ssize_t i = 1; i != nb; i++)
    {
        result <<= 8;
        if (*(*buf + i) < 0)
            result += *(*buf + i) + power(2, 8);
        else
            result += *(*buf + i);
    }
    return result;
}
