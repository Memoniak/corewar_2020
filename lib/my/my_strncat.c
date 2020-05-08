/*
** EPITECH PROJECT, 2019
** my_strncat
** File description:
** concatenates n number of char
*/

int my_strlen(char const *str);

char *my_strncat(char *dest, char const *src, int nb)
{
    int i = 0;
    int len = 0;
    char *result;

    len = my_strlen(dest);
    for (i = 0; src[i] != '\0' && i < nb; i++)
    {
        dest[len + i] = src[i];
    }
    dest[len + i] = '\0';
    return (dest);
}
