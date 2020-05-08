/*
** EPITECH PROJECT, 2019
** my_getnbr
** File description:
** returns nbr as string
*/

void my_putchar(char c);

int static check_for_negative(char const *str, int length)
{
    int result = 0;
    int count_negatives = 0;

    for (int i = 0; i <= length; i++) {
        if (str[i] - '0' == -3) {
            count_negatives++;
        }
        if (str[i + 1] - '0' <= 9 && str[i + 1] - '0' >= 0) {
            result++;
        }
        if (result > 0 && str[i] - '0' == -3 && count_negatives % 2 != 0) {
            result = 0;
            return (1);
        }
    }
    return (0);
}

int static check_if_impossible(char const *str, int pos, int length)
{
    int checker = 0;

    for (int i = pos; i < length; i++) {
        if (str[i] - '0' <= 9 && str[i] - '0' >= 0) {
            checker++;
        }
    }
    if (checker >= 10) {
        return (1);
    } else {
        return (0);
    }
}

int static turn_into_int(char number[], int len)
{
    int new_number = 0;
    char *tab = number;

    for (int i = 0; i < len; i++) {
        new_number = new_number * 10 + (tab[i] - '0');
    }
    return (new_number);
}

int static show_number(char number[], int length, char const *str)
{
    int result = 0;
    int impossible = 0;

    for (int z = 0; z <= length; z++){
        if (str[z] - '0'  <= 9 && str[z] - '0' >= 0) {
            number[z] = str[z];
            impossible = check_if_impossible(str, z, length);
            if (impossible != 0) {
                return (0);
            }
            result++;
        } else if (result == 0){
        }
    }
    result = turn_into_int(number, length);
    return (result);
}

int my_getnbr(char const *str)
{
    char number_to_show[9];
    int return_int = 0;
    int length = 0;
    int negative_check = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        length++;
    }
    negative_check = check_for_negative(str, length);
    return_int = show_number(number_to_show, length, str);
    if (negative_check == 1) {
        return_int * -1;
    }
    return (return_int);
}
