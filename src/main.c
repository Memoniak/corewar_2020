/*
** EPITECH PROJECT, 2020
** main.c
** File description:
** main for asm
*/

#include "corewar.h"

//TODO: fonction auxiliaire parcourir funct et check_instruction
static int evan_call(UNSD funct_t *funct_t)
{
    return 0;
}

static void display_funct(funct_t *funct)
{
    for (int i = 0; i < funct[0].len; i++) {
        printf("func name --> %s\n", funct[i].name);
        for (int j = 0; j < funct[i].nb_cmd; j++) {
            printf("command:\n\tindex:%i\n\tcode:%i\n\tparam1:%s\n\tparam2:%s"
                   "\n\tparam3:%s\n\tparam4:%s\n", funct[i].commands[j].index,
                   funct[i].commands[j].code, funct[i].commands[j].param1,
                   funct[i].commands[j].param2, funct[i].commands[j].param3,
                   funct[i].commands[j].param4);
        }
    }
}

int main(int ac, char **av)
{
    champion_header_t champ = {0};
    funct_t *funct;

    if (ac != 2)
        return EXIT_FAILURE;
    if (!(funct = make_struct(av[1], &champ)))
        return EXIT_FAILURE;
    if (evan_call(funct))
        return EXIT_FAILURE;
    if (!sim_main(funct))
        return EXIT_FAILURE;
    display_funct(funct);
    return EXIT_SUCCESS;
}
