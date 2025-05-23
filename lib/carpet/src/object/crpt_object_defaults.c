/*
** EPITECH PROJECT, 2025
** Project - Carpet Lib
** File description:
** Implementation for
** crpt_object_defaults
*/

#include <carpet/object.h>
#include <stdlib.h>
#include <string.h>


/*
** Intializes the given object with the
** default values.
*/
void crpt_object_defaults(object_t *object)
{
    memset(object, 0, sizeof(object_t));
    object->free = free;
}
