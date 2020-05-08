/*
** EPITECH PROJECT, 2019
** my_ststr
** File description:
** reproduce ststr function
*/

char *my_strstr(char *str, char const *to_find)
{
    int length_str = 0;
    int i = 0;
    char *result = str;

    while (str[i] != '\0') {
        length_str++;
        i++;
    }
    for (int a = 0; a < length_str; a++) {
        if (str[a] == to_find[0] && str[a + 1] == to_find[1]) {
            return (result);
        }
        result++;
    }
}
