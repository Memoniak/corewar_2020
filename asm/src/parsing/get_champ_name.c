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
    int str_len = 0;
    int i;

    for (i = pos; i < pos + name_len; i++) {
        if (str[i] == '"') {
            name = get_string_inbetween(str + i, '"');
            str_len = my_strlen(name);
            break;
        }
    }
    if (str[i + str_len + 2] != '\0' && str[i + str_len + 2] != '\n')
        return NULL;
    return name;
}

void get_champ_name(champion_header_t *champ, char **file)
{
    int pos = 0;
    char *name = NULL;

    for (int i = 0; file[i]; i++) {
        pos = get_pos_word_in_str(NAME_CMD_STRING, file[i]);
        if (pos != -1)
            name = copy_name(file[i], pos);
    }
    if (!name) {
        champ->name[0] = '\0';
        return;
    }
    for (int i = 0; i < my_strlen(name); i++)
        champ->name[i] = name[i];
    champ->name[my_strlen(name)] = '\0';
    free(name);
}
