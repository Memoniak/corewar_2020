/*
** EPITECH PROJECT, 2019
** my_strlen
** File description:
*/

int my_strlen(char const *str)
{
    int length = 0;
    int i = 0;

    while (str[i] != '\0') {
        length++;
        i++;
    }
    return (length);
}