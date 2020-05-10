/*
** EPITECH PROJECT, 2020
** destroy_all
** File description:
** destroyes all strucs
*/

#include "corewar.h"

void destroy_all(funct_t *func, champion_header_t *champ)
{
    if (champ->comment)
        free(champ->comment);
    if (champ->name)
        free(champ->name);
    destroy_func(func);
}
