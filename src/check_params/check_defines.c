/*
** EPITECH PROJECT, 2020
** Corewar
** File description:
** check_defines
*/

#include "corewar.h"

int check_label_name(char *name, funct_t *labels)
{
    int i = 0;
    if (check_label_chars(name))
        return 1;
    while (i < labels[0].len)
    {
        if(my_strcmp(labels[i].name, name))
            break;
        i++;
    }
    if (i == labels[0].len)
        return 1;
    return 0;
}

int check_value_dir(char *value, UNSD funct_t *labels)
{
    if (!is_num(value[0]))
        return 1;
    for (size_t i = 1; value[i]; i++) {
        if (is_num(value[i]) != 1)
            return 1;
    }
    return 0;
}

int check_value_ind(char *value, UNSD funct_t *labels)
{
    for (size_t i = 0; value[i]; i++) {
        if (is_num(value[i]) != 1)
            return 1;
    }
    return 0;
}
