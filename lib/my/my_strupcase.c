/*
** EPITECH PROJECT, 2019
** my_strupcase
** File description:
** make a string uppercase
*/

char *my_strupcase(char *str)
{
    int length = 0;
    int i = 0;

    while (str[i] != '\0') {
        i++;
        length++;
    }
    for (int a = 0; a < length; a++) {
        if (str[a] >= 97 && str[a] <= 122) {
            str[a] = str[a] - 32;
        }
    }
    return (str);
}
