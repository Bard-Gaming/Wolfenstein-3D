/*
** EPITECH PROJECT, 2025
** Project - Carpet Lib
** File description:
** Implementation for
** crpt_array_delete
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
** Frees all of the data associated
** with the given array using the given
** delete function.
*/
void crpt_array_delete(crpt_array_t *array, free_fnc_t delete)
{
    if (delete != NULL)
        delete_data(array, delete);
    free(array->data);
    memset(array, 0, sizeof(crpt_array_t));
}
