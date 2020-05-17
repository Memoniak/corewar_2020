/*
** EPITECH PROJECT, 2020
** main.c
** File description:
** main of the_virtual_machine
*/

#include "corewar.h"

void print_cycle(vm_t *vm)
{
    my_printf(1, "CYCLE NUMBER[%s"DYELLOW"]\t",
    F1000(vm->total_cycle), vm->total_cycle);
    my_printf(1, "CYCLE[%s"DGREEN"]\t",
    F1000(vm->cycle), vm->cycle);
    my_printf(1, "CYCLE_TO_DIE[%s"DBLUE"]\t\r",
    F1000(vm->cycle_to_die), vm->cycle_to_die);
}

void set_up_vm(vm_t *vm, parser_t *parser)
{
    vm->cycle = 1;
    vm->total_cycle = 1;
    vm->nb_live = 40;
    vm->cycle_to_die = CYCLE_TO_DIE;
    vm->all_process = NULL;
    vm->dump_cycle = parser->dump;
    vm->nb_champs = parser->nb_players;

}

int check_usage(char *av[])
{
    if (!my_strcmp(av[1], "-h"))
        return 0;
    my_printf(1, "%sUSAGE\n%s", LTEAL, DEF);
    my_printf(1, "./corewar [-dump nbr_cycle] [[-n prog_number]");
    my_printf(1, "[-a load_address] prog_name] ...\n");
    my_printf(1, SLBLUE, "DESCRIPTION\n");
    my_printf(1, "-dump nbr_cycle dumps the memory after the nbr_cycle");
    my_printf(1, "execution (if the round isn't already over) ");
    my_printf(1, "with the following format: 32 bytes/line\n in hexadecimal");
    my_printf(1, " (A0BCDEF1DD3...)\n-n prog_number sets the next program's");
    my_printf(1, "number. By default, the first free number in the parameter");
    my_printf(1, " order\n-a load_address sets the next program's loading");
    my_printf(1, "address. When no address is specified, optimize the ");
    my_printf(1, "addresses so that the processes are as far\n away from");
    my_printf(1, " each other as possible. The addresses are MEM_SIZE");
    my_printf(1, " modulo.\n");
    return 1;
}

int main(int ac, char *av[])
{
    vm_t vm;
    operation_t *opt = opt_create();;
    parser_t *parser;

    if (check_usage(av))
        return EXIT_SUCCESS;
    vmemset(&vm, '\0', sizeof(vm_t));
    init_empty_champ(&vm.champ);
    if (ac < 2)
        return EXIT_FAILURE;
    parser = parse_args(ac, av, &vm.champ);
    if (!parser) {
        //destroy all
        return EXIT_FAILURE;
    }
    for (ssize_t i = 0; i < parser->nb_players; i++)
        reada_file(&vm.champ[i], opt);
    set_up_vm(&vm, parser);
    run_vm(&vm, &vm.champ);
    //destroy_all
    return EXIT_SUCCESS;
}
