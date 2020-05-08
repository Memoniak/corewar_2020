/*
** EPITECH PROJECT, 2019
** my_strncpy
** File description:
** copies n char into a string
*/

char *my_strncpy(char *dest, char const *src, int n)
{
    int i = 0;
    int length = 0;
    int z = 0;

    while (src[i] != '\0') {
        length++;
        i++;
    }
    if (n > length) {
        for (int a = length; a < n; a++) {
            dest[a] = '\0';
        }
    }
    while (z != n) {
        dest[z] = src[z];
        z++;
    }
    return (dest);
}
