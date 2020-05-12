/*
** EPITECH PROJECT, 2020
** file_errors
** File description:
** file errors
*/

#include "corewar.h"

void file_error(void)
{
    my_printf(1,"File could not be opened, or it's length is too short\n");
}

void champ_info_error(void)
{
   my_printf(1,"No name or comment for champion in file\n");
}

void func_cmd_error(int line)
{
    my_printf(1,"Wrong label code detected on line %i\n", line);
}
