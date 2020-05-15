/*
** EPITECH PROJECT, 2020
** dup_process.c
** File description:
** duplicates a process
*/

#include "corewar.h"

static void copy_process(process_t **dest, process_t *src, size_t n)
{
    unsigned char *source;
    unsigned char *destination;

    source = (unsigned char *)src;
    destination = (unsigned char *)*dest;
    while(n--)
        *destination++ = *source++;
    return;
}

static void insert_process(vm_t *vm, process_t *new)
{
    process_t *p;
    process_t *previous;

    p = vm->all_process;
    while (p) {
        if (p->id == new->id) {
            while (p && p->id == new->id) {
                previous = p;
                p = p->next;
            }
            new->next = previous->next;
            previous->next = new;
            return;
        }
        p = p->next;
    }
}

int fork_operation(vm_t *vm, process_t *process)
{
    process_t *new;
    process_t *old = process;
    int adr;

    if (!(new = malloc(sizeof(process_t))))
        exit_w_msg("Failed to create new process\n", vm);
    vmemset(new, '\0', sizeof(process_t));
    copy_process(&new, old, sizeof(process_t));
    insert_process(vm, new);
    adr = get_param_value(vm, process, 1);
    new->wait_cycles = 0;
    new->operation_to_do = NULL;
    new->pc = (process->pc + adr) % IDX_MOD;
    move_pc(vm, process);
    return 0;
}
