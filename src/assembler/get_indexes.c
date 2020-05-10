/*
** EPITECH PROJECT, 2020
** get_indexes.c
** File description:
** get and put indexes in the cmd structs
*/

#include "corewar.h"

static void replace_label(UNSD char **param, UNSD int value)
{
    return;
}

static void check_label(char *param, int value)
{
    if (!param)
        return;
    else if (param[0] == DIRECT_CHAR &&
             param[1] == LABEL_CHAR)
        replace_label(&param, value);
}

static void get_param_info(cmd_t *cmd, int *value)
{
    check_label(cmd->param1, *value);
    check_label(cmd->param2, *value);
    check_label(cmd->param3, *value);
    check_label(cmd->param4, *value);
    *value += 1 + is_typed(cmd->code - 1);
    *value += get_type(cmd->param1, OTM(cmd->code - 1));
    *value += get_type(cmd->param2, OTM(cmd->code - 1));
    *value += get_type(cmd->param3, OTM(cmd->code - 1));
    *value += get_type(cmd->param4, OTM(cmd->code - 1));
}

int get_indexes(funct_t funct[][2])
{
    int value = 0;

    for (int i = 0; i != 2; i++) {
        (*funct)[i].index = value;
        for (int j = 0; j != (*funct)[i].nb_cmd; j++) {
            (*funct)[i].commands[j].index = value;
            get_param_info(&(*funct)[i].commands[j], &value);
        }
    }
    return value;
}
