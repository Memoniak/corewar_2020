/*
** EPITECH PROJECT, 2020
** bin_to_deca.c
** File description:
** convert binary number to decimal number
*/

#include "corewar.h"

static const int DECA_BASE = 10;

int bin_to_deca(int bin)
{
    int deca = 0;
    int base = 1;
    int temp = 0;

    while (bin > 0) {
        temp = bin % DECA_BASE;
        deca += temp * base;
        bin /= DECA_BASE ;
        base *= 2;
    }
    return deca;
}
