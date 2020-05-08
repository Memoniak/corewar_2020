/*
** EPITECH PROJECT, 2019
** my_show_word_array
** File description:
** show word array
*/

char *my_strcpy(char *dest, char const *src);

int my_strlen(char const *str);

int my_putstr(char const *str);

void my_putchar(char c);

int print_rr(char * const *tab)
{
    while (*tab != 0) {
        my_putstr(*tab);
        tab++;
        my_putchar('\n');
    }
    return (0);
}
