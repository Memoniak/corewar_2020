/*
** EPITECH PROJECT, 2020
** hexa_str_to_int.c
** File description:
** put an hexa str to int
*/

#include "my.h"

static bool is_alpha(char c)
{
    if (c >= 'A' && c <= 'Z')
        return true;
    if (c >= 'a' && c <= 'z')
        return true;
    return false;
}

int hexachar_to_int(char const *hexa)
{
    int length = my_strlen(hexa);
    int result = 0;

    for (ssize_t i = 0; i != length; i++)
    {
        result *= (i) ? 10 : 1;
        if (is_num(hexa[i]))
        {
            result += hexa[i];
        }
        else if (is_alpha(hexa[i]))
        {
            result += hexa[i] - '0';
        }
    }
    return result;
}
