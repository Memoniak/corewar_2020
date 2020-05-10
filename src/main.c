/*
** EPITECH PROJECT, 2020
** main.c
** File description:
** main of corewar project
*/

#include "corewar.h"

static bool write_params(cmd_t *cmd)
{
    int types   = 0;
    int *values = NULL;

    types = types_to_deca(cmd);
    values = values_to_deca(cmd);
    if (!put_ina_file(&types, &values, cmd))
        return false;
    free(values);
    return true;
}

int main(void)
{
    cmd_t cmd = {0, 11, "r2", "%-23", "%34", NULL};

    if (!write_params(&cmd))
        return EXIT_FAILURE;
    return EXIT_SUCCESS;
}
