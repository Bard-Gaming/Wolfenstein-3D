/*
** EPITECH PROJECT, 2025
** Project - Carpet Lib
** File description:
** Implementation for
** crpt_object_create
*/

#include <carpet/object.h>
#include <carpet/memory.h>
#include <stdlib.h>


/*
** Default object creation function.
** This allocates memory, so it shouldn't
** be used when trying to create a non-default
** object that inherits from the object structure.
*/
object_t *crpt_object_create(const texture_t *texture, vec2_t pos)
{
    object_t *object = cmalloc(sizeof(object_t));

    object->texture = texture;
    object->update = NULL;
    object->free = free;
    crpt_object_set_position(object, pos);
    return object;
}
