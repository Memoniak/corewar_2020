/*
** EPITECH PROJECT, 2020
** add_process
** File description:
** adds a process to the list
*/

#include "corewar.h"

static void add_process_to_mem(vm_t *vm, champ_t *champ)
{
    int i = 0;

    while (i < champ->prog_size) {
        vm->mem[vm->all_process->start_pos + i] = champ->prog[i];
        i++;
    }
}

static void put_process_in_list(vm_t *vm, process_t *process)
{
    process_t *head;

    head = vm->all_process;
    while (vm->all_process->next)
        vm->all_process = vm->all_process->next;
    vm->all_process->next = process;
    vm->all_process = head;
}

void add_process(champ_t *champ, vm_t *vm)
{
    process_t *process;

    process = malloc(sizeof(process_t));
    vmemset(process, '\0', sizeof(process_t));
    process->registre[1] = champ->champ_nb;
    process->pc = champ->champ_pos;
    process->start_pos = process->pc;
    if (vm->all_process)
        put_process_in_list(vm, process);
    else {
        vm->all_process = process;
    }
    add_process_to_mem(vm, champ);
}
