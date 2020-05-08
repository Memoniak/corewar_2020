/*
** EPITECH PROJECT, 2019
** my_params_to_list.c
** File description:
** structure liste chaînée
*/

#include "my.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int insertion_lk(linked_list_t *list, char *data)
{
    element_t *new = malloc(sizeof(*new));
    int len = my_strlen(data);

    new->data = malloc(sizeof(char) * (my_strlen(data) + 1));
    new->data[0] = '\0';
    new->data = my_strcat(new->data, data);
    new->next = list->first;
    list->first = new;
    list->size += 1;
    return 0;
}

int delete_lk(linked_list_t *list)
{
    element_t *to_del;

    if (list->first != NULL)
    {
        to_del = list->first;
        list->first = list->first->next;
        free(to_del->data);
        free(to_del);
        return 0;
    }
    else
        return -1;
}

void delete_last_lk(linked_list_t *list)
{
    element_t *tmp = list->first;
    element_t *ptmp = list->first;

    if (list == NULL)
        return;
    if (list->first->next == NULL)
    {
        free(list);
        return;
    }

    while (tmp->next != NULL)
    {
        ptmp = tmp;
        tmp = tmp->next;
    }
    ptmp->next = NULL;
    free(tmp);
    list->size -= 1;
}

int delete_item_lk(linked_list_t *list, int pos)
{
    element_t *current = list->first;
    element_t *del;

    if (list == NULL)
        return -1;
    for (int i = 0; i < pos && current != NULL; ++i)
        current = current->next;
    if (current == NULL) {
        free(list);
        return -1;
    }
    del = current;
    current->next = current->next->next;
    free(del->data);
    free(del);
    list->size -= 1;
}