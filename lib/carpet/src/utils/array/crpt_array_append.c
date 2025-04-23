/*
** EPITECH PROJECT, 2025
** Project - Carpet Lib
** File description:
** Implementation for
** crpt_array_append
*/

#include <carpet/utils/array.h>
#include <carpet/memory.h>


/*
** Appends an element to the array,
** dynamically growing the array's capacity
** when necessary.
*/
void crpt_array_append(crpt_array_t *array, void *data)
{
    if (array->count == array->capacity) {
        array->capacity = array->capacity ?
            CRPT_ARRAY_INIT_CAP : CRPT_ARRAY_GROWTH * array->capacity;
        array->data = crealloc(array->data, array->capacity * sizeof(void *));
    }
    array->data[array->count] = data;
    array->count++;
}
