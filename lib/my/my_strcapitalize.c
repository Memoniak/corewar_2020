/*
** EPITECH PROJECT, 2019
** my_strcapitalize
** File description:
** capitelizes the first letter of each word
*/

int static str_checker(char *str, int pos, int bool)
{
    if (str[pos] <= 90 && str[pos] >= 62) {
        str[pos] = str[pos] + 32;
    } else if (str[pos] == ' ' && str[pos + 1] > 96 && str[pos + 1] < 123) {
        bool = 1;
    }
    if (bool == 1 && str[pos] <= 122 && str[pos] >= 97) {
        str[pos] = str[pos] - 32;
        bool = 0;
    } else if (str[pos] < 48 || str[pos] > 123 ) {
        if (str[pos + 1] <= 122 && str[pos + 1] >= 97){
            bool = 1;
        }
    }
    return (bool);
}

char *my_strcapitalize(char *str)
{
    int i = 0;
    int length = 0;
    int bool_checker = 1;

    while (str[i] != '\0') {
        length++;
        i++;
    }
    for (int a = 0; a < length; a++) {
        bool_checker = str_checker(str, a, bool_checker);
    }
    return (str);
}
