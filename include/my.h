/*
** EPITECH PROJECT, 2019
** lib my_printf
** File description:
** lib my_printf
*/

#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>

typedef struct element_t
{
    char *data;
    struct element_t *next;
} element_t;

typedef struct linked_list_t
{
    element_t *first;
    int size;
} linked_list_t;

typedef struct tab_func
{
    char type;
    int (*ptr)();
} tab_func;

va_list list;

//CLASSIC
int my_strlen(const char *str);
int my_putchar(int c);
int my_put_nbr(int nb);
int my_putstr(char *str);
char *my_strcat(char *dest, char const *str);
char *my_strncat(char *dest, char const *str, int n);
char *my_strdup(char const *src);
char *my_strcpy(char *dest, char const *str);
char *my_strncpy(char *dest, char const *str, int n);
void *my_memset(void *ptr, int value, size_t count);
char **my_str_to_word_array(char *str, char sep);
int destroy_word_array(char **tab);
int my_str_isnum(char const *str);
int my_getnbr(char *str);
int is_num(char str);
int my_put_error(char *str);
int my_strncmp(char *s1, char *s2, int n);
int my_strcmp(char *s1, char *s2);
char **list_to_tab(linked_list_t *list);
linked_list_t *create_lk_list(void);
linked_list_t *my_params_to_list(linked_list_t *list, int ac, char **av);
int len_lk(linked_list_t *list);
int delete_lk(linked_list_t *list);
int insertion_lk(linked_list_t *list, char *data);
void my_show_list(linked_list_t *list);
int delete_item_lk(linked_list_t *list, int pos);
int ins_liste(linked_list_t *list, char *data, int pos);
int my_show_array(char **tab);
// SORT

void bubble_sort(linked_list_t *list_a);
int swap(element_t *first, element_t *second);
int sort(linked_list_t *list);

//MYPRINTF
int my_putstr_o(char *str);
int my_putnbr_o(int nb);
int my_put_bin(unsigned int nb);
int my_put_hexa(unsigned int nb);
int my_put_maj_hexa(unsigned int nb);
int my_putnbr_dec(unsigned int nb);
int my_put_point(unsigned int nb);
int unknow_flag(char *str, int count);
int display(char *str);
int my_put_maj_hexa_has(unsigned int nb);
int my_put_hexa_has(unsigned int nb);
int my_printf(const char *s, ...);
