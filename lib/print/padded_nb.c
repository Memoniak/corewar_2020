/*
** EPITECH PROJECT, 2019
** padded_nb
** File description:
** padds numbers with 0
*/

void my_putchar(int c);

int padded(int len)
{
    for (int i = 0; i < len; i++) {
        my_putchar('0');
    }
}
