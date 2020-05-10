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
    printf("code str == %s\n", code_str);
    printf("len == %i\n", len);
    for (int i = 0; i < 16; i++) {
        if (!my_strncmp(code_str, op_tab[i].mnemonique, len))
            return i + 1;
    }
    return 0;
}

void fill_champion_info(champion_header_t *champ, char **file)
{
    char *tmp = my_strdup(file[0]);

    while (*(tmp)++ != '.' && *(tmp) != '\0' && *(tmp) != '\n');
    *(tmp)-= 1;
    if (!my_strncmp(tmp, ".name", 5))
        champ->name = get_string_inbetween(tmp, '"');
    tmp = my_strdup(file[1]);
    while (*(tmp)++ != '.' && *(tmp) != '\0' && *(tmp) != '\n');
    *(tmp)-= 1;
    if (!my_strncmp(tmp, ".comment", 7))
       champ->comment = get_string_inbetween(tmp, '"');
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
    int z = 1;

    if (get_func_name(str[start_pos]) == NULL)
        len = count_cmd_len_first(str, start_pos);
    else
        len = count_cmd_len(str, start_pos);
    func->name = get_func_name(str[start_pos]);
    func->nb_cmd = len;
    func->commands = malloc(sizeof(cmd_t) * (len + 1));
    init_cmd_struct(func->commands, len);
    get_func_param(str[start_pos], &func->commands[0], func->name);
    for (int i = start_pos + 1; i < start_pos + len; i++) {
        if (str[i]) {
            get_func_param(str[i], &func->commands[z], NULL);
            z++;
        }
    }
    func->index = 0;
    return start_pos + len - 1;
}

funct_t *make_struct(char const *filepath, champion_header_t *champion_info)
{
    char **file_arr = get_file_ar(filepath);
    int len = get_dbl_arr_len((const char **)file_arr);
    funct_t *functions = malloc(sizeof(funct_t) * len);
    int z = 0;

    fill_champion_info(champion_info, file_arr);
    for (int i = 2; i < len; i++) {
        if (check_line(file_arr[i])) {
            i = create_command(file_arr, &functions[z], i);
            z++;
        }
    }
    functions[0].len = z;
    return functions;
}
