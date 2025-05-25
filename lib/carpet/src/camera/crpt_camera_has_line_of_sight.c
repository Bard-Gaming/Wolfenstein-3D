/*
** EPITECH PROJECT, 2025
** Project - Carpet Lib
** File description:
** Implementation for
** crpt_camera_has_line_of_sight
*/

#include <carpet/camera.h>
#include <carpet/game.h>
#include <carpet/scene.h>
#include <carpet/map.h>


/*
** Determines whether or not the camera can see
** from its location to the specified position.
** This requires a map to be loaded.
*/
bool crpt_camera_has_line_of_sight(vec2_t pos)
{
    game_t *game = crpt_game_get();
    camera_t *cam = &game->camera;
    const map_t *map = game->scene->map;
    vec2_t direction = crpt_vec2_sub(cam->position, pos);
    double distance = crpt_vec2_magnitude(direction);
    vec2_t current = pos;

    if (map == NULL)
        return false;
    if (distance <= 0.1)
        return true;
    direction = crpt_vec2_scale(direction, 16.0 / distance);
    for (double traversed = 0.0; traversed < distance; traversed += 16.0) {
        if (crpt_map_is_solid(map, current))
            return false;
        current = crpt_vec2_add(current, direction);
    }
    return true;
}
