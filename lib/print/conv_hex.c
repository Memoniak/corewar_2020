/*
** EPITECH PROJECT, 2019
** converts to hexa
** File description:
** hexa
*/

#include <stdlib.h>
#include "printf.h"

char check_high_nb(int number)
{
    char hexa_base[6] = {'a', 'b', 'c', 'd', 'e', 'f'};

    return (hexa_base[number - 10]);
}

char *create_hexa_string(int *numbers, char *result, int len)
{
    int i = 0;

    while (i < len) {
        if (numbers[i] > 9) {
            result[i] = check_high_nb(numbers[i]);
        } else {
            result[i] = numbers[i] + '0';
        }
        i++;
    }
    result[i] = '\0';
    return result;
}

char *conv_hexa(int nb)
{
    int len = get_nbr_len(nb);
    int remainder[len + 1];
    int i = 0;
    char *result = malloc(sizeof(char) * len + 1);

    while (nb != 0) {
        remainder[i] = nb % 16;
        nb /= 16;
        i++;
    }
    result = create_hexa_string(remainder, result, i);
    return my_revstr(result);
}
