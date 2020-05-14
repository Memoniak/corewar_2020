/*
** EPITECH PROJECT, 2020
** exec_process
** File description:
** executes a champ process
*/

#include "corewar.h"

void take_care_process(vm_t *vm)
{
    process_t *tmp;

    tmp = vm->all_process;
    while (tmp) {
        if (tmp->wait_cycles == 0) {
            if (!tmp->operation_to_do)
                get_opcode(vm, tmp);
            else
                exec_process(vm, tmp);
        } else
            tmp->wait_cycles--;
        tmp = tmp->next;
    }
}

void exec_process()
{
    return;
}
