/*
** EPITECH PROJECT, 2019
** my_swap
** File description:
** swap two ints
*/

void my_putchar(char c);

void my_swap(int *a, int *b)
{
    int a_spot = *a;
    int b_spot = *b;

    *b = a_spot;
    *a = b_spot;
}
