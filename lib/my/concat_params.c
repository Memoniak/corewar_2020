/*
** EPITECH PROJECT, 2019
** concat_params
** File description:
** turns param into string
*/

#include <stdlib.h>

int my_strlen(char const *str);

int my_putstr(char const *str);

void my_putchar(char c);

char *copy_params_into_new(char *tab, char **av, int ac)
{
    int z = 0;
    int temp = 0;
    int len = 0;

    for (int j = 0; j < ac; j++) {
        len = my_strlen(av[j]);
        len += z;
        temp = 0;
        while (z < len) {
            tab[z] = av[j][temp];
            z++;
            temp++;
        }
        tab[z] = '\n';
        z++;
    }
    z--;
    tab[z] = '\0';
    return (tab);
}

char *concat_params(int argc, char **argv)
{
    char *tab;
    int len = 0;
    int z = 0;
    int temp = 0;

    for (int i = 0; i < argc; i++) {
        len += my_strlen(argv[i]);

    }
    tab = malloc(sizeof(char) * (len + argc + 1));
    tab = copy_params_into_new(tab, argv, argc);
    return (tab);
}
