/*
** EPITECH PROJECT, 2019
** show_funcs
** File description:
** shows funcs
*/

#include <stdlib.h>
#include "printf.h"

char *to_octal(int x)
{
    char *octal = malloc(sizeof(char) * 4);
    int power_height[3];
    int character = x;

    power_height[0] = 64;
    power_height[1] = 8;
    power_height[2] = 1;
    for (int i = 0; i < 3; i++) {
        octal[i] = (character / power_height[i]) + '0';
        character %= power_height[i];
    }
    octal[3] = '\0';
    return octal;
}

char *non_p_s(char const *str)
{
    char *result = malloc(sizeof(char) * my_strlen(str) + 1);
    int tmp = 0;
    int i = 0;

    for (i = 0; i < my_strlen(str); i++) {
        if (str[i] < 32 || str[i] > 127) {
            tmp = i;
            result[tmp] = '\\';
            result = my_strcat(result, to_octal(str[i]));
            tmp = my_strlen(result);
        } else {
            result[tmp] = str[i];
            tmp++;
        }
    }
    result[i] = '\0';
    return result;
}
