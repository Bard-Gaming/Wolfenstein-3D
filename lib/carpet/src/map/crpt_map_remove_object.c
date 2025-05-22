/*
** EPITECH PROJECT, 2025
** Project - Carpet Lib
** File description:
** Implementation for
** crpt_map_remove_object
*/

#include <carpet/map.h>
#include <carpet/object.h>


/*
** Removes an object from the given
** map. This uses a swap-and-pop for
** efficiency, meaning the order
** of the elements in the map's object
** buffer won't be ordered properly after
** this.
*/
void crpt_map_remove_object(map_t *map, object_t *object)
{
    object_t *last_obj = map->objects.data[map->objects.count - 1];

    map->objects.data[object->index] = last_obj;
    map->objects.count--;
}
