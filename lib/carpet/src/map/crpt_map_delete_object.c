/*
** EPITECH PROJECT, 2025
** Project - Carpet Lib
** File description:
** Implementation for
** crpt_map_delete_object
*/

#include <carpet/map.h>
#include <carpet/object.h>


/*
** Does the same thing as _map_remove_object(),
** except that this also frees the memory the object
** takes.
*/
void crpt_map_delete_object(map_t *map, object_t *object)
{
    crpt_map_remove_object(map, object);
    if (object->free != NULL)
        object->free(object);
}
