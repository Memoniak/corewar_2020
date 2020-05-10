/*
** EPITECH PROJECT, 2019
** put_nbr_bin
** File description:
** converts to binary
*/

#include <stdlib.h>

char *my_revstr(char *str);

int my_putstr(char const *str);

int get_nbr_len(int nb);

char *to_binary(int nb)
{
    int remain = 0;
    int len = get_nbr_len(nb);
    int i = 0;
    char *result = malloc(sizeof(char) * len + 1);

    while (nb != 0) {
        remain = nb % 2;
        nb /= 2;
        result[i] = remain + '0';
        i++;
    }
    return my_revstr(result);
}
