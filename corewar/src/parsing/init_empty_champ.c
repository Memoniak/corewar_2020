/*
** EPITECH PROJECT, 2020
** init_empty_champ.c
** File description:
** initialize champ_t to empty
*/

#include "corewar.h"

void init_empty_champ(champ_t new[][4])
{
    for (ssize_t i = 0; i != 4; i++) {
        ((*new) + i)->file_name = NULL;
        *((*new) + i)->name = '\0';
        *((*new) + i)->comment = '\0';
        ((*new) + i)->prog = NULL;
        ((*new) + i)->prog_size = 0;
        ((*new) + i)->champ_nb = i + 1;
        ((*new) + i)->champ_pos = 0;
    }
}

parser_t *init_parser_t(void)
{
    parser_t *new = malloc(sizeof(parser_t));

    if (!new)
        return NULL;
    new->dump = 0;
    new->last_a = 0;
    new->last_n = 0;
    new->nb_n = 0;
    new->nb_a = 0;
    new->nb_players = 0;
    new->dump = 0;
    return new;
}