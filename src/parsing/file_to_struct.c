/*
** EPITECH PROJECT, 2020
** file_to_struct
** File description:
** reads the file and creates a structure
*/

#include "corewar.h"

int get_code(char *code_str, int len)
{
    for (int i = 0; i < 16; i++) {
        if (!my_strncmp(code_str, op_tab[i].mnemonique, len))
            return i + 1;
    }
    return 0;
}

int fill_champion_info(champion_header_t *champ, char **file)
{
    char *tmp = my_strdup(file[0]);

    if (!tmp)
        return 84;
    while (*(tmp)++ != '.' && *(tmp) != '\0' && *(tmp) != '\n');
    if (!my_strncmp(tmp, "name", 4))
        champ->name = get_string_inbetween(tmp, '"');
    tmp = my_strdup(file[1]);
    while (*(tmp)++ != '.' && *(tmp) != '\0' && *(tmp) != '\n');
    if (!my_strncmp(tmp, "comment", 6))
       champ->comment = get_string_inbetween(tmp, '"');
    if (!champ->name || !champ->comment) {
        champ_info_error();
        return 84;
    }
    return 1;
}

char *get_func_name(char *str)
{
    char *name = NULL;

    if (!str)
        return NULL;
    for (int i = 0; str[i]; i++) {
        if (str[i] == ':' && str[i - 1] != '%') {
            name = malloc(sizeof(char) * i + 1);
            name = my_strncpy(name, str, i);
            return name;
        }
    }
    return name;
}

int create_command(char **str, funct_t *func, int start_pos)
{
    int len;
    int tmp = 0;

    if (get_func_name(str[start_pos]) == NULL)
        len = count_cmd_len_first(str, start_pos);
    else
        len = count_cmd_len(str, start_pos);
    func->name = get_func_name(str[start_pos]);
    func->nb_cmd = len;
    func->commands = malloc(sizeof(cmd_t) * (len + 1));
    init_cmd_struct(func->commands, len);
    if ((tmp = command_loop(str, start_pos, func, len)) != -1) {
        func_cmd_error(tmp);
        return 84;
    }
    func->index = 0;
    return start_pos + len - 1;
}

funct_t *make_struct(char const *filepath, champion_header_t *champion_info)
{
    char **file_arr = get_file_ar(filepath);
    int len = get_dbl_arr_len((const char **)file_arr);
    funct_t *functions;

    if (!file_arr || len < 3) {
        file_error();
        return NULL;
    }
    if (fill_champion_info(champion_info, file_arr) == 84)
        return NULL;
    functions = malloc(sizeof(funct_t) * len);
    if (arr_func_loop(len, file_arr, functions) == 84) {
        free(functions);
        return NULL;
    }
    return functions;
}
