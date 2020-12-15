/*
** EPITECH PROJECT, 2020
** my_sort_int_array
** File description:
** sorting int from an array
*/

#include <stdbool.h>

bool array_is_sort(int *array, int size)
{
    int i = 0;

    while (i != size) {
        if (array[i] > array[i + 1])
            return (false);
        i++;
    }
    return (true);
}

void my_sort_int_array(int *array, int size)
{
    int i = 0;
    int pivot = 0;

    while (array_is_sort(array, size) == false) {
        if (array[i] > array[i + 1]) {
            pivot = array[i];
            array[i] = array[i + 1];
            array[i + 1] = pivot;
            i = 0;
        }
        else
            i++;
    }
}
