/*
** EPITECH PROJECT, 2020
** my_sti
** File description:
** sti operation
*/

#include "corewar.h"

int my_sti(vm_t *vm, process_t *process)
{
    int param1;
    int param2;
    int param3;
    int adr;

    param1 = get_param_value(vm, process, 1);
    param2 = get_param_value(vm, process, 2);
    param3 = get_param_value(vm, process, 3);
    adr = process->pc + (param2 + param3);
    vm->mem[adr] = (process->registre[param1] >> 24) & 0xFF;
    vm->mem[adr + 1] = (process->registre[param1] >> 16) & 0xFF;
    vm->mem[adr + 2] = (process->registre[param1] >> 8) & 0xFF;
    vm->mem[adr + 3] = process->registre[param1] & 0xFF;
    move_pc(vm, process);
//    my_printf(2, SREDN, "Executing STI operation");
    return 0;
}
