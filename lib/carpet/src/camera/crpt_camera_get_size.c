/*
** EPITECH PROJECT, 2025
** Project - Carpet Lib
** File description:
** Implementation for
** crpt_camera_get_size
*/

#include <carpet/camera.h>
#include <carpet/game.h>


/*
** Retrieves the camera's viewport
** size (i.e. window size).
*/
vec2u_t crpt_camera_get_size(void)
{
    camera_t *cam = &crpt_game_get()->camera;

    return (vec2u_t){ cam->width, cam->height };
}
