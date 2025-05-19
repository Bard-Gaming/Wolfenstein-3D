/*
** EPITECH PROJECT, 2025
** Project - Carpet Lib
** File description:
** Implementation for
** crpt_map_is_solid
*/

#include <carpet/map.h>
#include <carpet/object.h>
#include <carpet/utils/vector.h>


/*
** Determines whether or a solid cube
** is located at a given position or
** not.
*/
bool crpt_map_is_solid(const map_t *map, vec2_t position)
{
    object_t *object = crpt_map_get(map, position);

    return object != NULL && object->type == OT_WALL;
}
