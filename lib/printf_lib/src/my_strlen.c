/*
** EPITECH PROJECT, 2019
** my_strlen.c
** File description:
** returns str's length
*/

int my_strlen(char const *str)
{
    int len = 0;

    if (!str)
        return 0;
    while (str[len])
        len++;
    return len;
}
