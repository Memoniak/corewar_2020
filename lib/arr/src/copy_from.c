/*
** EPITECH PROJECT, 2020
** copy_from
** File description:
** copy_from
*/

char *copy_from_start(char *str, char *dest, int pos)
{
    int z = 0;

    for (int i = pos; str[i]; i++) {
        dest[z] = str[i];
        z++;
    }
    dest[z] = '\0';
    return dest;
}
