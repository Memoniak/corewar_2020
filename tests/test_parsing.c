/*
** EPITECH PROJECT, 2020
** test_parsing
** File description:
** tests for parsing
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "assembler.h"

char *get_func_name(char *str);
void get_func_param(char *str, cmd_t *cmd, char *func_name);
funct_t *make_struct(char const *filepath, champion_header_t *champion_info);

void redirect_all_str(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(get_func_name, get_name_easy)
{
    char *name = NULL;

    name = get_func_name("hi: sti r1, r2, r3");
    cr_assert_str_eq(name, "hi");
    if (name)
        free(name);
}

Test(get_func_name, get_name_null)
{
    char *name = NULL;
    int ok = 0;

    name = get_func_name("sti r1, %:2, %0");
    if (name)
        ok = 1;
    cr_assert(ok == 0);
}

Test(get_func_param, easy_param)
{
    cmd_t command;

    get_func_param("        sti r1, %:hi, %1", &command, NULL);
    cr_assert(command.code == 11);
    cr_assert_str_eq(command.param1, " r1");
    cr_assert_str_eq(command.param2, " %:hi");
    cr_assert_str_eq(command.param3, " %1");
}

Test(get_func_param, with_func)
{
    cmd_t command;

    get_func_param("hi:     live %234", &command, "hi");
    cr_assert(command.code == 1);
    cr_assert_str_eq(command.param1, " %234");
}
