/*
** EPITECH PROJECT, 2020
** Corewar
** File description:
** check_ params
*/

#include "op.h"
#include <stdio.h>
#include <stdbool.h>

// ! Pol struct

int check_type_arg(char *param);

typedef struct cmd
{
    int code;
    char *p1;
    char *p2;
    char *p3;
    char *p4;
}cmd_t;

//operztion sur les bools
int check_type_ok(int data_cmd , bool t_dir, bool t_ind, bool t_reg)
{
    if (t_dir == true && data_cmd == T_DIR)
        return 0;
    if (t_ind == true && data_cmd == T_IND)
        return 0;
    if (t_reg == true && data_cmd == T_REG)
        return 0;
    return 1;
}

//TODO : Revoir avc simon le ou binaire si d'autres if

int check_arg(int data_cmd , int type)
{
    bool t_dir = false;
    bool t_ind = false;
    bool t_reg = false;

    if (!data_cmd && !type)
        return 0; //ou func check_type_ok
    if (type - T_IND >= 0) {
        t_ind = true;
        type -= T_IND;
    }
    if (type - T_DIR >= 0) {
        t_dir = true;
        type -= T_DIR;
    }
    if (type - T_REG >= 0) {
        t_reg = true;
        type -= T_REG;
    }
    return check_type_ok(data_cmd, t_dir, t_ind, t_reg);
}

int check_line(cmd_t cmd_line, const op_t* op_tab)
{
    int code = cmd_line.code - 1;
    int data[4] = {check_type_arg(cmd_line.p1),
    check_type_arg(cmd_line.p2),
    check_type_arg(cmd_line.p3),
    check_type_arg(cmd_line.p4)};

    for (int i = 0; i < 4; i++) {
        if (check_arg(data[i], op_tab[code].type[i]))
            return -1;
    }
    return 0;
}