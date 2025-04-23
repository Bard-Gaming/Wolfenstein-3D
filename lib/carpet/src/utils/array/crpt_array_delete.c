/*
** EPITECH PROJECT, 2025
** Project - Carpet Lib
** File description:
** Implementation for
** crpt_array_delete
*/

#include <carpet/utils/array.h>
#include <string.h>


/*
** Frees the memory attached to a
** given array, and resets the given
** array to a reusable state.
** This means that the function does
** not free the given pointer itself.
*/
void crpt_array_delete(crpt_array_t *array, free_fnc_t free)
{
    for (size_t i = 0; i < array->count; i++)
        free(array->data[i]);
    memset(array, 0, sizeof(crpt_array_t));
}
