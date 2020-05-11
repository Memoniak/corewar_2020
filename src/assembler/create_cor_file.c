/*
** EPITECH PROJECT, 2020
** create_cor_file
** File description:
** creates the output file
*/

#include "corewar.h"

void create_cor_file(champion_header_t *champ, char const *file_name)
{
    char *name = my_strdup(file_name);

    for (int i = 0; name[i]; i++) {
        if (name[i] == '.')
            name[i] = '\0';
    }
    champ->file_name = malloc(sizeof(char) * my_strlen(file_name) + 4);
    champ->file_name = my_strdup(name);
    champ->file_name = my_strcat(champ->file_name, ".cor");
    champ->fd = open(champ->file_name,  O_WRONLY | O_APPEND | O_CREAT, 0644);
    write_header(champ);
    free(name);
}
