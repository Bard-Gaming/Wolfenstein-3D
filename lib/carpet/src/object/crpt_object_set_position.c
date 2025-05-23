/*
** EPITECH PROJECT, 2025
** Project - Carpet Lib
** File description:
** Implementation for
** crpt_object_set_position
*/

#include <carpet/object.h>
#include <carpet/game.h>


/*
** Sets the object's position to the
** position specified by new. This also
** updates the object's distance to the
** camera, which is why this function should
** be called instead of manually changing the
** position.
*/
void crpt_object_set_position(object_t *object, vec2_t new)
{
    object->position = new;
}
