/*
** EPITECH PROJECT, 2025
** Project - Carpet Lib
** File description:
** Implementation for
** crpt_camera_get_rotation
*/

#include <carpet/camera.h>
#include <carpet/game.h>


/*
** Returns the normalized rotation
** angle stored within the camera.
*/
double crpt_camera_get_rotation(void)
{
    camera_t *cam = &crpt_game_get()->camera;

    return cam->rotation;
}
