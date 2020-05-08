/*
** EPITECH PROJECT, 2019
** my_getnbr
** File description:
** get number in a string
*/

int my_strlen(char const *str);

int check_for_negative(char const *str, int len)
{
    int result = 0;
    int count_negative = 0;

    for (int i = 0; i <= len; i++) {
        if (str[i] == '-')
            count_negative++;
    }
    if (count_negative % 2 == 0)
        return 0;
    else
        return 1;
}

int check_if_impossible(char const *str, int pos, int len)
{
    int checker = 0;

    for (int i = pos; i < len; i++) {
        if (str[i] <= '9' && str[i] >= '0')
            checker++;
    }
    if (checker >= 10)
        return (1);
    else
        return 0;
}

int turn_into_int(char number[], int len)
{
    int new_number = 0;
    char *tab = number;

    for (int i = 0; i < len; i++) {
        new_number = new_number * 10 + (tab[i]);
    }
    return new_number;
}

int finds_nbr(int len, char const *str)
{
    char number[9];
    int result = 0;

    for (int i = 0; i <= len; i++) {
        if (str[i] <= '9' && str[i] >= '0') {
            number[i] = str[i] - '0';
            if (check_if_impossible(str, i, len))
                return 0;
        }
    }
    result = turn_into_int(number, len);
    return (result);
}

int my_getnbr(char const *str)
{
    int len = my_strlen(str);
    int negative_check = 0;
    int result = 0;

    negative_check = check_for_negative(str, len);
    result = finds_nbr(len, str);
    if (negative_check == 1)
        result *= -1;
    return result;
}
