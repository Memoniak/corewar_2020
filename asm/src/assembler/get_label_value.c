/*
** EPITECH PROJECT, 2020
** get_label_value.c
** File description:
** get the label value according to the indexes
*/

#include "corewar.h"

static char *replace_label(char *param, int nb)
{
    char *value = intchar(nb);
    char *result = malloc(sizeof(char) * (count_num(nb) + 2));

    if (!param)
        return NULL;
    result[0] = DIRECT_CHAR;
    result[1] = '\0';
    result = my_strcat(result, value);
    free(value);
    return result;
}

static int get_value(char *param, funct_t **funct, cmd_t cmd)
{
    for (int i = 0; i != (*funct)[0].len; i++) {
        if (my_strcmp((*funct)[i].name, param + 2))
            return ((*funct)[i].index - cmd.index);
    }
    return 0;
}

static bool check_label(char **param, funct_t **funct, cmd_t cmd)
{
    int value = 0;

    if (!(*param))
        return false;
    if ((*param)[0] == DIRECT_CHAR &&
        (*param)[1] == LABEL_CHAR)
        value = get_value((*param), funct, cmd);
    if (value)
        (*param) = replace_label((*param) + 2, value);
    return true;
}

void get_label_value(funct_t **funct)
{
    for (int i = 0; i != (*funct)[0].len; i++) {
        for (int j = 0; j != (*funct)[i].nb_cmd; j++) {
            check_label(&FC(i, j).param1, funct, FC(i, j));
            check_label(&FC(i, j).param2, funct, FC(i, j));
            check_label(&FC(i, j).param3, funct, FC(i, j));
            check_label(&FC(i, j).param4, funct, FC(i, j));
        }
    }
}
