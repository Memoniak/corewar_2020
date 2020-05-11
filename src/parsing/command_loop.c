/*
** EPITECH PROJECT, 2020
** func_param loop
** File description:
** the loop for when creating func
*/

#include "corewar.h"

int command_loop(char **str, int start_pos, funct_t *func, int len)
{
    int z = 1;

    my_printf(2, "%s len --- %i%s\n", TEAL, len, DEF);
    if (get_func_param(str[start_pos], &func->commands[0], func->name) == 84)
        return start_pos;
    for (int i = start_pos + 1; i < start_pos + len; i++) {
        if (str[i]) {
            if (get_func_param(str[i], &func->commands[z], NULL) == 84)
                return i;
            z++;
        }
    }
    return -1;
}

void check_empty_cmd(funct_t *func)
{
    for (int i = 0; i < func[0].len; i++) {
        for (int j = 0; j < func[i].nb_cmd; j++) {
            if (!func[i].commands[j].code && j + 1 != func[i].nb_cmd) {
                func[i].commands =
                remove_command(func[i].commands, j, func[i].nb_cmd);
                func[i].nb_cmd--;
            }
        }
    }
}

int arr_func_loop(int len, char **file_arr, funct_t *functions)
{
    int z = 0;
    int i;

    for (i = 2; i < len; i++) {
        if (check_line(file_arr[i])) {
            i = create_command(file_arr, &functions[z], i);
            z++;
        }
    }
    functions[0].len = z;
    check_empty_cmd(functions);
    if (i == 85)
        return 84;
    return 0;
}
