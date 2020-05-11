/*
** EPITECH PROJECT, 2020
** get_champ_comment
** File description:
** gets the champ comment in file
*/

#include "corewar.h"

void get_champ_comment(champion_header_t *champ, char **file)
{
    int pos = 0;
    char *comment = NULL;

    for (int i = 0; file[i]; i++) {
        pos = get_pos_word_in_str(COMMENT_CMD_STRING, file[i]);
        if (pos != -1)
            comment = copy_name(file[i], pos);
    }
    if (!comment) {
        champ->comment[0] = '\0';
        return;
    }
    for (int i = 0; i < my_strlen(comment); i++)
        champ->comment[i] = comment[i];
    champ->comment[my_strlen(comment)] = '\0';
    free(comment);
}
