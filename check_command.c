/*
** EPITECH PROJECT, 2020
** Corewar
** File description:
** check_ params
*/

// ! Pol struct 

#include "op.h"
#include <stdio.h>

int check_type_arg(char *param);

typedef struct cmd
{
    int code;
    char *p1;
    char *p2;
    char *p3;
    char *p4;
}cmd_t;

cmd_t cmd_line = {7, "r1", "r2", "r3"};

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

int check_args(char *cmd_line)
{

}

int check_line(cmd_t cmd_line, op_t* op_tab)
{
    int code = get_code(cmd_line.code, op_tab);

    if (code < 0)
        return -1;
    
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

    int ret = get_code(cmd_line.code, op_tab);
    return ret;
}