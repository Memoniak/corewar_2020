/*
** EPITECH PROJECT, 2019
** my_strncpy
** File description:
** copies n char into a string
*/

char *my_strncpy(char *dest, char const *src, int n)
{
    for (int i = 0; i < n; i++)
        dest[i] = src[i];
    dest[n] = '\0';
    return dest;
}
