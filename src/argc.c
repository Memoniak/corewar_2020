/*
** EPITECH PROJECT, 2020
** argc
** File description:
** argc
*/

#include "asm.h"

static void del_case(char *str)
{
    int i = 0;

    while (str[i]) {
        str[i] = str[i + 1];
        i++;
    }
}

void line_of_label(char *line)
{
    while (line[0] != ' ' && line[0] != '\0')
        del_case(line);
    while (line[0] == ' ')
        del_case(line);
}

char *recup_label(char *line) //t_asm *asm_d
{
    int i = 0;
    char *label;

    while (line[i] != ' ' && line[i] != '\0')
        i++;
    if (line[i - 1] == ':') { // LABEL_CHAR = ":"
        label = malloc(sizeof(char) * (i + 1));
        label[0] = '\0';
        my_strncpy(label, line, i - 1);
        line_of_label(line);
        return label;
    }
    return 0; //NULL ??
}

// int check_label(char *label)
// {
//     int i = 0;
//     int j;
//     int f = 0;

//     while (label[i]) {
//         j = 0;
//         while (LABEL_CHARS[j])
//             if (LABEL_CHARS[j++] == label[i])
//                 f = 1;
//         if (f == 0) {
//             my_printf("Label: \"%s\" is invalid\n", label);
//             return -1;
//         }
//         f = 0;
//         i++;
//     }
//     return 0;
// }
