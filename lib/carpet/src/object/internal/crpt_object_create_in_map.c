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
#include <stdlib.h>


/*
** Creates a new object in the
** given map (as specified by the
** position). This removes the object
** that was previously on the given
** position.
**
** Technical Addendum:
** Don't use crpt_object_delete here,
** as we are replacing the value in
** the map anyways.
*/
object_t *crpt_object_create_in_map(map_t *map, vec2_t pos, object_type_t t)
{
    object_t *obj = ccalloc(1, sizeof(object_t));
    object_t *old = crpt_map_get(map, pos);

    obj->position = pos;
    obj->type = t;
    obj->color = t == OT_ROOM ? sfMagenta : sfWhite;
    free(old);
    crpt_map_add(map, obj);
    return obj;
}
