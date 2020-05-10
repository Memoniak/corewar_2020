/*
** EPITECH PROJECT, 2019
** my_strcmp
** File description:
** compares two strings
*/

int my_strlen(char const *str);

int my_strcmp(char const *s1, char const *s2)
{
    int i = 0;

    if (!s1 || !s2)
        return 1;
    while (s1[i] != '\0') {
        if (s1[i] - s2[i] < 0) {
            return (-1);
        } else if (s1[i] - s2[i] > 0) {
            return (1);
        } else {
            i++;
        }
    }
    if (my_strlen(s1) < my_strlen(s2))
        return (1);
    return (0);
}
