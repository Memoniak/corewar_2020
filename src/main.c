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
    char *str = "and r1 ,%0,r1";

    printf("%s", recup_label(str));
    return 0;
}
