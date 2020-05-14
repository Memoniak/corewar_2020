/*
** EPITECH PROJECT, 2020
** get_op_code
** File description:
** gets the op code at memory
*/

#include "corewar.h"

static void (*operation_table[1]) (vm_t *vm, champ_t *champ) = {
    &op_live
};

void op_live(UNSD vm_t *vm, UNSD champ_t *champ)
{
    return;
}

void add_operation(process_t *process, operation_t *op)
{
    operation_t *head;

    head = process->operation_to_do;
    while (process->operation_to_do->next)
        process->operation_to_do = process->operation_to_do->next;
    process->operation_to_do->next = op;
    process->operation_to_do = head;
}

void get_opcode(UNSD vm_t *vm, UNSD process_t *process, UNSD champ_t *champ)
{
    int opcode = vm->mem[process->pc];
    operation_t *op;

    op = malloc(sizeof(operation_t));
    vmemset(op, '\0', sizeof(operation_t));
    op->nb_cycles = op_tab[opcode - 1].nbr_cycles;
    op->operation = operation_table[opcode - 1];
    process->wait_cycles = op->nb_cycles;
    if (process->operation_to_do)
        add_operation(process, op);
    else {
        process->operation_to_do = op;
    }
}
