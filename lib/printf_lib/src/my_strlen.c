/*
** EPITECH PROJECT, 2019
** my_strlen.c
** File description:
** srt lengh
*/

int void_putchar(int nb);

int my_strlen(char const *str)
{
    int counter = 0;

    while (str[counter])
        counter++;
    return (counter);
}
