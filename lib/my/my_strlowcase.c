/*
** EPITECH PROJECT, 2019
** my_strlowcase
** File description:
** puts a string all to lower case
*/

char *my_strlowcase(char *str)
{
    int i = 0;
    int length = 0;

    while (str[i] != '\0') {
        length++;
        i++;
    }
    for (int a = 0; a < length; a++) {
        if (str[a] >= 65 && str[a] <= 90) {
            str[a] = str[a] + 32;
        }
    }
    return (str);
}
