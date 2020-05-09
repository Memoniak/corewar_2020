/*
** EPITECH PROJECT, 2020
** write_ina_file.c
** File description:
** write asm in file
*/

#include "corewar.h"

static const char FILEPATH[] = "file.core";

static int power(int nb, int pow)
{
    if (!pow)
        return 1;
    return (nb * power(nb, pow - 1));
}

static void nwrite(int fd, int *value, int nb)
{
    int right;
    int left;
    int hexa;

    for (int i = nb; i != 0; i--) {
        right = *value & (power(2, i * 8) - 1);
        left = *value & (power(2, (i - 1) * 8) - 1);
        hexa = (right - left) >> (8 * (i - 1));
        write(fd, &hexa, sizeof(char));
    }
}

void writing(int *code, int *types, int **values, char *av[])
{
    int fd;

    fd = open(FILEPATH, O_APPEND | O_CREAT | O_WRONLY, 0644);
    if (fd == -1)
        return;
    write(fd, code, sizeof(char));
    write(fd, types, sizeof(char));
    for (int i = 0; i != 4 && *(*values + i); i++) {
        nwrite(fd, (*values + i), get_param_type(av[i + 2]));
    }
    close(fd);
}
