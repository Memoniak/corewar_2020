/*
** EPITECH PROJECT, 2020
** run_vm
** File description:
** runs the vm
*/

#include "corewar.h"

// void take_care_process(vm_t *vm, champ_t *champs)
// {
//     for (int i = 0; i < 4; i++) {
//         if (champs[i].process)
//             exec_process(vm, champs[i].process);
//     }
// }

void run_vm(vm_t *vm, champ_t *champs)
{
    create_champ_process(vm, &champs);
    while (vm->cycle_to_die > 0 && vm->all_process) {
        //take_care_process(vm, champs);
        if (vm->cycle == vm->cycle_to_die) {
            remove_process(vm, champs);
            if (vm->nb_live >= NBR_LIVE) {
                vm->cycle_to_die -= CYCLE_DELTA;
            }
            vm->cycle = 0;
            vm->nb_live = 0;
        }
        print_cycle(vm);
        vm->cycle++;
        vm->total_cycle++;
    }
}
