/*
** EPITECH PROJECT, 2025
** Project - Carpet Lib
** File description:
** Implementation for
** crpt_camera_get_position
*/

#include <carpet/camera.h>
#include <carpet/game.h>


/*
** Returns a pointer to the camera's
** position.
** The position can be freely changed,
** and the change will be reflected in
** the game.
** The return value is guaranteed to be
** a valid, non-null pointer.
*/
vec2_t *crpt_camera_get_position(void)
{
    camera_t *cam = &crpt_game_get()->camera;

    return &cam->position;
}
