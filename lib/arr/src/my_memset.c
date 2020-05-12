/*
** EPITECH PROJECT, 2020
** my_memset
** File description:
** sets the memory
*/

# include <limits.h>
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdarg.h>

char *my_memset(int len, char *str)
{
    for (int i = 0; i < len; i++)
        str[i] =  '\0';
    return str;
}

void *vmemset(void *s, int c, size_t len)
{
    unsigned char *str;

    str = (unsigned char *)s;
    while (len--)
        *str++ = (unsigned char)c;
    return s;
}
