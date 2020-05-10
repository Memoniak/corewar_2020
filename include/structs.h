/*
** EPITECH PROJECT, 2020
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
    int   nb_cmd;
    cmd_t *commands;
} funct_t;

typedef struct {
    char **file_header;
    char *name;
    char *comment;
} champion_info_t;

#endif /*STRUCT_H*/
