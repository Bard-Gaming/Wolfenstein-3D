/*
** EPITECH PROJECT, 2025
** Project - Carpet Lib
** File description:
** Implementation for
** crpt_camera_set_fov
*/

#include <carpet/camera.h>
#include <carpet/game.h>


/*
** Sets the camera's fov to the
** given value.
*/
void crpt_camera_set_fov(double new)
{
    camera_t *cam = &crpt_game_get()->camera;

    cam->fov = new;
}
