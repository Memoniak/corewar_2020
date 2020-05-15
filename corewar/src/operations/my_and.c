/*
** EPITECH PROJECT, 2020
** and
** File description:
** and VM
*/

#include "corewar.h"

int my_and(vm_t *vm, process_t *proc)
{
    int a = get_param_value(vm, proc, 1);
    int b = get_param_value(vm, proc, 2);
    int c = get_param_value(vm, proc, 3);
    int type_a = get_param_type(vm, proc, 1);
    int type_b = get_param_type(vm, proc, 2);
    int type_c = get_param_type(vm, proc, 3);

    if (type_a == 0 || type_b == 0 || type_c != T_REG)
        return -1;
    proc->registre[c] = a & b;
    (a & b) == 0 ? proc->carry = 1 : 0;
    move_pc(vm, proc);
    return 0;
}

// int my_and(vm_t *vm, process_t *process)
// {
//     int param1;
//     int param2;
//     int param3;

//     param1 = get_param_value(vm, process, 1);
//     param2 = get_param_value(vm, process, 2);
//     param3 = get_param_value(vm, process, 3);
//     process->registre[param3] = param1 & param2;
//     if (!process->registre[param3])
//         process->carry = 1;
//     else
//         process->carry = 0;
//     move_pc(vm, process);
//     return 0;
// }
