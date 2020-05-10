/*
** EPITECH PROJECT, 2020
** write_ina_file.c
** File description:
** write asm in file
*/

#include "corewar.h"

static const char FILEPATH[] = "abel.core";

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

bool put_ina_file(int *types, int **values, cmd_t *cmd, op_t op_tab[])
{
    int fd;

    fd = open(FILEPATH, O_APPEND | O_CREAT | O_WRONLY, 0644);
    if (fd == -1)
        return false;
    write(fd, &cmd->code, sizeof(char));
    if (is_typed(cmd->code - 1))
        write(fd, types, sizeof(char));
    nwrite(fd, (*values + 0), get_type(cmd->param1, OTM(cmd->code - 1)));
    nwrite(fd, (*values + 1), get_type(cmd->param2, OTM(cmd->code - 1)));
    nwrite(fd, (*values + 2), get_type(cmd->param3, OTM(cmd->code - 1)));
    nwrite(fd, (*values + 3), get_type(cmd->param4, OTM(cmd->code - 1)));
    close(fd);
    return true;
}
