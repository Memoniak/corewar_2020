/*
** EPITECH PROJECT, 2020
** main.c
** File description:
** main of corewar project
*/

#include "corewar.h"

static bool write_params(cmd_t *cmd, op_t op_tab[])
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

int main(void)
{
    cmd_t cmd1[] = {
        {0, 11, "r1", "%:hi", "%1", NULL}
    };
    cmd_t cmd2[] = {
        {0, 1, "%234", NULL, NULL, NULL},
        {0, 2, "%0", "r3", NULL, NULL},
        {0, 9, "%:hi", NULL, NULL, NULL}
    };
    funct_t funct[] = {
        {0, NULL, 1, cmd1},
        {0, "hi", 3, cmd2}
    };

    printf("prog_size = %d\n", get_indexes(&funct));
    get_label_value(&funct);
    for (int i = 0; i != 2; i++)
        for (int j = 0; j != funct[i].nb_cmd; j++)
            if (!write_params(&funct[i].commands[j], op_tab))
                return EXIT_FAILURE;
    return EXIT_SUCCESS;
}
