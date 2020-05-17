/*
** EPITECH PROJECT, 2020
** remove_process
** File description:
** removes processes
*/

#include "corewar.h"

void remove_from_list(process_t **p, process_t *previous, vm_t *vm)
{
    process_t *tmp;

    if (!previous) {
        vm->all_process = (*p)->next;
        (*p) = NULL;
        free(*p);
        *p = vm->all_process;
    } else {
        tmp = (*p)->next;
        (*p) = NULL;
        free(*p);
        (*p) = tmp;
    }
}

void remove_all_process(vm_t *vm)
{
    process_t *tmp = vm->all_process;
    process_t *prev = NULL;

    while (tmp)
        remove_from_list(&tmp, prev, vm);
}

void check_if_diff(process_t *prev, process_t *p, int *value)
{
    process_t *tmp = p;
    process_t *prev_tmp = prev;

    if (prev)
        while (tmp)  {
            if (tmp->id != prev_tmp->id)
                *value = 1;
            tmp = tmp->next;
        }
}

void remove_process(vm_t *vm)
{
    process_t *all_process;
    process_t *previous = NULL;
    int check_diff = 0;

    all_process = vm->all_process;
    while (all_process) {
        check_if_diff(previous, all_process, &check_diff);
        if (!all_process->live) {
            remove_from_list(&all_process, previous, vm);
        } else {
            all_process->live = 0;
            previous = all_process;
            all_process = all_process->next;
        }
    }
    if (!check_diff)
        remove_all_process(vm);
}
