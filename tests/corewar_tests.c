/*
** EPITECH PROJECT, 2020
** ai_tests.c
** File description:
** unitary tests for ai
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "corewar.h"

void redirect_all_std(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(code_to_hexa, convert_code_to_hexa, .init = redirect_all_std)
{
    FILE *solved = fopen("tests/files/code_test", "r");
    char *code = code_to_hexa(13);

    my_printf(1, "%s", code);
    cr_assert_stdout_eq(solved);
}

Test(types_to_hexa, convert_types_to_hexa, .init = redirect_all_std)
{
    FILE *solved = fopen("tests/files/types_test", "r");
    char *types = types_to_hexa("r2", "23", "%34", NULL);

    my_printf(1, "%s", types);
    cr_assert_stdout_eq(solved);
}

Test(values_to_hexa, convert_values_to_hexa, .init = redirect_all_std)
{
    FILE *solved = fopen("tests/files/values_test", "r");
    char *values = values_to_hexa("r2", "23", "%34", "r1");

    my_printf(1, "%s", values);
    cr_assert_stdout_eq(solved);
}
