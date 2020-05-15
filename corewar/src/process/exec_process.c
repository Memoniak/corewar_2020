/*
** EPITECH PROJECT, 2020
** exec_process
** File description:
** executes a champ process
*/

#include "corewar.h"

static void exec_all_process(vm_t *vm)
{
    process_t *tmp = vm->all_process;
    operation_t *last_op;

    while (tmp) {
        while (tmp->operation_to_do) {
            last_op = tmp->operation_to_do;
            tmp->operation_to_do = tmp->operation_to_do->next;
            last_op->operation(vm, tmp);
            last_op->operation = NULL;
            free(last_op);
        }
        tmp = tmp->next;
    }
    return;
}

void take_care_process(vm_t *vm, champ_t *champ)
{
    process_t *tmp;

    tmp = vm->all_process;
    while (tmp) {
        if (tmp->wait_cycles == 0) {
//            my_printf(2, STEALN, "\n━━━━━━━━━━━\n");
//            my_printf(2, "%sGetting new operation for cycle pc = %d%s",
//            LRED, tmp->pc, DEF);
//            my_printf(2, STEALN, "\n━━━━━━━━━━━\n");
            if (!tmp->operation_to_do)
                get_opcode(vm, tmp, champ);
        } else {
            tmp->wait_cycles--;
        }
        tmp = tmp->next;
    }
    exec_all_process(vm);
}
