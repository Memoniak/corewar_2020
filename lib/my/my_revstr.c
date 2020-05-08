/*
** EPITECH PROJECT, 2019
** my_revstr
** File description:
** reverses a string
*/

char *my_revstr(char *str)
{
    int i = 0;
    int length = 0;
    int z = 0;
    char temp;

    while (str[z] != '\0') {
        length++;
        z++;
    }
    i = length - 1;
    for (int a = 0; a < length / 2; a++) {
        temp = str[a];
        str[a] = str[i];
        str[i] = temp;
        i--;
    }
    return (str);
}
