/*
** EPITECH PROJECT, 2020
** file_errors
** File description:
** file errors
*/

#include "corewar.h"

void file_error(void)
{
    my_printf(2, "%sFile could not be opened, or it's length is too short%s\n",
    RED, DEF);
}

void champ_info_error(void)
{
    my_printf(2, "%sNo name or comment for champion in file%s\n",
    RED, DEF);
}

void func_cmd_error(UNSD int line)
{
    my_printf(2, "%sWrong label code detected on line %i%s\n",
    RED, line, DEF);
}
