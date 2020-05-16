/*
** EPITECH PROJECT, 2020
** my_zjmp.c
** File description:
** jumps to an address
*/

#include "corewar.h"

int my_zjmp(vm_t *vm, process_t *process)
{
    UNSD int param;

    if (process->carry) {
        param = get_param_value(vm, process, 1);
        process->pc += (param % IDX_MOD);
    } else {
        move_pc(vm, process);
    }
    return 0;
}
