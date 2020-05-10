/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** get_word_pos_arr
*/

#include "arr.h"

int my_strncmp(char const *s1, char const *s2, int n);
int my_strlen(char const *str);

size_t get_pos_word_in_str(char const  *word, char const *str)
{
    size_t pos = 0;

    if (!word || !str)
        return -1;
    while (str[pos]) {
        if (my_strncmp(word, str + pos, my_strlen(word))) {
            return pos;
        }
        pos++;
    }
    return -1;
}
