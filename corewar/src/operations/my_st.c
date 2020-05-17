/*
** EPITECH PROJECT, 2020
** or
** File description:
** or VM
*/

#include "corewar.h"

int my_st(vm_t *vm, process_t *proc)
{
    int a = get_param_value(vm, proc, 1);
    int b = get_param_value(vm, proc, 2);
    int type_a = get_param_type(vm, proc, 1);
    int type_b = get_param_type(vm, proc, 2);
    int reg = 0;

    if (type_a != T_REG || (type_b != T_REG && type_b != IND_SIZE))
        return -1;
    reg = proc->registre[b];
    if (type_b == T_REG)
        proc->registre[a] = reg;
    else
        proc->registre[a] = b;
    (a == 0) ? proc->carry = 1 : 0;
    move_pc(vm, proc);
    return 0;
}
