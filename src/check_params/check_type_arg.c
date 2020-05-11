/*
** EPITECH PROJECT, 2020
** COREWAR
** File description:
** check_type_arg
*/

#include "corewar.h"

static int check_t_reg(char *param)
{
    int nb_reg;
    if(param[0] != 'r')
        return 1;
    for(int i = 1; param[i]; i++) {
        if (is_num(param[i]) !=  1)
            return 1;
    }
    nb_reg = my_getnbr(param + 1);
    if (nb_reg > REG_NUMBER)
        return 1;
    return 0;
}

static int check_t_dir(char *param, funct_t *labels)
{
    if (param[0] != DIRECT_CHAR)
        return 1;
    if (param[1] != LABEL_CHAR)
        return check_value_dir(param + 1, labels);
    else
        return check_label_name(param + 2, labels);
    return 0;
}

static int check_t_ind(char *param, funct_t *labels)
{
    if(param[0] != LABEL_CHAR)
        return check_value_ind(param, labels);
    return check_label_name(param + 1, labels);
    return 0;
}

int check_type_arg(char *param, funct_t *labels)
{
    if (!param)
        return 0;
    if (!check_t_reg(param + 1))
        return T_REG;
    if (!check_t_dir(param + 1, labels))
        return T_DIR;
    if (!check_t_ind(param + 1, labels))
        return T_IND;
    return 0;
}