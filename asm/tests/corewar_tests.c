/*
** EPITECH PROJECT, 2020
** corewar_tests.c
** File description:
** unitary tests for corewar
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "corewar.h"

static void redirect_all_std(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(types, get_param_types, .init = redirect_all_std)
{
    FILE *solved = fopen("tests/files/types_test", "r");
    cmd_t cmd = {0, 11, "r2", "23", "%34", NULL};
    int types = types_to_deca(&cmd);

    my_printf(1, "%d", types);
    cr_assert_stdout_eq(solved);
}

Test(values, get_param_values, .init = redirect_all_std)
{
    FILE *solved = fopen("tests/files/values_test", "r");
    cmd_t cmd = {0, 11, "r2", "23", "%34", NULL};
    int *values = values_to_deca(&cmd);

    my_printf(1, "%d %d %d %d",
    values[0], values[1], values[2], values[3]);
    cr_assert_stdout_eq(solved);
}

Test(indexes, get_prog_size, .init = redirect_all_std)
{
    cmd_t cmd1[] = {
        {0, 11, "r1", "%7", "%1", NULL}
    };
    cmd_t cmd2[] = {
        {0, 1, "%234", NULL, NULL, NULL},
        {0, 2, "%0", "r3", NULL, NULL},
        {0, 9, "%-12", NULL, NULL, NULL}
    };
    funct_t funct[] = {
        {0, NULL, 1, cmd1},
        {0, "hi", 3, cmd2}
    };
    int prog_size = get_indexes(&funct);

    cr_assert(prog_size == 22);
}
