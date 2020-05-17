/*
** EPITECH PROJECT, 2020
** my_live
** File description:
** my live operation
*/

#include "corewar.h"

int my_live(vm_t *vm, process_t *process)
{
    int p_nb = get_param_value(vm, process, 1);
    int param1_type = get_param_type(vm, process, 1);
    champ_t champ = get_champ_from_process(process, vm);

    if (param1_type != DIR_SIZE)
        return -1;
    vm->nb_live++;
    vm->last_live_nb = p_nb;
    if (vm->last_name)
        free(vm->last_name);
    vm->last_name = my_strdup(champ.name);
    process->live++;
    my_printf(2, "\n"SRED BOLD DLBLUE, "The player ", p_nb);
    my_printf(2, " ("DARK BOLD SWHITE")"SRED, vm->last_name, " is alive = ");
    my_printf(2, BOLD SDYELLOW"       \n", F1000(process->live), process->live);
    move_pc(vm, process);
    return 0;
}
