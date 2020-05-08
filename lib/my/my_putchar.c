/*
** EPITECH PROJECT, 2019
** my_putchar.c
** File description:
** afficher un caractère
*/
#include <unistd.h>

int my_putchar(int c)
{
    write(1, &c, 1);
        return 1;
}