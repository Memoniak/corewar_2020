/*
** EPITECH PROJECT, 2019
** my_showstr
** File description:
** shows string
*/

void my_putchar(char c);


int static get_hexa(char const *str, int pos)
{
    int quotiant = 0;
    int remain = 0;
    int checker = 0;

    for (int i = str[pos]; remain >= 16; pos++) {
        remain = str[i] - 16;
        checker++;
    }
    my_putchar(checker + '0');
    quotiant = str[pos] % 16;
    if (quotiant > 10) {
        my_putchar(quotiant);
    } else {
        my_putchar(quotiant + 87);
    }
    return (0);
}

int my_showstr(char const *str)
{
    int remainder = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] <= 126 && str[i] >= 32) {
            my_putchar(str[i]);
        } else {
            my_putchar('\\');
            get_hexa(str, i);
        }
    }
    return (0);
}
