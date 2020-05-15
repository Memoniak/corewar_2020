/*
** EPITECH PROJECT, 2020
** get_op_code
** File description:
** gets the op code at memory
*/

#include "corewar.h"

static void init_operation_table(op_func *table)
{
    table[0] = &my_live;
    table[5] = &my_and;
    table[8] = &my_zjmp;
    table[10] = &my_sti;
    table[11] = &fork_operation;
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

void get_opcode(vm_t *vm, process_t *process, UNSD champ_t *champ)
{
    int opcode = vm->mem[process->pc];
    operation_t *op;
    op_func table[16];

    my_printf(2, "OPCODE == %i\n", opcode);
    init_operation_table(table);
    op = malloc(sizeof(operation_t));
    vmemset(op, '\0', sizeof(operation_t));
    op->nb_cycles = op_tab[opcode - 1].nbr_cycles;
    op->operation = table[opcode - 1];
    process->wait_cycles = op->nb_cycles;
    if (process->operation_to_do)
        add_operation(process, op);
    else {
        process->operation_to_do = op;
    }
}
