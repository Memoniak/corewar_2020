/*
** EPITECH PROJECT, 2020
** get_champ_name
** File description:
** gets the champ name in file
*/

#include "corewar.h"

char *copy_name(char *str, int pos)
{
    int name_len = my_strlen(str) - pos;
    char *name;

    for (int i = pos; i < pos + name_len; i++) {
        if (str[i] == '"') {
            name = get_string_inbetween(str + i, '"');
            return name;
        }
    }
    return NULL;
}

void get_champ_name(champion_header_t *champ, char **file)
{
    int pos = 0;

    for (int i = 0; file[i]; i++) {
        pos = get_pos_word_in_str(NAME_CMD_STRING, file[i]);
        if (pos != -1)
            champ->name = copy_name(file[i], pos);
    }
}
