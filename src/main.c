/*
** EPITECH PROJECT, 2020
** main.c
** File description:
** main for asm
*/

#include "assembler.h"

int main(int ac, char **av)
{
    champion_header_t champ = {0};
    funct_t *functions;

    functions = make_struct(av[1], &champ);
    if (!functions)
        return 84;
    printf("func->commds test = %i\n", functions[0].commands->code);
    for (int i = 0; i < functions[0].len; i++) {
        printf("func name --> %s\n", functions[i].name);
        for (int j = 0; j < functions[i].nb_cmd; j++) {
            printf("command:\n\tcode:%i\n\tparam1:%s\n\tparam2:%s\n\tparam3:%s\n\tparam4:%s\n",
            functions[i].commands[j].code, functions[i].commands[j].param1, functions[i].commands[j].param2, functions[i].commands[j].param3, functions[i].commands[j].param4);
        }
    }
    return 0;
}
