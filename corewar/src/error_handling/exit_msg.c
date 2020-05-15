/*
** EPITECH PROJECT, 2020
** exit_msg
** File description:
** exits with a message
*/

#include "corewar.h"

void exit_w_msg(char *msg, UNSD vm_t *vm)
{
    my_printf(2, "%s%s%s\n", RED, msg, DEF);
    exit(1);
}
