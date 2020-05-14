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
    my_printf(1, "CYCLE_TO_DIE[%d]\t\n", vm->cycle_to_die);
    usleep(10000);
}

void set_up_vm(vm_t *vm)
{
    vmemset(vm, '\0', sizeof(vm_t));
    vm->cycle = 1;
    vm->total_cycle = 1;
    vm->nb_live = 40;
    vm->cycle_to_die = CYCLE_TO_DIE;
    vm->all_process = NULL;
}

//! nombre de players : parser->nb_players
//! nb de cycle : parser->dump

int main(int ac, char *av[])
{
    UNSD vm_t vm;
    champ_t champ[4];
    operation_t *opt = opt_create();;
    parser_t *parser;

    init_empty_champ(&champ);
    if (ac < 2)
        return EXIT_FAILURE;
    parser = parse_args(ac, av, &champ);
    if (!parser)
        return EXIT_FAILURE;
    champ[0].file_name = av[1];
    reada_file(&champ[0], opt);
    my_printf(2, "opt_len = %d\n", opt_length(opt));
//    opt_display(opt);
//    set_up_vm(&vm);
//    run_vm(&vm, champ);
    return EXIT_SUCCESS;
}
