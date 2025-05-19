/*
** EPITECH PROJECT, 2025
** Project - Carpet Lib
** File description:
** Implementation for
** crpt_object_dup_in_map
*/

#include <carpet/object.h>
#include <carpet/map.h>


/*
** Duplicates the given object at
** the new position in the given map.
*/
object_t *crpt_object_dup_in_map(const object_t *ref, map_t *map, vec2_t pos)
{
    object_t *obj = crpt_object_create_in_map(map, pos, ref->type);

    obj->color = ref->color;
    obj->texture = ref->texture;
    return obj;
}
