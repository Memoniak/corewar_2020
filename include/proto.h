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
bool put_ina_file(int *types, int **values, cmd_t *cmd);

//tools.c
int power(int nb, int pow);
int get_param_type(char const *param);
int get_binary_type(char const *param);

#endif /*PROTO_H*/
