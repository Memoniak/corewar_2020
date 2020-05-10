/*
** EPITECH PROJECT, 2019
** flags
** File description:
** special flags
*/

#include <stdlib.h>
#include "printf.h"

int *get_padded_nb(char *str, int pos, args_t const *fct)
{
    int *padding_num = init_padded_num();
    int tens = 1;
    int i = pos + 1;

    while (str[i] == '0' || str[i] == ' ') {
        i++;
    }
    for (int j = 0; j < 10; j++) {
        if (str[i] == fct[j].arg[0]) {
            padding_num[0] = i - pos;
            return padding_num;
        } else if (str[i] <= '9' && str[i] >= '0') {
            padding_num[1] = padding_num[1] * tens + (str[i] - '0');
            tens *= 10;
            i++;
        }
    }
    padding_num[0] = i - pos;
    return padding_num;
}

char *add_padding(char *buffer, char *cpy, int padding, int old_len)
{
    int dif_len = my_strlen(cpy) - old_len;
    int new_len = my_strlen(buffer);
    int i = 0;

    if (old_len == 0)
        padding -= dif_len + 2;
    for (i = old_len; i < padding + old_len; i++)
        buffer[i] = '0';
    dif_len = my_strlen(cpy) - old_len;
    i -= dif_len;
    for (int j = old_len; j < new_len; j++) {
        buffer[i] = cpy[j];
        i++;
    }
    free(cpy);
    return buffer;
}

char *flag_true(char *buffer, int flag, char *s, int i)
{
    if (flag == 1) {
        if (s[i + 1] == 'x')
            my_strcat(buffer, "0x");
        else if (s[i + 1] == 'X')
            my_strcat(buffer, "0X");
        if (s[i + 1] == 'o')
            my_strcat(buffer, "0");
        return buffer;
    }
    return buffer;
}

int check_flags(char s, int pos, char *str, char *buffer)
{
    if (s == '#')
        return 1;
    else
        return 0;
}
