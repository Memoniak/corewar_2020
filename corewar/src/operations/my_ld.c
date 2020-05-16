/*
** EPITECH PROJECT, 2020
** ld
** File description:
** instruction ld
*/

#include "corewar.h"

int my_ld(vm_t *vm, process_t *process)
{
    int a = get_param_value(vm, process, 1);
    int b = get_param_value(vm, process, 2);
    int param1 = get_param_type(vm, process, 1);
    int param2 = get_param_type(vm, process, 2);

    if (param1 != DIR_SIZE && param1 != IND_SIZE)
        return -1;
    if (param2 != T_REG)
        return -1;
    process->registre[b] = a;
    if (!a)
        process->carry = 1;
    move_pc(vm, process);
    return 0;
}
