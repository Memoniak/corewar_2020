/*
** EPITECH PROJECT, 2020
** write_header
** File description:
** writes the champ header
*/

#include "corewar.h"

void write_char(char c, int fd)
{
    write(fd, &c, 1);
}

void write_header(champion_header_t *champ)
{
    for (int i = 0; champ->name[i]; i++)
        write_char(champ->name[i], champ->fd);
    for (int i = my_strlen(champ->name); i < PROG_NAME_LENGTH; i++)
        write_char(0, champ->fd);
    for (int i = 0; champ->comment[i]; i++)
        write_char(champ->comment[i], champ->fd);
    for (int i = my_strlen(champ->comment); i < COMMENT_LENGTH; i++)
        write_char(0, champ->fd);

}
