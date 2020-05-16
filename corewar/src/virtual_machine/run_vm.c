/*
** EPITECH PROJECT, 2020
** run_vm
** File description:
** runs the vm
*/

#include "corewar.h"

champ_t get_champ_from_process(process_t *process, vm_t *vm)
{
    process_t *tmp = process;

    while (tmp) {
        for (int i = 0; i < vm->nb_champs; i++) {
            if (tmp->id == vm->champ[i].champ_nb)
                return vm->champ[i];
        }
        tmp = tmp->next;
    }
    return vm->champ[0];
}

void print_end(vm_t *vm, UNSD champ_t champ[][4])
{
    my_printf(2, "The player %i(%s) has won.\n", vm->last_live_nb, vm->last_name);
}

void dump_mem(vm_t *vm)
{
    if (vm->dump_cycle == vm->cycle)
        print_mem(vm);
}

void run_vm(vm_t *vm, champ_t champs[][4])
{
    CLEAR_ALL;
    create_champ_process(vm, champs);
    while (vm->cycle_to_die > 0 && vm->all_process) {
        print_mem(vm);
        take_care_process(vm, *champs);
        if (vm->cycle == vm->cycle_to_die) {
            remove_process(vm);
            if (vm->nb_live >= NBR_LIVE) {
                vm->cycle_to_die -= CYCLE_DELTA;
            }
            vm->cycle = 0;
            vm->nb_live = 0;
        }
        vm->cycle++;
        vm->total_cycle++;
        print_cycle(vm);
        dump_mem(vm);
        CLEAR;
    }
    print_end(vm, champs);
}
