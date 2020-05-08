/*
** EPITECH PROJECT, 2019
** my_sort_int_array
** File description:
** sort an array
*/

void my_putchar(char c);

void my_sort_int_array(int *array, int size)
{
    int new_array[size];
    int until_done = size;
    int temp_holder = 0;

    while (until_done > 0) {
        for (int i = 0; i < size; i++) {
            if (array[i] > array[i + 1]) {
                temp_holder = array[i];
                array[i] = array[i + 1];
                array[i + 1] = temp_holder;
            }
        }
        until_done--;
    }
}
