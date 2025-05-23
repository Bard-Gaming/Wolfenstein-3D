/*
** EPITECH PROJECT, 2025
** Project - Carpet Lib
** File description:
** Implementation for
** crpt_object_move
*/

#include <carpet/object.h>
#include <carpet/game.h>


/*
** Moves the object by the given offset.
*/
void crpt_object_move(object_t *object, vec2_t offset)
{
    camera_t *cam = &crpt_game_get()->camera;

    object->position.x += offset.x;
    object->position.y += offset.y;
    object->cam_dist = crpt_vec2_distance(
        object->position,
        cam->position
    );
}
