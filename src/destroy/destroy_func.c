/*
** EPITECH PROJECT, 2020
** destroy_func
** File description:
** destroyes the func struct
*/

#include "corewar.h"

void destroy_func(funct_t *func)
{
    int len;

    if (!func)
        return;
    len = func[0].len;
    for (int i = 0; i < len; i++) {
        if (func[i].name)
            free(func[i].name);
        destroy_command(func[i].commands, func[i].nb_cmd);
    }
    if (func)
        free(func);
}
