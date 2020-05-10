/*
** EPITECH PROJECT, 2019
** test_my_printf
** File description:
** test my_printf
*/

int is_num(char str)
{
    if (str >= '0' && str <= '9')
        return 1;
    else if (str == '+' || str == '-')
        return 2;
    return 0;
}