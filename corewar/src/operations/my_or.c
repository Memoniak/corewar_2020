/*
** EPITECH PROJECT, 2020
** or
** File description:
** or VM
*/

#include "corewar.h"

int my_or(vm_t *vm, process_t *proc)
{
    int a = get_param_value(vm, proc, 1);
    int b = get_param_value(vm, proc, 2);
    int c = get_param_value(vm, proc, 3);
    int type_a = get_param_type(vm, proc, 1);
    int type_b = get_param_type(vm, proc, 2);
    int type_c = get_param_type(vm, proc, 3);

    if (type_a == 0 || type_b == 0 || type_c != T_REG)
        return -1;
    proc->registre[c] = (a | b);
    (a | b) == 0 ? proc->carry = 1 : 0;
    move_pc(vm, proc);
    return 0;
}
