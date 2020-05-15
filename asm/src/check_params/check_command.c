/*
** EPITECH PROJECT, 2020
** Corewar
** File description:
** check_ params
*/

#include "corewar.h"

int check_type_arg(char *param, funct_t *labels);

int check_type_ok(int data_cmd, bool t_dir, bool t_ind, bool t_reg)
{
    if (t_dir == true && data_cmd == T_DIR)
        return 0;
    if (t_ind == true && data_cmd == T_IND)
        return 0;
    if (t_reg == true && data_cmd == T_REG)
        return 0;
    return 1;
}

int check_arg(int data_cmd, int type)
{
    bool t_type[3] = {false};

    if (!data_cmd && !type)
        return 0;
    if (type - T_IND >= 0)
    {
        t_type[1] = true;
        type -= T_IND;
    }
    if (type - T_DIR >= 0)
    {
        t_type[0] = true;
        type -= T_DIR;
    }
    if (type - T_REG >= 0)
    {
        t_type[2] = true;
        type -= T_REG;
    }
    return check_type_ok(data_cmd, t_type[0], t_type[1], t_type[2]);
}

int check_instructions(cmd_t cmd_line, const op_t *op_tab, funct_t *labels)
{
    int code = cmd_line.code - 1;
    int data[4] = {
        check_type_arg(cmd_line.param1, labels),
        check_type_arg(cmd_line.param2, labels),
        check_type_arg(cmd_line.param3, labels),
        check_type_arg(cmd_line.param4, labels)
    };

    for (int i = 0; i < 4; i++)
    {
        if (check_arg(data[i], op_tab[code].type[i]))
            return 1;
    }
    return 0;
}

int check_errors_instructions(funct_t *labels)
{
    for (int y = 0; y < labels[0].len; y++)
    {
        for (int x = 0; x < labels[y].nb_cmd; x++)
        {
            if (check_instructions(labels[y].commands[x], op_tab, labels))
            {
                my_printf(2, "%sy = %d x = %d%s\n", RED, y, x, DEF);
                return 1;
            }
        }
    }
    return 0;
}
