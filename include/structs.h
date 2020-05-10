/*
** EPITECH PROJECT, 2020
<<<<<<< HEAD:include/structs.h
** structs.h
** File description:
** structs
*/

#ifndef STRUCT_H
#define STRUCT_H

#include "op.h"

extern struct op_s op_tab[];

typedef struct {
    int  index;
    int  code;
    char *param1;
    char *param2;
    char *param3;
    char *param4;
} cmd_t;

typedef struct {
    int   index;
    char  *name;
    int   len;
    int   nb_cmd;
    cmd_t *commands;
} funct_t;

typedef struct {
    char *name;
    char *comment;
    int magic;
    int prog_size;
} champion_header_t;

#endif /* !ASSEMBLER_H_ */
