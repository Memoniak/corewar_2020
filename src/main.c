/*
** EPITECH PROJECT, 2020
** main.c
** File description:
** main of corewar project
*/

#include "corewar.h"

static void destroy(char **code, char **types, char **values)
{
    free(*code);
    free(*types);
    free(*values);
}

static void display(char *code, char *types, char *values)
{
    my_printf(1, "code   = |%s|\n", code);
    my_printf(1, "types  = |%s|\n", types);
    my_printf(1, "values = |%s|\n", values);
}

int main(int ac, char *av[])
{
    char *code;
    char *types;
    char *values;
    int   param0 = (ac > 0 && av[1]) ? my_getnbr(av[1]) : 0;
    char *param1 = (ac > 1 && av[2]) ? av[2] : NULL;
    char *param2 = (ac > 2 && av[3]) ? av[3] : NULL;
    char *param3 = (ac > 3 && av[4]) ? av[4] : NULL;
    char *param4 = (ac > 4 && av[5]) ? av[5] : NULL;

    code = code_to_hexa(param0);
    types = types_to_hexa(param1, param2, param3, param4);
    values = values_to_hexa(param1, param2, param3, param4);
    display(code, types, values);
    destroy(&code, &types, &values);
    return EXIT_SUCCESS;
}
