/*
** EPITECH PROJECT, 2019
** my_str_to_word_array
** File description:
** splits string into words
*/

#include <stdlib.h>
#include <stdio.h>

int my_strlen(char const *str);
char *my_strdup(char const *src);
int my_show_word_array(char * const *str);

int check_if_alphanum(char let)
{
    if (let > 32 && let < 127)
        return 1;
    else
        return 0;
}

int get_number_of_words(char const *str, int len)
{
    int counter = 0;
    int checker = 0;

    for (int i = 0; i < len; i++) {
        if (check_if_alphanum(str[i]) == 1 && checker == 0)
            checker = 1;
        if (check_if_alphanum(str[i]) == 0 && checker == 1) {
            counter++;
            checker = 0;
        }
    }
    return counter;
}

char **allocate_memory(char **tab, int nb, int len)
{
    for (int i = 0; i < nb; i++) {
        tab[i] = malloc(sizeof(char) * (len + 1));
    }
    return (tab);
}

char **copy_into_tab(char const *str, char **tab, int nb)
{
    int i = 0;
    int j = 0;

    for (int z = 0; z < nb; z++) {
        while (check_if_alphanum(str[i]) == 0) {
            if (str[i] == '\0') {
                tab[z][j] = '\0';
                return tab;
            }
            i++;
        }
        while (check_if_alphanum(str[i]) == 1) {
            tab[z][j] = str[i];
            i++;
            j++;
        }
        tab[z][j] = '\0';
        j = 0;
    }
    return (tab);
}

char **my_str_to_word_array(char const *str)
{
    int nb_words = 0;
    char **tab;
    int len = 0;

    if (str == NULL)
        return NULL;
    len = my_strlen(str);
    nb_words = get_number_of_words(str, len);
    tab = malloc(sizeof(char *) * (nb_words + 1));
    tab[nb_words] = NULL;
    tab = allocate_memory(tab, nb_words, len);
    tab = copy_into_tab(str, tab, nb_words);
    return (tab);
}
