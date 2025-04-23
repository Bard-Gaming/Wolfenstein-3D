/*
** EPITECH PROJECT, 2025
** Project - Carpet Lib
** File description:
** Implementation for
** crpt_array_reserve
*/

#include <carpet/utils/array.h>
#include <carpet/memory.h>


/*
** Ensures the given array has at least
** <count> slots reserved in its data buffer.
** If count <= array->capacity, this function
** does nothing.
*/
void crpt_array_reserve(crpt_array_t *array, size_t count)
{
    if (array->capacity >= count)
        return;
    array->data = crealloc(array->data, count * sizeof(void *));
    array->capacity = count;
}
