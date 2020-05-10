/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** check_label_char
*/

#include "corewar.h"

int check_label_chars(char *name)
{
    int len_chars = my_strlen(LABEL_CHARS);
    int x = 0;

    for (int i = 0; name[i]; i++) {
        x = 0;
        for (; x < len_chars; x++) {
            if (name[i] == LABEL_CHARS[x])
                break;
        }
        if (x == len_chars)
            return 1;
    }
    return 0;
}
