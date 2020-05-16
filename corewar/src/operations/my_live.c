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
    UNSD int param_t = get_param_type(vm, process, 1);
    champ_t champ = get_champ_from_process(process, vm);

    vm->nb_live++;
    vm->last_live_nb = p_nb;
    if (vm->last_name)
        free(vm->last_name);
    vm->last_name = my_strdup(champ.name);
    process->live++;
    my_printf(2, "\n%sA process show that player %s%d %sis alive = %s%d%s%s\n",
    LRED, LBLUE, p_nb, LRED, LGREEN, process->live, "                  ", DEF);
    move_pc(vm, process);
    return 0;
}
