/*
** EPITECH PROJECT, 2019
** revstr
** File description:
** reverse str
*/

char *my_revstr(char *str)
{
    char char_temp;
    int counter = 0;

    for (int i = 0; str[i] != '\0'; i++)
        counter++;
    for (int j = 0; j < counter / 2; j++) {
        char_temp = str[j];
        str[j] = str[counter - 1 - j];
        str[counter - 1 - j] = char_temp;
    }
    return (str);
}
