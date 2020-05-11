/*
** EPITECH PROJECT, 2020
** destroy_all
** File description:
** destroyes all strucs
*/

#include "corewar.h"

void destroy_all(funct_t *func, champion_header_t *champ)
{
    if (champ->file_name)
        free(champ->file_name);
    destroy_func(func);
}
