/*
** EPITECH PROJECT, 2019
** test_my_printf
** File description:
** test my_printf
*/

#include "op.h"
#include <criterion/criterion.h>
#include <criterion/redirect.h>

typedef struct cmd
{
    int code;
    char *p1;
    char *p2;
    char *p3;
    char *p4;
}cmd_t;

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

static const op_t    op_tab[] =
  {
    {"live", 1, {T_DIR}, 1, 10, "alive"},
    {"ld", 2, {T_DIR | T_IND, T_REG}, 2, 5, "load"},
    {"st", 2, {T_REG, T_IND | T_REG}, 3, 5, "store"},
    {"add", 3, {T_REG, T_REG, T_REG}, 4, 10, "addition"},
    {"sub", 3, {T_REG, T_REG, T_REG}, 5, 10, "soustraction"},
    {"and", 3, {T_REG | T_DIR | T_IND, T_REG | T_IND | T_DIR, T_REG}, 6, 6,
     "et (and  r1, r2, r3   r1&r2 -> r3"},
    {"or", 3, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG}, 7, 6,
     "ou  (or   r1, r2, r3   r1 | r2 -> r3"},
    {"xor", 3, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG}, 8, 6,
     "ou (xor  r1, r2, r3   r1^r2 -> r3"},
    {"zjmp", 1, {T_DIR}, 9, 20, "jump if zero"},
    {"ldi", 3, {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG}, 10, 25,
     "load index"},
    {"sti", 3, {T_REG, T_REG | T_DIR | T_IND, T_DIR | T_REG}, 11, 25,
     "store index"},
    {"fork", 1, {T_DIR}, 12, 800, "fork"},
    {"lld", 2, {T_DIR | T_IND, T_REG}, 13, 10, "long load"},
    {"lldi", 3, {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG}, 14, 50,
     "long load index"},
    {"lfork", 1, {T_DIR}, 15, 1000, "long fork"},
    {"aff", 1, {T_REG}, 16, 2, "aff"},
    {0, 0, {0}, 0, 0, 0}
  };

int check_line(cmd_t cmd_line, const op_t* op_tab);

TestSuite(instructions);

Test(live, test_check_line_live)
{
    cr_assert_eq(check_line(cmd_line_1, op_tab), 0);
    cr_assert_eq(check_line(cmd_line_3, op_tab), -1);
    cr_assert_eq(check_line(cmd_line_4, op_tab), 0);
    cr_assert_eq(check_line(cmd_line_5, op_tab), -1);
    cr_assert_eq(check_line(cmd_line_6, op_tab), -1);
    cr_assert_eq(check_line(cmd_line_7, op_tab), -1);
}

Test(instructions, test_ld) {
    cr_assert_eq(check_line(cmd_ld_1, op_tab), 0);
    cr_assert_eq(check_line(cmd_ld_2, op_tab), -1);
    cr_assert_eq(check_line(cmd_ld_3, op_tab), -1);
}

Test(instructions, test_zjmp)
{
    cr_assert_eq(check_line(cmd_zjmp_1, op_tab), 0);
}

