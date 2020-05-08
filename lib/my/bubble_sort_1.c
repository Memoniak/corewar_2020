/*
** EPITECH PROJECT, 2019
** test_my_printf
** File description:
** test my_printf
*/

//refaire des fonctions liste chaînées

// TODO: connaitre dernière instruction
// TODO: première instruction

#include "my.h"
#include <unistd.h>
#include <stdlib.h>

linked_list_t *create_lk_list(void)
{
    linked_list_t *list = malloc(sizeof(*list));
    element_t *new = malloc(sizeof(*new));

    if (list == NULL || new == NULL)
        return NULL;
    new->data = my_strdup("");
    new->next = NULL;
    list->first = new;
    return list;
}

int check_sorted(linked_list_t *list)
{
    element_t *check = list->first;

    if (len_lk(list) == 1) {
        my_putchar('\n');
        return 0;
    }
    while (check->next != NULL) {
        if (check->data[0] > check->next->data[0])
            return 1;
        else
            check = check->next;
    }
    my_putchar('\n');
    return 0;
}

int len_lk(linked_list_t *list)
{
    int count = 0;
    element_t *current = list->first;

    while (current != NULL)
    {
        count++;
        current = current->next;
    }
    return count;
}

void erase_lk(linked_list_t *list)
{
    if (list->first == NULL)
        return;
    else
    {
        element_t *tmp;

        tmp = list->first->next;
        free(list->first->data);
        free(list->first);
        list->first = tmp;
        return erase_lk(list);
    }
}

int sort(linked_list_t *list)
{
    if (check_sorted(list) == 0)
        return 0;
    bubble_sort(list);
    return 0;
}
