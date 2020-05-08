/*
** EPITECH PROJECT, 2019
** my_strcat
** File description:
** concatenates two strings
*/

int my_strlen(char const *str);

char *my_strcat(char *dest, char const *src)
{
    int i = 0;
    int len = 0;
    char *result;

    len = my_strlen(dest);
    for (i = 0; src[i] != '\0'; i++) {
        dest[len + i] = src[i];
    }
    dest[len + i] = '\0';
    return (dest);
}
