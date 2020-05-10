/*
** EPITECH PROJECT, 2020
** proto.h
** File description:
** prototypes
*/

#ifndef PROTO_H
#define PROTO_H

#include "includes.h"
#include "structs.h"

//sim_main.c
bool write_params(cmd_t *cmd, op_t op_tab[]);

//types.c
int types_to_deca(cmd_t *cmd);

//values.c
int *values_to_deca(cmd_t *cmd);

//write_ina_file.c
bool put_ina_file(int *types, int **values, cmd_t *cmd, op_t op_tab[]);

//tools.c
int power(int nb, int pow);
int get_type(char const *param, char *name);
int get_binary_type(char const *param);
int is_typed(int code);

//get_indexes.c
int get_indexes(funct_t **funct);

//get_label_value.c
void get_label_value(funct_t **funct);

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
void file_error(void);
void champ_info_error(void);
void func_cmd_error(int line);

//check_params
int check_label_name(char *name, funct_t *labels);
int check_value_dir(char *value, funct_t *labels);
int check_value_ind(char *value, funct_t *labels);
int check_instructions(cmd_t cmd_line, const op_t* op_tab, funct_t *labels)
int check_label_chars(char *name);
#endif /*PROTO_H*/
