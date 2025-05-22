/*
** EPITECH PROJECT, 2025
** Project - Carpet Lib
** File description:
** Implementation for
** crpt_map_add_object
*/

#include <carpet/map.h>
#include <carpet/object.h>


/*
** Adds the given object to the map.
**
** Technical Addendum:
** This function also updates the object's
** index field to allow the quick removal of
** the object.
*/
void crpt_map_add_object(map_t *map, object_t *object)
{
    object->index = map->objects.count;
    crpt_array_append(&map->objects, object);
}
