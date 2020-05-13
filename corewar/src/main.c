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

int main(int ac, char *av[])
{
    vm_t vm;
    champ_t champ[4];
    champ_t *champs = malloc(sizeof(champ_t) * 4);

    champs[0].champ_pos = 0;
    champs[0].champ_nb = 1;
    champs[0].prog = malloc(sizeof(char) * 7);
    champs[0].prog[0] = 0x0b;
    champs[0].prog_size = 7;
    champs[1].champ_pos = 0;
    champs[1].champ_nb = 2;
    champs[1].prog = my_strdup("0b000F");
    champs[1].prog_size = 7;
    champs[2].champ_pos = 0;
    champs[2].champ_nb = 2;
    champs[2].prog = my_strdup("0b000F");
    champs[2].prog_size = 7;
    champs[3].champ_pos = 0;
    champs[3].champ_nb = 3;
    champs[3].prog = my_strdup("0b000F");
    champs[3].prog_size = 7;

    if (ac != 2)
	return EXIT_FAILURE;
    //reada_file(av[1]);
    init_empty_champ(&champ);
    //fonction evan parsing
    if (ac != 2)
	return EXIT_FAILURE;
    champ[0].file_name = av[1];
    reada_file(&champ[0]);
    set_up_vm(&vm);
    run_vm(&vm, champs);
    return EXIT_SUCCESS;
}
