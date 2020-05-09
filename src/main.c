/*
** EPITECH PROJECT, 2020
** main.c
** File description:
** main of corewar project
*/

#include "corewar.h"

int main(int ac, char *av[])
{
    char *param1 = (ac > 1 && av[2]) ? av[2] : NULL;
    char *param2 = (ac > 2 && av[3]) ? av[3] : NULL;
    char *param3 = (ac > 3 && av[4]) ? av[4] : NULL;
    char *param4 = (ac > 4 && av[5]) ? av[5] : NULL;
    int   code   = (ac > 0 && av[1]) ? my_getnbr(av[1]) : 0;
    int   types  = 0;
    int  *values = NULL;

    types = types_to_deca(param1, param2, param3, param4);
    values = values_to_deca(param1, param2, param3, param4);
    writing(&code, &types, &values, av);
    free(values);
    return EXIT_SUCCESS;
}
