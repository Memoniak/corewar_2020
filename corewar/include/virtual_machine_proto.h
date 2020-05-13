/*
** EPITECH PROJECT, 2020
** virtual_machine.h
** File description:
** prototype for the_virtual_machine
*/

#ifndef VIRTUAL_H
#define VIRTUAL_H

//read_cor.c
void reada_file(champ_t *champ);

//pars_readed_champ.c
void pars_all_values(char *buf, int read_len, champ_t *champ);

//get_champ_content.c
void get_prog_size(char **buf, int *prog_size);
void get_prog_name(char **buf, char name[][PROG_NAME_LENGTH]);
void get_prog_comment(char **buf, char comment[][COMMENT_LENGTH]);

//get_bytes.c
int read_nbytes(char **buf, int nb, int code);
int get_nbytes(char **buf, int nb);

//decrypt_champ_content.c
void decrypt_instruction(unsigned char code, char **buf, int *read_len);

//tools.c
int power(int nb, int pow);
int get_type(char const *param, char *name);
int get_binary_type(char const *param);
int is_typed(int code);

//init_empty_champ.c
void init_empty_champ(champ_t champ[][4]);

#endif /* !VIRTUAL_H */
