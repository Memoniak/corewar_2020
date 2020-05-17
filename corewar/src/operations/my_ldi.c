/*
** EPITECH PROJECT, 2020
** ldi
** File description:
** instruction ldi
*/

#include "corewar.h"

int my_ldi(vm_t *vm, process_t *process)
{
    int a = get_param_value(vm, process, 1);
    int b = get_param_value(vm, process, 2);
    int c = get_param_value(vm, process, 3);
    int param1 = get_param_type(vm, process, 1);
    int param2 = get_param_type(vm, process, 2);
    int param3 = get_param_type(vm, process, 3);
    int sum = (a + b) % IDX_MOD;

    if (param1 != IND_SIZE && param1 != T_REG)
        return -1;
    if(param2 != IND_SIZE)
        return -1;
    if(param3 != T_REG)
        return -1;
    process->registre[c] = vm->mem[ABS((process->pc + sum)) % MEM_SIZE];
    if (!vm->mem[ABS((process->pc + sum)) % MEM_SIZE])
        process->carry = 1;
    move_pc(vm, process);
    return 0;
}
