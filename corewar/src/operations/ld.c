/*
** EPITECH PROJECT, 2020
** ld
** File description:
** instruction ld
*/

#include "corewar.h"

int ld(vm_t *vm, process_t *process)
{
    int a = get_param_value(vm, process, 1);
    int b = get_param_value(vm, process, 2);
    int param1 = get_param_type(vm, process, 1);
    int param2 = get_param_type(vm, process, 2);

    if (param1 != T_DIR || param1 != T_IND && param2 != T_REG)
        return -1;
    process->registre[b] = a; // ou b -1 ??
    a == 0 ? process->carry = 1 : 0;
    move_pc(vm, process);
    my_printf(2, "INSTRUCTION LD");
    return 0;
}
