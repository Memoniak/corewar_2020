/*
** EPITECH PROJECT, 2020
** get_mem_info.c
** File description:
** get params and pc
*/

#include "corewar.h"

int get_param_type(vm_t *vm, process_t *proc, int nb)
{
    int code = vm->mem[proc->pc];
    int params[4] = {0};
    int temp = 0;

    if (!is_typed(code - 1))
    {
        params[0] = check_direct(OTM(code - 1));
        return params[nb - 1];
    }
    for (ssize_t i = 0; i != 4; i++)
    {
        temp = vm->mem[proc->pc + 1] >> (2 * i);
        temp &= 0x03;
        if (temp == 2)
            params[3 - i] = check_direct(OTM(code - 1));
        else
            params[3 - i] = temp;
    }
    return params[nb - 1];
}

static int move(vm_t *vm, process_t *proc, int nb)
{
    int temp = 0;

    for (ssize_t i = 1; i != nb; i++)
    {
        temp += get_param_type(vm, proc, i);
        my_printf(2, "%d ", temp);
    }
    return (proc->pc + is_typed(vm->mem[proc->pc] - 1) + temp);
}

int get_param_value(vm_t *vm, process_t *proc, int nb)
{
    int code = vm->mem[proc->pc];
    int byte = get_param_type(vm, proc, nb);
    char *next = vm->mem + move(vm, proc, nb) + 1;
    int result = 0;

    result = read_nbytes(&next, byte, code);
    return result;
}

int get_next_pc(vm_t *vm, process_t *proc)
{
    int result = 0;
    int code = vm->mem[proc->pc];

    for (ssize_t i = 1; i != 5; i++)
    {
        result += get_param_type(vm, proc, i);
    }
    if (!is_typed(code - 1))
        return result + 1;
    return result + 2;
}
