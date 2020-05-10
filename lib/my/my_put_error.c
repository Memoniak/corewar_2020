/*
** EPITECH PROJECT, 2019
** my_putstr.c
** File description:
** affiche une chaine de caractères
*/
#include <unistd.h>
#include <stdlib.h>

int my_strlen(char *str);

int my_put_error(char *str)
{
    write(2, str, my_strlen(str));
    exit(84);
    return 84;
}