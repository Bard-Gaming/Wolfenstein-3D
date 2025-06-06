/*
** EPITECH PROJECT, 2025
** Project - Carpet Lib
** File description:
** Implementation for
** crpt_map_draw3
*/

#include <carpet/map.h>
#include <carpet/game.h>
#include <carpet/ray.h>
#include <carpet/object.h>


/*
** Draws the 3D view of a map with a
** given camera's settings.
**
** Note: the projection distance is
** assumed to be 1.0.
*/
void crpt_map_draw3(const map_t *map, camera_t *cam)
{
    const double half_width = tan(cam->fov / 2);
    double angle;
    ray_t ray;
    double x;

    for (unsigned int i = 0; i < cam->width; i++) {
        x = (2.0 * (i / (cam->width - 1.0)) - 1.0) * half_width;
        angle = norm(atan2(x, 1.0) + cam->rotation);
        ray = crpt_raycast(cam->position, angle, map);
        cam->depth_buffer[i] = crpt_vec2_distance(ray.pos, cam->position);
        crpt_ray_draw3(ray, i, map, cam);
    }
    for (size_t i = 0; i < map->objects.count; i++)
        crpt_object_draw(map->objects.data[i], cam);
}
