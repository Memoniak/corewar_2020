/*
** EPITECH PROJECT, 2019
** converts to hexa
** File description:
** hexa
*/

#include <stdlib.h>
#include "printf.h"

char check_high_nb_c(int number)
{
    char hexa_base[6] = {'A', 'B', 'C', 'D', 'E', 'F'};

    return (hexa_base[number - 10]);
}

char *create_hexa_string_c(int *numbers, char *result, int len)
{
    int i = 0;

    while (i < len) {
        if (numbers[i] > 9) {
            result[i] = check_high_nb_c(numbers[i]);
        } else {
            result[i] = numbers[i] + '0';
        }
        i++;
    }
    result[i] = '\0';
    return result;
}

char *conv_hexa_c(int nb)
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
    result = create_hexa_string_c(remainder, result, i);
    return my_revstr(result);
}
