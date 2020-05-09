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

//bin_to_deca.c
int bin_to_deca(int bin);

//types.c
int types_to_deca(char *param1, char *param2, char *param3, char *param4);

//values.c
int *values_to_deca(char *param1, char *param2, char *param3, char *param4);

//write_ina_file.c
void writing(int *code, int *types, int **values, char *av[]);

//tools.c
int get_param_type(char const *str);

#endif /*PROTO_H*/
