/*
** EPITECH PROJECT, 2025
** Project - Carpet Lib
** File description:
** Implementation for
** crpt_camera_get_fov
*/

#include <carpet/camera.h>
#include <carpet/game.h>


/*
** Sets the camera's fov to the
** given value.
*/
double crpt_camera_get_fov(void)
{
    camera_t *cam = &crpt_game_get()->camera;

    return cam->fov;
}
