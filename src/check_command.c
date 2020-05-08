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

cmd_t cmd_line = {1, "%4", NULL, NULL};

int get_code(int cmd_code, op_t* op_tab)
{
    int i = 0;

    while(cmd_code != op_tab[i].code && i < 16)
        i++;
    if (i >= 16)
        return -1;
    else
        return i;
}

//operztion sur les bools
int check_type_ok(int data_cmd , bool t_dir, bool t_ind, bool t_reg)
{
    if (data_cmd == 0 && t_dir | t_ind | t_reg == 0)
        return 0;
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
    if (type - T_IND >= 0)
        t_ind = true;
    if (type - T_DIR >= 0)
        t_reg = true;
    if (type - T_REG >= 0)
        t_reg = true;
    return check_type_ok(data_cmd, t_dir, t_ind, t_reg);
}

int check_line(cmd_t cmd_line, op_t* op_tab)
{
    int code = get_code(cmd_line.code, op_tab);
    int data[4] = {check_type_arg(cmd_line.p1),
    check_type_arg(cmd_line.p2),
    check_type_arg(cmd_line.p3),
    check_type_arg(cmd_line.p4)};

    if (code < 0)
        return -1;
    for (size_t i = 0; i < 4; i++) {
        if (check_args(data[i], op_tab[code].type[i]))
            return -1;
    }
    return 0;
}

int main(void)
{
    op_t    op_tab[] =
  {
    {"live", 1, {T_DIR}, 1, 10, "alive"},
    {"ld", 2, {T_DIR | T_IND, T_REG}, 2, 5, "load"},
    {"st", 2, {T_REG, T_IND | T_REG}, 3, 5, "store"},
    {"add", 3, {T_REG, T_REG, T_REG}, 4, 10, "addition"},
    {"sub", 3, {T_REG, T_REG, T_REG}, 5, 10, "soustraction"},
    {"and", 3, {T_REG | T_DIR | T_IND, T_REG | T_IND | T_DIR, T_REG}, 6, 6,
     "et (and  r1, r2, r3   r1&r2 -> r3"},
    {"or", 3, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG}, 7, 6,
     "ou  (or   r1, r2, r3   r1 | r2 -> r3"},
    {"xor", 3, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG}, 8, 6,
     "ou (xor  r1, r2, r3   r1^r2 -> r3"},
    {"zjmp", 1, {T_DIR}, 9, 20, "jump if zero"},
    {"ldi", 3, {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG}, 10, 25,
     "load index"},
    {"sti", 3, {T_REG, T_REG | T_DIR | T_IND, T_DIR | T_REG}, 11, 25,
     "store index"},
    {"fork", 1, {T_DIR}, 12, 800, "fork"},
    {"lld", 2, {T_DIR | T_IND, T_REG}, 13, 10, "long load"},
    {"lldi", 3, {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG}, 14, 50,
     "long load index"},
    {"lfork", 1, {T_DIR}, 15, 1000, "long fork"},
    {"aff", 1, {T_REG}, 16, 2, "aff"},
    {0, 0, {0}, 0, 0, 0}
  };

    check_line(cmd_line, op_tab);
    return 0;
}