/*
** EPITECH PROJECT, 2019
** get_nbr_len
** File description:
** gets the len of an int
*/

int get_nbr_len(int nb)
{
    int len = 1;

    while (nb > 9) {
        nb /= 10;
        len++;
    }
    return len;
}
