/*
** EPITECH PROJECT, 2020
** run_vm
** File description:
** runs the vm
*/

#include "corewar.h"

void print_mem(vm_t *vm)
{
    unsigned char bite;

    for (int i = 0; i < MEM_SIZE; i++) {
        bite = vm->mem[i];
        if (vm->mem[i] != 0)
            my_printf(2, "%s%s%x%s ", YELLOW, (bite < 16) ? "0" : "", bite, DEF);
        else {
            my_printf(2, "%s%s%x%s ", LBLUE, (bite < 16) ? "0" : "", bite, DEF);
        }
        if (!((i + 33) % 32))
            printf("\n");
    }
}

void run_vm(vm_t *vm, champ_t champs[][4])
{
    create_champ_process(vm, champs);
    print_mem(vm);
    while (vm->cycle_to_die > 0 && vm->all_process) {
        take_care_process(vm, *champs);
        if (vm->cycle == vm->cycle_to_die) {
            my_printf(2, "%sRESTARTING LOOP\n%s", LRED, DEF);
            remove_process(vm);
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
