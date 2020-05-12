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

#define UNSD __attribute__((unused))

#define DEF     "\e[m"
#define BLACK   "\e[30m"
#define RED     "\e[31m"
#define GREEN   "\e[32m"
#define YELLOW  "\e[33m"
#define BLUE    "\e[34m"
#define MAGENTA "\e[35m"
#define TEAL    "\e[36m"
#define WHITE   "\e[37m"
#define BOLD    "\e[1m"

#define LRED     "\e[91m"
#define LGREEN   "\e[92m"
#define LYELLOW  "\e[93m"
#define LBLUE    "\e[94m"
#define LMAGENTA "\e[95m"
#define LTEAL    "\e[96m"

#define MAX(a, b) ((a > b) ? a : b)
#define MIN(a, b) ((a < b) ? a : b)

#define ROTATION_DIST (1000)
#define SPEED_DIST    (2000)

#define INFO (true)

#define OTM(a)   op_tab[a].mnemonique
#define FC(a, b) (*funct)[a].commands[b]

#endif /*DEFINES_H*/
