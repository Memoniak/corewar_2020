/*
** EPITECH PROJECT, 2019
** my_params_to_list.c
** File description:
** structure liste chaînée
*/

#include "my.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

linked_list_t *my_params_to_list(linked_list_t *list, int ac, char **av)
{
    int i = 0;
    while (ac > 1)
    {
        insertion_lk(list, av[ac - 1]);
        ac--;
    }
    return list;
}
