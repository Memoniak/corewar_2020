/*
** EPITECH PROJECT, 2020
** get_double_array_len
** File description:
** gets the length of a double array
*/

#include "arr.h"

size_t get_dbl_arr_len(char const **arr)
{
    size_t len = 0;

    if (!arr)
        return 0;
    while (arr[len++]);
    return len - 1;
}
