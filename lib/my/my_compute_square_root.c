/*
** EPITECH PROJECT, 2019
** my_compute_square_root
** File description:
** compute the square root
*/

void my_putchar(char c);

int my_compute_square_root(int nb)
{
    for (int i = 0; i < 46340; i++) {
        if ((i * i) == nb) {
            return (i);
        }
    }
    return (0);
}
