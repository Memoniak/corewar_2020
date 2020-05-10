/*
** EPITECH PROJECT, 2019
** my_get nbr.c
** File description:
** retourne les int dans une str$
*/

int my_putnbr(int nb);

int my_sign(char const str, int sign)
{
    if (str == '-')
        sign = sign * -1;
    return sign;
}

int is_nbr(char str)
{
    if (str >= '0' && str <= '9')
        return 1;
    else if (str != '+' || str != '-')
        return 2;
    return 0;
}

int calcul_nb(char str, int nb)
{
    if (str != '\0' && nb < 214732392)
    {
        if (is_nbr(str) == 1)
        {
            nb = nb * 10;
            nb = nb + (str - '0');
        }
        else
            return nb;
    }
    return nb;
}

int my_getnbr(char *str)
{
    int nb = 0;
    int sign = 1;
    int i = 0;

    while (is_nbr(str[i]) == 0) {
        i++;
    }
    while (is_nbr(str[i]) == 2) {
        sign = my_sign(str[i], sign);
        i++;
    }
    while (is_nbr(str[i]) == 1)
    {
        nb = calcul_nb(str[i], nb);
        i++;
    }
    return (nb * sign);
}
