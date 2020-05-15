/*
** EPITECH PROJECT, 2020
** my_and
** File description:
** my_and
*/

#include "corewar.h"

int my_and(vm_t *vm, process_t *process)
{
    int param1;
    int param2;
    int param3;

    param1 = get_param_value(vm, process, 1);
    param2 = get_param_value(vm, process, 2);
    param3 = get_param_value(vm, process, 3);
    process->registre[param3] = param1 & param2;
    if (!process->registre[param3])
        process->carry = 1;
    else
        process->carry = 0;
    move_pc(vm, process);
    return 0;
}
