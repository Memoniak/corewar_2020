/*
** EPITECH PROJECT, 2020
** remove_process
** File description:
** removes processes
*/

#include "corewar.h"

static void remove_from_list(process_t **p)
{
    process_t *tmp;

    tmp = (*p)->next;
    free(*p);
    (*p) = NULL;
    (*p) = tmp;
}

void remove_process(vm_t *vm, champ_t *champ)
{
    process_t *all_process;
    int i = 0;

    all_process = vm->all_process;
    while (all_process) {
        if (!all_process->live) {
            my_printf(2, "%sCHAMP NB:%i has lost a PROCESS\n%s", RED, all_process->registre[1], DEF);
            remove_from_list(&all_process);
        } else {
            all_process->live = 0;
            all_process = all_process->next;
        }
    }
    vm->all_process = all_process;
}
