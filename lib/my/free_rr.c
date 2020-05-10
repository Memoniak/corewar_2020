/*
** EPITECH PROJECT, 2020
** frees a double table
** File description:
** frees a double table
*/

#include <stdlib.h>

void free_rr(char **tab)
{
  if (tab != NULL) {
    for (int i = 0; tab[i] != NULL; i++)
        free(tab[i]);
    free(tab);
  }
}
