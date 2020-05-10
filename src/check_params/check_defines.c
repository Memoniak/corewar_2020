#include "op.h"

int check_label_chars(char *name)
{
    int len_chars = my_strlen(LABEL_CHARS);
    int x = 0;

    for (int i = 0; name[i]; i++) {
        x = 0;
        for (; x < len_chars; x++) {
            if (name[i] == LABEL_CHARS[x])
                break;
        }
        if (x == len_chars)
            return 1;
    }
    return 0;
}

int check_label_name(char *name, funct_t *labels)
{
    int i = 0;

    if (check_label_chars(name))
        return 1;
    while (i < labels[0].len)
    {
        if(!my_strcmp(labels[i].name, name))
            break;
        i++;
    }
    if (i == labels[0].len)
        return 1;
    return 0;
}

int check_value_dir(char *value, funct_t *labels)
{
    if (!is_num(value[0]))
        return 1;
    for (size_t i = 1; value[i]; i++) {
        if (is_num(value[i]) != 1)
            return 1;
    }
    return 0;
}

int check_value_ind(char *value, funct_t *labels)
{
    for (size_t i = 0; value[i]; i++) {
        if (is_num(value[i]) != 1)
            return 1;
    }
    return 0;
}