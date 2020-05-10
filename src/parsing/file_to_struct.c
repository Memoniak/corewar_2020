/*
** EPITECH PROJECT, 2020
** file_to_struct
** File description:
** reads the file and creates a structure
*/

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include "assembler.h"

op_t    op_tab[] =
  {
    {"live", 1, {T_DIR}, 1, 10, "alive"},
    {"ld", 2, {T_DIR | T_IND, T_REG}, 2, 5, "load"},
    {"st", 2, {T_REG, T_IND | T_REG}, 3, 5, "store"},
    {"add", 3, {T_REG, T_REG, T_REG}, 4, 10, "addition"},
    {"sub", 3, {T_REG, T_REG, T_REG}, 5, 10, "soustraction"},
    {"and", 3, {T_REG | T_DIR | T_IND, T_REG | T_IND | T_DIR, T_REG}, 6, 6,
     "et (and  r1, r2, r3   r1&r2 -> r3"},
    {"or", 3, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG}, 7, 6,
     "ou  (or   r1, r2, r3   r1 | r2 -> r3"},
    {"xor", 3, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG}, 8, 6,
     "ou (xor  r1, r2, r3   r1^r2 -> r3"},
    {"zjmp", 1, {T_DIR}, 9, 20, "jump if zero"},
    {"ldi", 3, {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG}, 10, 25,
     "load index"},
    {"sti", 3, {T_REG, T_REG | T_DIR | T_IND, T_DIR | T_REG}, 11, 25,
     "store index"},
    {"fork", 1, {T_DIR}, 12, 800, "fork"},
    {"lld", 2, {T_DIR | T_IND, T_REG}, 13, 10, "long load"},
    {"lldi", 3, {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG}, 14, 50,
     "long load index"},
    {"lfork", 1, {T_DIR}, 15, 1000, "long fork"},
    {"aff", 1, {T_REG}, 16, 2, "aff"},
    {0, 0, {0}, 0, 0, 0}
  };

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
    champ->magic = COREWAR_EXEC_MAGIC;
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
