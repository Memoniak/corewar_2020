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

    if(param1 != T_REG || param1 != T_DIR || param1 != T_IND)
        return -1;
    if(param2 != T_IND || param2 != T_DIR)
        return -1;
    if(param3 != T_REG)
        return -1;
    process->registre[c] = a + b;
    (a + b) == 0 ? process->carry = 1 : 0;
    move_pc(vm, process);
    return 0;
}
