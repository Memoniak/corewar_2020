/*
** EPITECH PROJECT, 2019
** my_str_isupper
** File description:
** checks if only uppercase
*/

int my_str_isupper(char const *str)
{
    int a = 0;
    int length = 0;
    int checker = 0;

    while (str[a] != '\0') {
        length++;
        a++;
    }
    if (length <= 0)
        return (1);
    for (int i = 0; i < length; i++) {
        if (str[i] <= 90 && str[i] >= 65) {
            checker++;
        }
    }
    if (checker == length)
        return (1);
    return (0);
}
