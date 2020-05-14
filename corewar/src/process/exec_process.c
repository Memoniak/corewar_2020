/*
** EPITECH PROJECT, 2020
** exec_process
** File description:
** executes a champ process
*/

#include "corewar.h"

static void exec_all_process(UNSD vm_t *vm, UNSD champ_t *champ)
{
    process_t *tmp = vm->all_process;
    operation_t *last_op;

    while (tmp) {
        while (tmp->operation_to_do) {
            last_op = tmp->operation_to_do;
            tmp->operation_to_do = tmp->operation_to_do->next;
            last_op->operation(vm, champ);
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
    process_t *head;

    tmp = vm->all_process;
    head = tmp;
    while (tmp) {
        if (tmp->wait_cycles == 0) {
            tmp->live = 1;
            if (!tmp->operation_to_do)
                get_opcode(vm, tmp, champ);
        } else {
            tmp->wait_cycles--;
            my_printf(2, "%sWait Cycles:%i%s\n", LBLUE, tmp->wait_cycles, DEF);
        }
        tmp = tmp->next;
    }
    //exec_all_process(vm, champ);
}
