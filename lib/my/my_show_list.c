/*
** EPITECH PROJECT, 2019
** my_show = _list
** File description:
** show list
*/

#include "my.h"
#include <unistd.h>

void my_show_list(linked_list_t *list)
{
    element_t *current = list->first->next;

    while (current != NULL)
    {
        my_putstr(current->data);
        my_putchar(' ');
        my_putchar('\n');
        current = current->next;
    }
}
