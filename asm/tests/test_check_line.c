/*
** EPITECH PROJECT, 2019
** test_my_printf
** File description:
** test my_printf
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "corewar.h"

cmd_t cmd_line_1 = {1, "%4", NULL, NULL, NULL};
cmd_t cmd_line_2 = {1, "r4", NULL, NULL, NULL};
cmd_t cmd_line_3 = {1, "%4", "r4", NULL, NULL};
cmd_t cmd_line_4 = {1, "%128", NULL, NULL, NULL};
cmd_t cmd_line_5 = {1, "%128", NULL, NULL, "r1"};
cmd_t cmd_line_6 = {1, "(128", NULL, NULL, "r1"};
cmd_t cmd_line_7 = {1, NULL, NULL, NULL, "r1"};

cmd_t cmd_ld_1 = {2, "%0", "r3", NULL, NULL};
cmd_t cmd_ld_2 = {2, "%0", "r128", NULL, NULL};
cmd_t cmd_ld_3 = {2, "%0", "rr", NULL, NULL};

cmd_t cmd_zjmp_1 = {9, "%:hi", NULL, NULL};
cmd_t cmd_zjmp_2 = {9, "%:l2", NULL, NULL};
cmd_t cmd_zjmp_3 = {9, "%:l)", NULL, NULL};

cmd_t cmd_lld_1 = {13, ":live", "r2", NULL, NULL};
cmd_t cmd_lld_2 = {13, "sedf", "r2", NULL, NULL};
cmd_t cmd_value_1 = {1, "%-4", NULL, NULL, NULL};
cmd_t cmd_value_2 = {1, "%4ef", NULL, NULL, NULL};
cmd_t cmd_value_3 = {1, "-4", NULL, NULL, NULL};
funct_t labels[] = {{0, "live", 0, 2, NULL}, {0, "l2", 0, 2, NULL}};

int check_instructions(cmd_t cmd_line, const op_t *op_tab, funct_t *labels);

TestSuite(instructions);

Test(live, test_check_instructions_live)
{
    cr_assert_eq(check_instructions(cmd_line_1, op_tab, labels), 0);
    cr_assert_eq(check_instructions(cmd_line_3, op_tab, labels), 1);
    cr_assert_eq(check_instructions(cmd_line_4, op_tab, labels), 0);
    cr_assert_eq(check_instructions(cmd_line_5, op_tab, labels), 1);
    cr_assert_eq(check_instructions(cmd_line_6, op_tab, labels), 1);
    cr_assert_eq(check_instructions(cmd_line_7, op_tab, labels), 1);
}

Test(instructions, test_ld) {
    cr_assert_eq(check_instructions(cmd_ld_1, op_tab, labels), 0);
    cr_assert_eq(check_instructions(cmd_ld_2, op_tab, labels), 1);
    cr_assert_eq(check_instructions(cmd_ld_3, op_tab, labels), 1);
}

Test(instructions, test_zjmp_and_labels)
{
    cr_assert_eq(check_instructions(cmd_zjmp_1, op_tab, labels), 1);
    cr_assert_eq(check_instructions(cmd_zjmp_2, op_tab, labels), 0);
    cr_assert_eq(check_instructions(cmd_zjmp_3, op_tab, labels), 1);
    cr_assert_eq(check_instructions(cmd_lld_2, op_tab, labels), 1);
}

Test(instructions, test_values)
{
    cr_assert_eq(check_instructions(cmd_value_1, op_tab, labels), 0);
    cr_assert_eq(check_instructions(cmd_value_2, op_tab, labels), -1);
    cr_assert_eq(check_instructions(cmd_value_3, op_tab, labels), -1);
}
