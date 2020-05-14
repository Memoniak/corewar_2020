/*
** EPITECH PROJECT, 2020
** get_bytes.c
** File description:
** get n bytes from buf
*/

#include "corewar.h"

int read_nbytes(char **buf, int nb, int code)
{
    int           result = **buf;
    unsigned char live = **buf;

    if (!nb)
        return 0;
    for (ssize_t i = 1; i != nb; i++)
    {
        if (!my_strcmp(OTM(code - 1), "live"))
        {
            result <<= 8;
            result += *(*buf + i);
            result %= power(2, 8);
        } else
        {
            live <<= 8;
            live += *(*buf + i);
            live %= power(2, 8 * (nb - 1));
        }
    }
    if (!my_strcmp(OTM(code - 1), "live"))
        return result;
    return live;
}

int get_nbytes(char **buf, int nb)
{
    int result = **buf;

    for (ssize_t i = 1; i != nb; i++)
    {
        result <<= 8;
        result += *(*buf + i) + power(2, 8);
    }
    return result;
}
