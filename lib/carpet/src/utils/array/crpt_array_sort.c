/*
** EPITECH PROJECT, 2025
** Project - Carpet Lib
** File description:
** Implementation for
** crpt_array_sort
*/

#include <carpet/utils/array.h>


/*
** Gets the index of the minimum value
** starting at the given index.
*/
static size_t get_min_index(crpt_array_t *array, size_t start, cmp_fnc_t cmp)
{
    size_t min = start;

    for (size_t i = start + 1; i < array->count; i++) {
        if (cmp(array->data[min], array->data[i]) > 0)
            min = i;
    }
    return min;
}

/*
** Sorts the given array using the given
** function to compare elements.
** This uses a simple selection sort.
*/
void crpt_array_sort(crpt_array_t *array, cmp_fnc_t cmp)
{
    size_t min_index;
    void *buf;

    for (size_t i = 0; i < array->count; i++) {
        min_index = get_min_index(array, i, cmp);
        buf = array->data[i];
        array->data[i] = array->data[min_index];
        array->data[min_index] = buf;
    }
}
