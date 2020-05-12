/*
** EPITECH PROJECT, 2019
** octal base my_printf
** File description:
** putoct.c
*/

#include "my_printf.h"

void disp_octal(char *dest, char c, int flag)
{
    int nb = c;

    if (flag == 0) {
        dest[2] = (nb % 10) + '0';
        if ((nb - nb % 10) >= 0)
            dest[1] = ((nb - nb % 10) / 10) + '0';
        if ((nb - (nb % 100) * 10 - nb % 10) >= 0)
            dest[0] = ((nb - (nb % 100) * 10 - nb % 10) / 10) + '0';
        write(1, "\\", 1);
        write(1, dest, 4);
    }
    else
        write(1, "\\127", 4);
}

void void_putoct(int output, char *str)
{
    char octal[4] = {'0', '0', '0', '\0'};

    for (int i = 0; i != my_strlen(str); i++) {
        if (str[i] < 32)
            disp_octal(octal, str[i], 0);
        else if (str[i] == 127)
            disp_octal(octal, str[i], 1);
        write(output, &str[i], 1);
    }
}
