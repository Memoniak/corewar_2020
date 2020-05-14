/*
** EPITECH PROJECT, 2020
** create_champ_process
** File description:
** creates the champs process
*/

#include "corewar.h"

int get_champ_pos(champ_t *champ, int i)
{
    int champ_left = 0;

    if (champ[i].champ_pos)
        return champ[i].champ_pos;
    for (; i <= 4; i++)
        champ_left++;
    return (MEM_SIZE / champ_left);
}

void create_champ_process(vm_t *vm, champ_t **champs)
{
    int pos_change = 0;
    int champ_pos = 0;

    for (int i = 0; i < 3; i++) {
        pos_change = get_champ_pos(*champs, i);
        champ_pos += pos_change;
        champs[i]->champ_pos = champ_pos;
        my_printf(2, "%schamp[%i]_pos--%i%s\n", BLUE, i, champ_pos, DEF);
        add_process(&champs[i], vm);
    }
}
