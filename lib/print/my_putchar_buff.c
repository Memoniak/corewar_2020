/*
** EPITECH PROJECT, 2019
** my_putchar
** File description:
** Prints a char in console
*/

#include <unistd.h>
#include <stdlib.h>

char *my_putchar_b(int c)
{
    char a = (char) c;
    char *result = malloc(sizeof(char) * 2);

    result[0] = a;
    result[1] = '\0';
    return result;
}
