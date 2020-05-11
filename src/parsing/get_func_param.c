/*
** EPITECH PROJECT, 2020
** get_func_param
** File description:
** gets the param of the label
*/

#include "corewar.h"

int get_func_param(char *str, cmd_t *cmd, char *func_name)
{
    char **parsed = my_parser(str, SEPARATOR_CHAR);
    int i = 0;

    parsed[0] = check_name(parsed[0], func_name);
    parsed[0] = remove_first_spaces(parsed[0]);
    printf("parsed[0] after removed spacs =%s\n", parsed[0]);
    while((parsed[0][i] != ' ' || parsed[0][i] == 9) && parsed[0][i] != '\0')
        i++;
    printf("code end at %i\n", i);
    cmd->code = get_code(parsed[0], i);
    if (!cmd->code && parsed[0][0] != '\0')
        return 84;
    cmd->index = 0;
    cmd->param1 = my_strdup_start(parsed[0], i);
    if (parsed[0] != NULL && parsed[1] != NULL)
        cmd->param2 = my_strdup(parsed[1]);
    if (parsed[0] && parsed[1] && parsed[2])
        cmd->param3 = my_strdup(parsed[2]);
    if (parsed[0] && parsed[1] && parsed[2] && parsed[3])
        cmd->param4 = my_strdup(parsed[3]);
//    destroy_rr(parsed);
    return 0;
}
