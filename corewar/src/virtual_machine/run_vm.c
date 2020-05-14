/*
** EPITECH PROJECT, 2020
** run_vm
** File description:
** runs the vm
*/

#include "corewar.h"

void print_mem(vm_t *vm)
{
    for (int i = 0; i < MEM_SIZE; i++) {
        if (vm->mem[i] != 0)
            printf("%s%x%s ", YELLOW, vm->mem[i], DEF);
        else {
            printf("%s%x%s ", LBLUE, vm->mem[i], DEF);
        }
        if (i % 64 == 0 && i != 0)
            printf("\n");
    }
}

void run_vm(vm_t *vm, champ_t champs[][4])
{
    create_champ_process(vm, champs);
    my_printf(2, DREDN, vm->all_process->pc);
    my_printf(2, DLBLUE" ", get_param_type(vm, vm->all_process, 1));
    my_printf(2, DLBLUE" ", get_param_type(vm, vm->all_process, 2));
    my_printf(2, DLBLUE" ", get_param_type(vm, vm->all_process, 3));
    my_printf(2, DLBLUEN, get_param_type(vm, vm->all_process, 4));
    my_printf(2, DLGREEN" ", get_param_value(vm, vm->all_process, 1));
    my_printf(2, DLGREEN" ", get_param_value(vm, vm->all_process, 2));
    my_printf(2, DLGREEN" ", get_param_value(vm, vm->all_process, 3));
    my_printf(2, DLGREENN, get_param_value(vm, vm->all_process, 4));
    my_printf(2, DLYELLOWN, get_next_pc(vm, vm->all_process));
    print_mem(vm);
    while (vm->cycle_to_die > 0 && vm->all_process) {
        //take_care_process(vm, champs);
        if (vm->cycle == vm->cycle_to_die) {
            my_printf(2, "%sRESTARTING LOOP\n%s", LRED, DEF);
            remove_process(vm);
            if (vm->nb_live >= NBR_LIVE) {
                vm->cycle_to_die -= CYCLE_DELTA;
            }
            vm->cycle = 0;
            vm->nb_live = 0;
        }
        //print_cycle(vm);
        vm->cycle++;
        vm->total_cycle++;
    }
}
