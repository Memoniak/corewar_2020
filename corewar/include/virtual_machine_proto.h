/*
** EPITECH PROJECT, 2020
** virtual_machine.h
** File description:
** prototype for the_virtual_machine
*/

#ifndef VIRTUAL_H
#define VIRTUAL_H

#define MAX_CHAMPS (4)


//read_cor.c
void reada_file(champ_t *champ, operation_t *opt);

//pars_readed_champ.c
void pars_all_values(char *buf, int read_len, champ_t *champ, operation_t *opt);

//get_champ_content.c
void get_prog_size(char **buf, int *prog_size);
void get_prog_name(char **buf, char name[][PROG_NAME_LENGTH]);
void get_prog_comment(char **buf, char comment[][COMMENT_LENGTH]);

//get_bytes.c
int read_nbytes(char **buf, int nb, int code);
int get_nbytes(char **buf, int nb);

//decrypt_champ_content.c
void decrypt_instruction(unsigned char code, char **buf, int *read_len, operation_t *opt);

//tools.c
int power(int nb, int pow);
int get_type(char const *param, char *name);
int get_binary_type(char const *param);
int is_typed(int code);
//vm
void run_vm(vm_t *vm, champ_t *champs);

//process
void add_process(champ_t **champ, vm_t *vm);
void create_champ_process(vm_t *vm, champ_t **champs);
void remove_process(vm_t *vm, champ_t *champs);
void get_opcode(vm_t *vm, process_t *process);
void exec_process();

//print
void print_cycle(vm_t *vm);

//error_handling
void exit_w_msg(char *msg, vm_t *vm);

//champ_t **init_empty_champ(void);
void init_empty_champ(champ_t new[][4]);
parser_t *init_parser_t(void);
int check_parser_values(parser_t *parser);
int fill_cor_file(char *name, parser_t *parser, champ_t *player);
int check_cor_file(char *name);
int check_value_prog(char *name, parser_t *parser);
int check_value_adress(char *name, parser_t *parser);
int check_value_dump(char *name, parser_t *parser);

//create_opt.c
operation_t *opt_create(void);
int opt_length(operation_t *opt);
void opt_display(operation_t *opt);
void opt_push_back(operation_t *opt, operation_t *new);

#endif /* !VIRTUAL_H */
