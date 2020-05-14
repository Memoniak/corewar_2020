/*
** EPITECH PROJECT, 2020
** live
** File description:
** live
*/

#include "corewar.h"

static int champ_alive(champ_t *champion, vm_t *vm)
{
//    vm->cycle_to_die = -1;
    vm->all_process->live++;
//    vm->current_champ = champion;
//    while (*str != '.' && *str)
    my_printf(1, "The player %d(%s)is alive.\n", champion->champ_nb, champion->name); // str ou str++ ??
    return 0;
}

int live(champ_t *champion, vm_t *vm)
{
    champ_t *tmp;

    if (champion->value[0] == champion->process->registre[1]
        || champion->process->registre[1]) //nb_player faut pas savoir plutot le joueur exact ?? genre int *nb_player plutot ?
        return (champ_alive(champion, vm));
    else {
        tmp = champion->process->operation_to_do->next; //ou process->next ??
        while (tmp != champion) {
            if (champion->value[0] == tmp->process->registre[1])
                champ_alive(tmp, vm);
            tmp = tmp->process->operation_to_do->next; //ou process->next ??
        }
    }
    return 0;
}
//nb_player ) MAX_ARGV_NUMBER
