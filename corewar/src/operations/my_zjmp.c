/*
** EPITECH PROJECT, 2020
** my_zjmp.c
** File description:
** jumps to an address
*/

#include "corewar.h"

int my_zjmp(vm_t *vm, process_t *process)
{
    int param;
    int type1 = get_param_type(vm, process, 1);

    if (type1 != T_DIR)
        return -1;
    if (process->carry) {
        param = get_param_value(vm, process, 1);
        process->pc = ABS(((process->pc + param % IDX_MOD) % MEM_SIZE));
    } else {
        move_pc(vm, process);
    }
    return 0;
}
