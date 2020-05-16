/*
** EPITECH PROJECT, 2020
** lld
** File description:
** instruction lld
*/

#include "corewar.h"

int my_lld(vm_t *vm, process_t *process)
{
    UNSD int a = get_param_value(vm, process, 1);
    UNSD int b = get_param_value(vm, process, 2);
    int param1 = get_param_type(vm, process, 1);
    int param2 = get_param_type(vm, process, 2);

    if (param1 != T_DIR || param1 != T_IND)
        return -1;
    if (param2 != T_REG)
        return -1;
    return 0;
}
