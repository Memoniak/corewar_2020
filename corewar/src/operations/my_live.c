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

    vm->nb_live++;
    vm->last_live_nb = p_nb;
    process->live++;
    my_printf(2, "\n%sA process show that player %d is alive%s\n", RED, p_nb, DEF);
    move_pc(vm, process);
    return 0;
}
