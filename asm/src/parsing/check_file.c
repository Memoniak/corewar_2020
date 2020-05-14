/*
** EPITECH PROJECT, 2020
** check_file
** File description:
** checks the file lines
*/

#include "corewar.h"


int check_line(char *line)
{
    if (!line)
        return 0;
    for (int i = 0; line[i]; i++) {
        if (line[i] >= 'a' && line[i] <= 'z') {
<<<<<<< HEAD
=======
//            printf("line %s + char %c\n", line, line[i]);
>>>>>>> ea52d79ff86b688955455c5af29633059bf3da42
            return 1;
        }
    }
    return 0;
}

char *check_name(char *str, char *name)
{
    char *new;

    if (name == NULL)
        return str;
    new = my_strdup(str + my_strlen(name) + 1);
    free(str);
    return new;
}
