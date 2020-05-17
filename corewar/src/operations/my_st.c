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

    if (type_a != T_REG || (type_b != T_REG && type_b != IND_SIZE))
        return -1;
    if (type_b == T_REG)
        proc->registre[b] = proc->registre[a];
    else {
        for (int i = 0; i < 4; i++)
            vm->mem[MEME((proc->pc + ((b + i) % IDX_MOD)))] =
            (proc->registre[a] >> (8 * (3 - i))) & 0xFF;
    }
    move_pc(vm, proc);
    return 0;
}
