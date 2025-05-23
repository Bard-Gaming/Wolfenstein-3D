/*
** EPITECH PROJECT, 2025
** Project - Carpet Lib
** File description:
** Implementation for
** crpt_array_empty
*/

#include <carpet/utils/array.h>
#include <string.h>
#include <stdlib.h>


/*
** Deletes the data contained within the array.
*/
static void delete_data(crpt_array_t *array, free_fnc_t delete)
{
    for (size_t i = 0; i < array->count; i++)
        delete(array->data[i]);
}

/*
** Empties the array, resetting it
** to a state with no elements. If you intend
** to reuse the array, this function is better
** than deleting the array, as this doesn't waste
** the already allocated space.
*/
void crpt_array_empty(crpt_array_t *array, free_fnc_t delete)
{
    if (delete != NULL)
        delete_data(array, delete);
    free(array->data);
    array->count = 0;
}
