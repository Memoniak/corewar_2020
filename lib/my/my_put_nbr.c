/*
** EPITECH PROJECT, 2019
** my_put_nbr
** File description:
** show number
*/

void my_putchar(char c);

int static get_this_number(int length, long one_num, int power_number)
{
    long value_of_number = one_num;
    int temp_value = 0;

    for (int i = 0; i < length; i++) {
        one_num = one_num / 10;
    }
    my_putchar(one_num + '0');
    while (length > 0) {
        one_num = value_of_number % power_number;
        if (one_num >= 10) {
            for (int z = 1; z < length; z++) {
            one_num = one_num / 10;
            }
        }
        my_putchar(one_num + '0');
        power_number = power_number / 10;
        length--;
    }
    return (0);
}

int static power_of_length(int length, long n)
{
    int result = 10;

    for (int i = 1; i < length; i++) {
        result = result * 10;
    }

    get_this_number(length, n, result);
    return (0);
}

int static get_length(long n)
{
    int length = 0;
    long length_finder = n;

    while (length_finder > 9) {
        length_finder = length_finder / 10;
        length++;
    }
    power_of_length(length, n);
    return (0);
}

int my_put_nbr(int nb)
{
    long new_nb = nb;
    if (nb < 0) {
        my_putchar('-');
        new_nb = new_nb * -1;
    }

    get_length(new_nb);
    return (0);
}
