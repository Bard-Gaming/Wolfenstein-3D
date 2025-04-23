/*
** EPITECH PROJECT, 2025
** Project - Carpet Lib
** File description:
** Implementation for
** crpt_object_dup
*/

#include <carpet/object.h>


/*
** Duplicates the given object at
** the new position.
*/
object_t *crpt_object_dup(const object_t *reference, vec2_t pos)
{
    return crpt_object_dup_in_map(reference, reference->map, pos);
}
