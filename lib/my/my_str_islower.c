/*
** EPITECH PROJECT, 2019
** my_str_islower
** File description:
** checks is only lowercase
*/

int my_str_islower(char const *str)
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
        if (str[i] <= 122 && str[i] >= 97) {
            checker++;
        }
    }
    if (checker == length)
        return (1);
    return (0);
}
