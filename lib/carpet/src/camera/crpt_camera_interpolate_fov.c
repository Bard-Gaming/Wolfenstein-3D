/*
** EPITECH PROJECT, 2025
** Project - Carpet Lib
** File description:
** Implementation for
** crpt_camera_interpolate_fov
*/

#include <carpet/camera.h>
#include <carpet/game.h>


/*
** Determines if the end condition of
** the interpolation has been reached
** or not.
*/
static bool is_at_end(const camera_t *cam, double end, double step)
{
    return
        (step > 0.0 && cam->fov > end) ||
        (step < 0.0 && cam->fov < end) ||
        (step == 0.0);
}

/*
** Interpolates the FOV to the given end
** value.
** This essentially applies step to the
** FOV every time this function is called,
** until the end is reached.
*/
void crpt_camera_interpolate_fov(double end, double step)
{
    camera_t *cam = &crpt_game_get()->camera;

    if (is_at_end(cam, end, step))
        return;
    cam->fov += step;
}
