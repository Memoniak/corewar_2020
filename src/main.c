/*
** EPITECH PROJECT, 2020
** main
** File description:
** main
*/

#include "asm.h"
#include <stdio.h>

int main(void)
{
    char *str = "%:hi";
    int value = -1245678;

    printf("%s\n", replace_label(str, value));
    return 0;
}
