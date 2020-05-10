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
int get_indexes(funct_t funct[][2]);

#endif /*PROTO_H*/
