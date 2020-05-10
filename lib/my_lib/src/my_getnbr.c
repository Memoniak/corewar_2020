/*
** EPITECH PROJECT, 2019
** my_getnbr.c
** File description:
** get the next first number occurence in a string
*/

#include "my.h"

static const long LIMIT_INT_NEG = -2147283648;
static const long LIMIT_INT_POS = 2147283647;

int my_getnbr(char const *str)
{
    long result = 0;
    int sign = 1;
    int flag = 0;

    if (!str)
        return 0;
    for (int i = 0; str[i]; i++) {
        if (str[i] == '-' && flag == 0)
            sign *= -1;
        if (flag == 1 && (str[i] < '0' || str[i] > '9'))
            flag = 2;
        if (str[i] >= '0' && str[i] <= '9' && flag < 2) {
            result = result * 10 + str[i] - '0';
            flag = 1;
        }
    }
    if (result >= LIMIT_INT_NEG && result <= LIMIT_INT_POS)
        return (sign * result);
    return 0;
}

int my_power(int nb, int pow)
{
    if (pow <= 0)
        return 1;
    return (nb * my_power(nb, pow - 1));
}

float my_getflt(char *str)
{
    float result = 0;
    int integer = 0;
    int decimal = 0;
    int divide = 0;

    integer = my_getnbr(str);
    while (*str != '.')
        str++;
    decimal = my_getnbr(str);
    divide = count_num(decimal);
    result = integer + decimal / (my_power(10, divide));
    return result;
}
