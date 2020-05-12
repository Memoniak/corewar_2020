/*
** EPITECH PROJECT, 2020
** main.c
** File description:
** main of the_virtual_machine
*/

#include "corewar.h"

void print_cycle(vm_t *vm)
{
    my_printf(1, "CYCLE NUMBER[%d]\t", vm->total_cycle);
    my_printf(1, "CYCLE[%d]\t", vm->cycle);
    my_printf(1, "CYCLE_TO_DIE[%d]\t", vm->cycle_to_die);
}

void set_up_vm(vm_t *vm)
{
    vmemset(vm, '\0', sizeof(vm_t));
    vm->cycle = 1;
    vm->total_cycle = 1;
    vm->nb_live = 40;
    vm->cycle_to_die = CYCLE_TO_DIE;
}

int main(int ac, char *av[])
{
    vm_t vm;
    champ_t champ;

    if (ac != 2)
        return EXIT_FAILURE;
    reada_file(av[1], &champ);
    set_up_vm(&vm);
    return EXIT_SUCCESS;
}
