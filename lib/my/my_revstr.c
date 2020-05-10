/*
** EPITECH PROJECT, 2019
** my_revstr
** File description:
** inverse une str
*/

int my_strlen(char *str);

char *my_revstr(char *str)
{
    int len = my_strlen(str);
    char temp = 0;

    for (int i = 0; i < len / 2; i++) {
        temp = str[i];
        str[i] = str[len - 1 - i];
        str[len - 1 - i] = temp;
    }
    return str;
}
