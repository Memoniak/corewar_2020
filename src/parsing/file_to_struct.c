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
    champ->magic = COREWAR_EXEC_MAGIC;
    get_champ_name(champ, file);
    get_champ_comment(champ, file);
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
        if (str[i] == LABEL_CHAR && str[i - 1] != DIRECT_CHAR) {
            name = malloc(sizeof(char) * i + 1);
            name = my_strncpy(name, str, i);
            return name;
        }
    }
    return name;
}

int create_command(char **str, funct_t *func, int start_pos)
{
    int len = 0;
    int tmp = 0;

    if (get_func_name(str[start_pos]) == NULL)
        len = count_cmd_len_first(str, start_pos);
    else
        len = count_cmd_len(str, start_pos);
    func->name = get_func_name(str[start_pos]);
    if (func->name && check_label_chars(func->name))
        return 84;
    func->nb_cmd = len;
    func->commands = malloc(sizeof(cmd_t) * (len + 1));
    init_cmd_struct(func->commands, len);
    if ((tmp = command_loop(str, start_pos, func, len)) != -1) {
        func_cmd_error(tmp);
        return 84;
    }
    func->index = 0;
    return start_pos + len;
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
