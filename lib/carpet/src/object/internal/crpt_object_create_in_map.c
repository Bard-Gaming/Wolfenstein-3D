/*
** EPITECH PROJECT, 2025
** Project - Carpet Lib
** File description:
** Implementation for
** crpt_object_create_in_map
*/

#include <carpet/object.h>
#include <carpet/memory.h>
#include <carpet/map.h>


/*
** Creates a new object in the
** given map (as specified by the
** position).
*/
object_t *crpt_object_create_in_map(map_t *map, vec2_t pos)
{
    object_t *obj = ccalloc(1, sizeof(object_t));

    obj->position = pos;
    obj->color = sfBlue;
    obj->draw_solid = true;
    crpt_map_add(map, obj);
    return obj;
}
