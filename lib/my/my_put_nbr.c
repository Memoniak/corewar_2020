/*
** EPITECH PROJECT, 2019
** my_putnbr
** File description:
** print number
*/

int my_putchar(char c);

int my_putstr(char const *str);

int my_put_nbr(int nb)
{
    int a = 0;

    if (nb == -2147483648) {
        return my_putstr("-2147483648");
    }
    else if (nb < 0) {
        nb = -nb;
        my_putchar('-');
    }
    a = nb % 10 + '0';
    nb = nb / 10;
    if (nb > 0)
        my_put_nbr(nb);
    my_putchar(a);
    return 0;
}
