/*
** EPITECH PROJECT, 2019
** my_str_isprintable
** File description:
** checks if string is printable
*/

int my_strlen(char const *str);

int my_str_isprintable(char const *str)
{
    int checker = 0;
    int length = 0;

    length = my_strlen(str);
    if (length <= 0)
        return (1);
    for (int i = 0; i < length; i++) {
        if (str[i] > 31 && str[i] < 127) {
            checker++;
        }
    }
    if (checker == length) {
        return (1);
    } else {
        return (0);
    }
}
