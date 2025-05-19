/*
** EPITECH PROJECT, 2025
** Project - Carpet Lib
** File description:
** Implementation for
** crpt_camera_set_rotation
*/

#include <carpet/camera.h>
#include <carpet/game.h>
#include <carpet/utils/math.h>


/*
** Sets the camera's rotation to the
** given value.
** This will normalize the given angle.
*/
void crpt_camera_set_rotation(double new)
{
    camera_t *cam = &crpt_game_get()->camera;

    cam->rotation = norm(new);
}
