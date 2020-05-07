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

//deca_to_hexa.c
char *deca_to_hexa(int deca);
int bin_to_deca(int bin);

//code_to_hexa.c
char *code_to_hexa(int code);

//types_to_hexa.c
char *types_to_hexa(char *param1, char *param2, char *param3, char *param4);

//values_to_hexa.c
char *values_to_hexa(char *param1, char *param2, char *param3, char *param4);

#endif /*PROTO_H*/
