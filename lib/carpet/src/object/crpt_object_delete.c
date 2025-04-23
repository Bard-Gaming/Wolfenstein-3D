/*
** EPITECH PROJECT, 2025
** Project - Carpet Lib
** File description:
** Implementation for
** crpt_object_delete
*/

#include <carpet/object.h>
#include <carpet/scene.h>
#include <carpet/game.h>
#include <carpet/map.h>
#include <stdlib.h>


/*
** Frees the memory allocated to
** store a Carpet Lib map object.
*/
void crpt_object_delete(object_t *object)
{
    if (object == NULL)
        return;
    if (object->map != NULL)
        crpt_map_remove(object->map, object);
    free(object);
}
