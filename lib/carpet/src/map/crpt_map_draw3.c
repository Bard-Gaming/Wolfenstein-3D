/*
** EPITECH PROJECT, 2025
** Project - Carpet Lib
** File description:
** Implementation for
** crpt_map_draw3
*/

#include <carpet/map.h>
#include <carpet/object.h>
#include <carpet/game.h>
#include <carpet/ray.h>



/*
** Casts a ray and draws the resulting vertical line on
** the screen.
** If the ray doesn't hit anything, this function does
** nothing.
*/
static void draw_raycast(const map_t *map, const camera_t *cam,
    unsigned int x, double angle)
{
    ray_t ray = crpt_raycast(cam->position, angle, map);

    crpt_ray_draw3(ray, x, map, cam);
}

/*
** Draws the 3D view of a map with a
** given camera's settings.
**
** Note: the projection distance is
** assumed to be 1.0.
*/
void crpt_map_draw3(const map_t *map, const camera_t *cam, window_t *window)
{
    const unsigned int ray_count = sfRenderWindow_getSize(window).x;
    const double half_width = tan(cam->fov / 2);
    double angle;
    double x;

    for (unsigned int i = 0; i < ray_count; i++) {
        x = (2.0 * (i / (ray_count - 1.0)) - 1.0) * half_width;
        angle = norm(atan2(x, 1.0) + cam->rotation);
        draw_raycast(map, cam, i, angle);
    }
}
