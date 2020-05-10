/*
** EPITECH PROJECT, 2019
** my_strlen
** File description:
** affiche la longueur d'une chaine de caractères
*/

void my_putchar(char c);

int my_strlen(const char *str)
{
    int i = 0;
    while (str[i] != '\0')
    {
        i++;
    }
    return i;
}
