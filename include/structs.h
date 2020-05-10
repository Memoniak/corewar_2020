/*
** EPITECH PROJECT, 2020
** structs.h
** File description:
** structs
*/

#ifndef STRUCT_H
#define STRUCT_H

typedef struct {
    int  index;
    int  code;
    char *param1;
    char *param2;
    char *param3;
    char *param4;
} cmd_t;

typedef struct {
    char  *name;
    int   index;
    cmd_t *commands;
} funct_t;

typedef struct {
    char **file_header;
    char *name;
    char *comment;
} champion_info_t;

#endif /*STRUCT_H*/
