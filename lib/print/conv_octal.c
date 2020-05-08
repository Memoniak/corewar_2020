/*
** EPITECH PROJECT, 2019
** octal
** File description:
** conv_octal
*/

#include "printf.h"
#include <stdlib.h>

int get_power_of_eight(unsigned int nb)
{
    unsigned int power_of_eight = 1;

    while (power_of_eight < nb) {
        power_of_eight *= 8;
    }
    if (power_of_eight > nb) {
        power_of_eight /= 8;
    }
    return power_of_eight;
}

int get_power_len(int power_of_eight)
{
    int len = 0;

    while (power_of_eight / 8 >= 1) {
        len++;
        power_of_eight /= 8;
    }
    return len;
}

char *init_result(int len)
{
    char *result = malloc(sizeof(char) * len + 2);

    for (int i = 0; i < len + 2; i++)
        result[i] = '\0';
    return result;
}

char *conv_octal(unsigned int x)
{
    char *octal = malloc(sizeof(char) * 4);
    char *result;
    unsigned int power_of_eight = get_power_of_eight(x);
    int remainder = 0;
    int len = get_power_len(power_of_eight);

    result = init_result(len);
    if (len == 0) {
        result[0] = '0';
        return result;
    }
    for (int i = 0; i < len; i++) {
        result[i] = (x / power_of_eight) + '0';
        x %= power_of_eight;
        power_of_eight /= 8;
    }
    return result;
}
