/*
** EPITECH PROJECT, 2019
** test_my_printf
** File description:
** test my_printf
*/

#include "my.h"
#include <unistd.h>
#include <stdlib.h>

int swap(element_t *first, element_t *second)
{
    char *temp = first->data;

    first->data = second->data;
    second->data = temp;
    return 0;
}

int sort_sep(element_t *check, int swapped)
{
    int i = 0;

    while (check->data[i] == '\0' || check->data[i] == '\0') {
        if (check->data[i] == check->next->data[i])
            i++;
        else
            break;
    }
    if (check->data[i] > check->next->data[i])
    {
        swap(check, check->next);
        swapped = 1;
    }
    return swapped;
}

void bubble_sort(linked_list_t *list_a)
{
    element_t *check = list_a->first;
    int swapped = 1;

    while (swapped == 1)
    {
        swapped = 0;
        check = list_a->first;
        while (check->next != NULL) {
            swapped = sort_sep(check, swapped);
            check = check->next;
        }
    }
}