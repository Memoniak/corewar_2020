/*
** EPITECH PROJECT, 2020
** main.c
** File description:
** main of corewar project
*/

#include "corewar.h"

bool write_params(cmd_t *cmd, op_t op_tab[])
{
    int types   = 0;
    int *values = NULL;

    types = types_to_deca(cmd);
    values = values_to_deca(cmd);
    if (!put_ina_file(&types, &values, cmd, op_tab))
        return false;
    free(values);
    return true;
}
