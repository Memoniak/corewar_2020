/*
** EPITECH PROJECT, 2019
** mystrcpy.c
** File description:
** copie du str
*/

char *my_strncpy(char *dest, char const *str, int n)
{
    int i = 0;

    while (i != n) {
        dest[i] = str[i];
        i++;
    }
    if (n > i)
        dest[i] = '\0';
    return dest;
}

char *my_strcpy(char *dest, char const *str)
{
    int i = 0;

    while (i != '\0') {
        dest[i] = str[i];
        i++;
    }
    dest[i] = '\0';
    return dest;
}
