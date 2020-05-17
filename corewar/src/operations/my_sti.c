/*
** EPITECH PROJECT, 2020
** my_sti
** File description:
** sti operation
*/

#include "corewar.h"

static int check_adr(process_t *ps, int value)
{
    value = (ABS(ps->pc + (value % IDX_MOD))) % MEM_SIZE;
    return value;
}

static void check_reg_type(vm_t *vm, process_t *process, int nb, int *value)
{
    if (get_param_type(vm, process, nb) == T_REG)
        *value = process->registre[get_param_value(vm, process, nb)];
    else
        *value = get_param_value(vm, process, nb);
}

int my_sti(vm_t *vm, process_t *process)
{
    int param1 = get_param_value(vm, process, 1);;
    int adr = 0;
    int value2 = 0;
    int value3 = 0;
    int tmp_pc = get_next_pc(vm, process) % MEM_SIZE;

    check_reg_type(vm, process, 2, &value2);
    check_reg_type(vm, process, 3, &value3);
    adr = value2 + value3;
    for (int i = 0; i < 4; i++)
        vm->mem[check_adr(process, adr + i)] =
        (process->registre[param1] >> (8 * (3 - i))) & 0xFF;
    (!adr) ? process->carry = 1 : 0;
    process->pc = check_adr(process, tmp_pc);
    return 0;
}