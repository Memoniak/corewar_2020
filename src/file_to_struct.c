/*
** EPITECH PROJECT, 2020
** file_to_struct
** File description:
** reads the file and creates a structure
*/

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>

typedef struct {
    int code;
    char *param1;
    char *param2;
    char *param3;
    char *param4;
} cmd_t;

typedef struct {
    cmd_t *commands;
    char *name;
} funct_t;

typedef struct {
    char **file_header;
    char *name;
    char *comment;
} champion_info_t;

size_t get_file_len(char const *filepath)
{
    FILE *fd = fopen(filepath, "r");
    char *buff = NULL;
    size_t first = 0;
    size_t len = 0;
    int res = 0;

    for (; res != -1; len++) {
        res = getline(&buff, &first, fd);
    }
    if (buff)
        free(buff);
    if (fd)
        fclose(fd);
    if (first <= 0 || len == 0)
        return 0;
    return --len;
}

char **get_file_ar(char const *filepath)
{
    FILE *fd = fopen(filepath, "r");
    size_t size = 0;
    int res = 1;
    char **arr_file = NULL;
    int len = get_file_len(filepath);

    if (len <= 0 || !fd)
        return NULL;
    arr_file = malloc(sizeof(char *) * (len + 1));
    arr_file[len] = NULL;
    for (int i = 0; i < len; i++) {
        arr_file[i] = NULL;
        res = getline(&arr_file[i], &size, fd);
        arr_file[i][res] = '\0';
        if (res == -1 || !arr_file[i])
            break;
    }
    fclose(fd);
    return arr_file;
}

int get_code(int cmd_code, const cmd_t *op_tab)
{
    int i = 0;

    while(cmd_code != op_tab[i].code && i < 16)
        i++;
    if (i >= 16)
        return -1;
    else
        return i;
}

void fill_champion_info(champion_info_t *champ, char **file_arr)
{
    int i = 0;

    while (*(file_arr[0])++ != '.' && *(file_arr[0]) != '\0' && *(file_arr[0]) != '\n');
    *(file_arr[0])--;
    if (!my_strncmp(file_arr[0], ".name", 5)) {
        champ->name = get_string_inbetween(file_arr[0], '"');
    }
    while (*(file_arr[1])++ != '.' && *(file_arr[1]) != '\0' && *(file_arr[1]) != '\n');
    if (!my_strncmp(file_arr[1], ".comment", 7))
       champ->comment = get_string_inbetween(file_arr[1], '"');
}

cmd_t *make_struct(char const *filepath, champion_info_t *champion_info)
{
    char **file_arr = get_file_ar(filepath);
    funct_t *functions;
    size_t len = get_dbl_arr_len(file_arr);

    fill_champion_info(champion_info, file_arr);

    return functions;
}

int main(int ac, char **av)
{
    champion_info_t champ;
    make_struct(av[1], &champ);
    return 0;
}
