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

bool sim_main(funct_t *funct)
{
    printf("prog_size = %d\n", get_indexes(&funct));
    get_label_value(&funct);
    for (int i = 0; i != 2; i++)
        for (int j = 0; j != funct[i].nb_cmd; j++)
            if (!write_params(&funct[i].commands[j], op_tab))
                return false;
    return true;
}
