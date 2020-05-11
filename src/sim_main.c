/*
** EPITECH PROJECT, 2020
** main.c
** File description:
** main of corewar project
*/

#include "corewar.h"

bool write_params(cmd_t *cmd, op_t op_tab[], int fd)
{
    int types   = 0;
    int *values = NULL;

    types = types_to_deca(cmd);
    values = values_to_deca(cmd);
    if (!put_ina_file(&types, &values, cmd, fd))
        return false;
    free(values);
    return true;
}

bool sim_main(funct_t *funct, char *file_name, champion_header_t *champ)
{
    champ->prog_size = get_indexes(&funct);
    write_header(champ);
    get_label_value(&funct);
    for (int i = 0; i != 2; i++)
        for (int j = 0; j != funct[i].nb_cmd; j++)
            if (!write_params(&funct[i].commands[j], op_tab, champ->fd))
                return false;
    return true;
}
