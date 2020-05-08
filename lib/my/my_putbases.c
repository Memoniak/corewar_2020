/*
** EPITECH PROJECT, 2019
** my_puthexa
** File description:
** put int en hexa
*/

#include <stdlib.h>
#include <stdio.h>

int my_putstr(char *str);

int my_putchar(char c);

char *my_strncpy(char *dest, char const *str, int n);

char *my_revstr(char *str);

int my_strlen(char const *str);

int my_put_bin(unsigned int nb);

int my_put_hexa(unsigned int nb);

int my_put_maj_hexa(unsigned int nb);

int my_putnbr_o(unsigned int nb);

int my_putbase(unsigned int nb, char *base)
{
    unsigned int len_base = my_strlen(base);
    int i = 1;
    int res;

    while (nb / i >= len_base)
    {
        i *= len_base;
    }
    while (i > 0)
    {
        res = (nb / i) % len_base;
        my_putchar(base[res]);
        i /= len_base;
    }
    return 0;
}

int my_putstr_o(char *str)
{
    if (*str != '\0')
    {
        if (*str <= 32 || *str >= 127) {
            my_putchar('\\');
            my_putnbr_o(*str);
        }
        else {
            my_putchar(*str);
            if (*(str + 1) != '\0')
                return my_putstr_o(str + 1);
        }
    }
    return 0;
}

int my_put_point(unsigned int nb)
{
    return my_putstr("0x") + my_put_hexa(nb);
}

int my_put_hexa_has(unsigned int nb)
{
    return my_putstr("0x") + my_put_hexa(nb);
}

int my_put_maj_hexa_has(unsigned int nb)
{
    return my_putstr("0X") + my_put_maj_hexa(nb);
}
