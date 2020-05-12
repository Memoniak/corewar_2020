/*
** EPITECH PROJECT, 2020
** main.c
** File description:
** main of the_virtual_machine
*/

#include "corewar.h"

int main(int ac, char *av[])
{
    if (ac != 2)
        return EXIT_FAILURE;
    reada_file(av[1]);
    return EXIT_SUCCESS;
}
