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

    if (process->carry) {
        param = get_param_value(vm, process, 2);
        process->pc -= 5;
        //process->pc + (param % IDX_MOD);
    } else {
        move_pc(vm, process);
    }
    //my_printf(2, SREDN, "Executing zjmp operation");
    return 0;
}
