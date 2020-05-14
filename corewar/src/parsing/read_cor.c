/*
** EPITECH PROJECT, 2020
** read_cor.c
** File description:
** read .cor file
*/

#include "corewar.h"

static int opena_file(char *filepath)
{
    int fd;

    fd = open(filepath, O_RDONLY);
    if (fd == -1)
    {
        my_printf(2, "%sError with open:%s%s '%s'%s\n",
                  RED, BOLD, WHITE, filepath, DEF);
        exit(EXIT_FAILURE);
    }
    return fd;
}

void reada_file(champ_t *champ, operation_t *opt)
{
    ssize_t read_len;
    char    buf[100000];
    int     fd = opena_file(champ->file_name);

    read_len = read(fd, &buf, 100000);
    if (read_len == (-1)) {
        my_printf(2, "%sError with read:%s%s '%s'%s\n",
                  RED, BOLD, WHITE, champ->file_name, DEF);
        exit(EXIT_FAILURE);
    }
    pars_all_values(buf, read_len, champ, opt);
}
