/*
** EPITECH PROJECT, 2019
** my_strcmp.c
** File description:
** strcmp, strncmp
*/

#include "stdio.h"
#include "my.h"

int my_strcmp(char *s1, char *s2)
{
    int i = 0;

    while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0')
        i++;
    return s1[i] - s2[i];
}

int my_strncmp(char *s1, char *s2, int n)
{
    int i = 0;

    while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0' && i < n)
        i++;
    if (i == my_strlen(s2))
        return 0;
    return s1[i] - s2[i];
}