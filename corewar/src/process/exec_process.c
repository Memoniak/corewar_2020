/*
** EPITECH PROJECT, 2020
** exec_process
** File description:
** executes a champ process
*/

#include "corewar.h"

/*
static void exec_all_process(vm_t *vm)
{
    process_t *tmp = vm->all_process;
    operation_t *last_op;

    while (tmp) {
        while (tmp->operation_to_do) {
            last_op = tmp->operation_to_do;
            tmp->operation_to_do = tmp->operation_to_do->next;
            //printf("executing operation of code == %i\n", last_op->code);
            if (last_op->operation(vm, tmp) == -1)
                tmp->pc = (tmp->pc + 1) % MEM_SIZE;
            last_op->operation = NULL;
            free(last_op);
        }
        tmp = tmp->next;
    }
}
*/

static void exec_c_process(vm_t *vm, process_t *process)
{
    process_t *tmp = process;
    operation_t *last_op;

    while (tmp->operation_to_do) {
        last_op = tmp->operation_to_do;
        tmp->operation_to_do = tmp->operation_to_do->next;
        //printf("executing operation of code == %i\n", last_op->code);
        if (last_op->operation(vm, tmp) == -1)
            tmp->pc = (tmp->pc + 1) % MEM_SIZE;
        last_op->operation = NULL;
        free(last_op);
    }
}

void take_care_process(vm_t *vm, champ_t *champ)
{
    process_t *tmp;

    tmp = vm->all_process;
    while (tmp) {
        if (tmp->wait_cycles == 0) {
            if (!tmp->operation_to_do)
                get_opcode(vm, tmp, champ);
            else {
                exec_c_process(vm, tmp);
                break;
            }
        } else {
            tmp->wait_cycles--;
        }
        tmp = tmp->next;
    }
}
