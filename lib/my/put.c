/*
** EPITECH PROJECT, 2019
** put
** File description:
** affichage basics
*/

int my_putbase(unsigned int nb, char *base);

int my_put_bin(unsigned int nb)
{
    return my_putbase(nb, "01");
}

int my_put_hexa(unsigned int nb)
{
    return my_putbase(nb, "0123456789abcdef");
}

int my_put_maj_hexa(unsigned int nb)
{
    return my_putbase(nb, "0123456789ABCDEF");
}

int my_putnbr_o(unsigned int nb)
{
    return my_putbase(nb, "01234567");
}

int my_putnbr_dec(unsigned int nb)
{
    return my_putbase(nb, "0123456789");
}
