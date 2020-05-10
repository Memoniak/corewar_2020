/*
** EPITECH PROJECT, 2019
** my_compute_power_rec
** File description:
** power recursive
*/

void  my_putchar(char c);

int my_compute_power_rec(int nb, int p)
{
    int result = 1;
    int temp = nb;

    if (p < 0) {
        return (0);
    } else if (p == 0) {
        return (1);
    } else {
        if (temp > 0 && result * nb <= result) {
            return (0);
        }
        if (p > 1) {
            result = my_compute_power_rec(nb, (p - 1));
        }
        return (result * nb);
    }
}
