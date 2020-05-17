/*
** EPITECH PROJECT, 2020
** defines.h
** File description:
** defines
*/

#ifndef DEFINES_H
#define DEFINES_H

#undef  EXIT_FAILURE
#define EXIT_FAILURE (84)

#include "zdefinef.h"

#define UNSD __attribute__((unused))

#define ABS(a)    ((a < 0) ? -a : a)
#define MAX(a, b) ((a > b) ? a : b)
#define MIN(a, b) ((a < b) ? a : b)

#define ROTATION_DIST (1000)
#define SPEED_DIST    (2000)

#define ANIM (true)

#define INFO (true)

#define OTM(a)   op_tab[a].mnemonique
#define FC(a, b) (*funct)[a].commands[b]

#define CLEAR     my_printf(2, "\e[H")
#define CLEAR_ALL my_printf(2, "\e[H\e[J")

#endif /*DEFINES_H*/
