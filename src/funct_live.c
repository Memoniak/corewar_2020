/*
** EPITECH PROJECT, 2020
** funct_live
** File description:
** funct live
*/

#include "asm.h"

static int check_winner(vm_t *vm)
{
    champion_t *tmp;

    tmp = vm->champions;
    while (tmp) {
        if (tmp->live == 0)
            tmp->live = -1;
        else
            tmp->live = tmp->live;
        tmp = tmp->next;
    }
}

static int check_live(vm_t *vm, int *nbr_winner) // struct pol
{
    int dead = 0;
    int i = 0;
    champion_t *tmp; // struct evan 

    check_winner(vm);
    i = -1;
    while (++i < vm->nbr_champions) {
        if (vm->team_live[i] == 0 || vm->team_live[i] == -1) {
            ++dead;
            if (vm->team_live[i] == 0)
                my_printf(1, "Champion %d is dead\n", i);
            vm->team_live[i] = -1;
        }
        if (vm->team_live[i] == 1)
            *nbr_winner = i;
        else
            *nbr_winner = *nbr_winner;
        //*nbr_winner = (vm->team_live[i] == 1 ? i : *nbr_winner);
    }
    for (int i = 0; i < 4; i++) {
        if (vm->team_live[i] == 1)
            vm->team_live[i] = 0;
    }
    tmp = vm->champions;
    while (tmp) {
        if (tmp->live == 1)
            tmp->live = 0;
        tmp = tmp->next;
    }
    if (nbr_winner - dead <= 1)
        return (nbr_winner = -1);
    return dead; // si nbr_champ - dead <= 1 je return error(-1) or nbr_champ ?
}

static void check_cycles(int *live, int *save_cycles, vm_t *vm)
{
    int i = 1;
    int nb_dead = 0;
    int winner = -1;

    *live = *live + 1;
    if (*live == 40) { // 40 + NBR_LIVE
        *live = 0;
        nb_dead = check_live(vm, &winner);
        if (nb_dead == -1) {
            *save_cycles = 0; //my_printf(1, "Champion %d won :)\n", winner);
        }
        else if (nb_dead > 0)
            return ; // return ??
        else if (nb_dead == 0)
        {
            *save_cycles = 1536 - (i++ * 5); //CYCLE_TO_DIE //CYCLE_DELTA
            if (*save_cycles < 0)
                *save_cycles = 0;
        }
    }
}

int main (int ac, char **av)
{
    return 0;
}

/*static int still_alive(vm_t *vm)
{
    return;
}*/