/*
** EPITECH PROJECT, 2019
** util.c
** File description:
** utilitzires my_printf
*/

#include <stdlib.h>
#include <stdio.h>

char *my_strncat(char *dest, char const *str, int n);

int my_putstr(char *str);

int my_putchar(int c);

int my_put_nbr(int nb);

int display(char *str)
{
    int i = 0;
    char *chain;

    while (str[i] != '%' && str[i] != '\0')
        i++;
    chain = malloc(sizeof(char) * (i + 1));
    for (size_t j = 0; j < i; j++)
        chain[j] = '\0';
    chain[i] = '\0';
    my_strncat(chain, str, i);
    my_putstr(chain);
    free(chain);
    return i;
}

int unknow_flag(char *str, int count)
{
    if (str[count + 1] == '\0') {
        return count++;
    }
    else {
        if (str[count] != '\0')
            my_putchar('%');
        return count++;
    }
    return count;
}
