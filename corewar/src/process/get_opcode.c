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
    table[1] = &my_ld;
    table[2] = &my_st;
    table[3] = &my_add;
    table[4] = &my_sub;
    table[5] = &my_and;
    table[6] = &my_or;
    table[7] = &my_xor;
    table[8] = &my_zjmp;
    table[9] = &my_ldi;
    table[10] = &my_sti;
    table[11] = &fork_operation;
    table[12] = &my_lld;
    table[13] = &my_lldi;
    table[14] = &my_lfork;
    table[15] = &my_aff;
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
    op_func table[17];

    init_operation_table(table);
    op = malloc(sizeof(operation_t));
    vmemset(op, '\0', sizeof(operation_t));
    if (opcode <= 0 || opcode > 16) {
        printf("Process lost id == %i\n", process->id);
        //printf("Lost process\n");
        process->pc = (process->pc + 1) % MEM_SIZE;
        return;
    }
    op->operation = table[opcode - 1];
    op->nb_cycles = op_tab[opcode - 1].nbr_cycles;
    op->code = opcode;
    process->wait_cycles = op->nb_cycles;
    if (process->operation_to_do)
        add_operation(process, op);
    else
        process->operation_to_do = op;
}
