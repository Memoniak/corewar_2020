/*
** EPITECH PROJECT, 2020
** file.h
** File description:
** file.h
*/

#ifndef FILE_H_
#define FILE_H_

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>

size_t get_file_len(char const *filepath);
char **get_file_ar(char const *filepath);


#endif /* !FILE_H_ */
