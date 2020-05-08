/*
** EPITECH PROJECT, 2019
** my_put_nbr
** File description:
** show number
*/

#include <stdlib.h>

void my_putchar(char c);

char *my_strcat(char *dest, char const *src);

char static *get_this_number(int len, long one_num, int power_number)
{
    long value_of_number = one_num;
    int temp_value = 0;
    int i = 0;
    char *str = malloc(sizeof(char) * len + 2);

    for (int a = 0; a < len; a++)
        one_num = one_num / 10;
    str[0] = one_num + '0';
    for (i = 1; len > 0; i++) {
        one_num = value_of_number % power_number;
        if (one_num >= 10) {
            for (int z = 1; z < len; z++)
            one_num = one_num / 10;
        }
        str[i] = one_num + '0';
        power_number = power_number / 10;
        len--;
    }
    str[i] = '\0';
    return str;
}

int static power_of_length(int length, long n)
{
    int result = 10;

    for (int i = 1; i < length; i++)
        result = result * 10;
    return result;
}

int static get_length(long n)
{
    int length = 0;
    long length_finder = n;

    while (length_finder > 9) {
        length_finder = length_finder / 10;
        length++;
    }
    return length;
}

char *my_put_nbr(long nb)
{
    long new_nb = nb;
    int len = 0;
    int power_of_len = 0;
    int neg = 0;
    char *str;

    if ((int)nb < 0) {
        neg = 1;
        new_nb = new_nb * -1;
    }
    len = get_length(new_nb);
    power_of_len = power_of_length(len, new_nb);
    str = malloc(sizeof(char) * len + 2);
    for (int i = 0; i < len + 2; i++)
        str[i] = '\0';
    if (neg == 1)
        str[0] = '-';
    return my_strcat(str, get_this_number(len, new_nb, power_of_len));
}
