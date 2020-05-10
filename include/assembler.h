/*
** EPITECH PROJECT, 2020
** assembler\
** File description:
** assembler
*/

#ifndef ASSEMBLER_H_
#define ASSEMBLER_H_

#include "my.h"
#include "printf.h"
#include "arr.h"
#include "op.h"
#include "file.h"

typedef struct {
    int code;
    int index;
    char *param1;
    char *param2;
    char *param3;
    char *param4;
} cmd_t;

typedef struct {
    cmd_t *commands;
    char *name;
    int index;
    int len;
    int nb_cmd;
} funct_t;

typedef struct {
    char *name;
    char *comment;
    int magic;
    int prog_size;
} champion_header_t;


//PARSING
int get_func_param(char *str, cmd_t *cmd, char *func_name);
int check_line(char *line);
char *check_name(char *str, char *name);
int get_code(char *code_str, int len);
void init_cmd_struct(cmd_t *commands, int len);
int count_cmd_len(char **arr, int pos);
int count_cmd_len_first(char **arr, int pos);
funct_t *make_struct(char const *filepath, champion_header_t *champion_info);
int create_command(char **str, funct_t *func, int start_pos);
int fill_champion_info(champion_header_t *champ, char **file);
char *get_func_name(char *str);
int command_loop(char **str, int start_pos, funct_t *func, int len);
int arr_func_loop(int len, char **file_arr, funct_t *functions);

//EROR_HANDLING PARSING
void file_error();
void champ_info_error();
void func_cmd_error(int line);

//check_params

int check_label_name(char *name, funct_t *labels);
int check_value_dir(char *value, funct_t *labels);
int check_value_ind(char *value, funct_t *labels);
int check_instructions(cmd_t cmd_line, const op_t* op_tab, funct_t *labels)

#endif /* !ASSEMBLER_H_ */
