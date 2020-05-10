/*
** EPITECH PROJECT, 2020
** my_memset
** File description:
** sets the memory
*/

char *my_memset(int len, char *str)
{
    for (int i = 0; i < len; i++)
        str[i] =  '\0';
    return str;
}
