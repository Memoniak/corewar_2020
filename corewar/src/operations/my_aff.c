/*
** EPITECH PROJECT, 2020
** my_aff.c
** File description:
** aff VM
*/

#include "corewar.h"

int my_aff(vm_t *vm, process_t *proc)
{
    int val = get_param_value(vm, proc, 1);
    int typ = get_param_type(vm, proc, 1);

    if (typ != T_REG)
        return -1;
    (!val) ? proc->carry = 1 : 0;
    my_printf(2, SDLBLACKN, "AFF = ", val);
    move_pc(vm, proc);
    return 0;
}
