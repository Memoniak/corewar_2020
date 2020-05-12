/*
** EPITECH PROJECT, 2020
** init_empty_champ.c
** File description:
** initialize champ_t to empty
*/

#include "corewar.h"

void init_empty_champ(champ_t champ[][4])
{
    for (ssize_t i = 0; i != 4; i++)
    {
        ((*champ) + i)->file_name = NULL;
        *((*champ) + i)->name = '\0';
        *((*champ) + i)->comment = '\0';
        ((*champ) + i)->prog = NULL;
        ((*champ) + i)->prog_size = 0;
        ((*champ) + i)->champ_nb = i;
    }
}
