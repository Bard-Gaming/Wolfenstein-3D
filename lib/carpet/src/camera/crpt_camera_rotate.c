/*
** EPITECH PROJECT, 2025
** Project - Carpet Lib
** File description:
** Implementation for
** crpt_camera_rotate
*/

#include <carpet/camera.h>
#include <carpet/game.h>
#include <carpet/utils/math.h>


/*
** Rotates the camera by the given
** amount. The user of this function
** doesn't have to worry about normalising
** the angle, as this function already does.
*/
void crpt_camera_rotate(double offset)
{
    camera_t *cam = &crpt_game_get()->camera;

    cam->rotation = norm(cam->rotation + offset);
}
