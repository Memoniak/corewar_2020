/*
** EPITECH PROJECT, 2019
** my_strcnmp
** File description:
** compares n characters of 2 strings
*/

int my_strncmp(char const *s1, char const *s2, int n)
{
    int result = 0;
    int z = 0;
    int e = 0;

    for (int a = 0; a < n; a++) {
        if (s1[a] != s2[a]) {
            z = s1[a];
            e = s2[a];
            result = z - e;
            return (result);
        }
    }
    return 0;
}
