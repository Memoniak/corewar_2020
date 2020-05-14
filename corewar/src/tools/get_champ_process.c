/*
** EPITECH PROJECT, 2020
** get_champ_process
** File description:
** gets the champ ptrocess
*/

#include "corewar.h"

process_t *get_champ_process(vm_t *vm, champ_t *champ)
{
    process_t *res = vm->all_process;

    while (res) {
        if (res->registre[1] == champ->champ_nb)
            return res;
        res = res->next;
    }
    return res;
}
