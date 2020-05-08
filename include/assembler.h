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


typedef struct {
    int code;
    char *param1;
    char *param2;
    char *param3;
    char *param4;
} cmd_t;

typedef struct {
    cmd_t *commands;
    char *name;
} funct_t;

typedef struct {
    char **file_header;
    char *name;
    char *comment;
} champion_info_t;

#endif /* !ASSEMBLER_H_ */
