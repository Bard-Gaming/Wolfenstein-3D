/*
** EPITECH PROJECT, 2025
** Project - Carpet Lib
** File description:
** Implementation for
** crpt_ray_hitscan_object
*/

#include <carpet/ray.h>
#include <carpet/map.h>
#include <carpet/game.h>
#include <carpet/object.h>
#include <carpet/utils/math.h>
#include <carpet/utils/vector.h>


/*
** Determines whether or not a given
** object is in the specified range.
*/
static bool is_in_range(const object_t *obj, vec2_t min, vec2_t max)
{
    return
        (min.x <= obj->position.x && obj->position.x <= max.x) &&
        (min.y <= obj->position.y && obj->position.y <= max.y);
}

/*
** Returns the closest object that is located
** at the given position. If no object is at
** the specified position, NULL is returned
** instead.
*/
static object_t *object_at_position(const map_t *map, vec2_t pos, ssize_t type)
{
    vec2_t min = { pos.x - CRPT_RAY_THRESHOLD, pos.y - CRPT_RAY_THRESHOLD };
    vec2_t max = { pos.x + CRPT_RAY_THRESHOLD, pos.y + CRPT_RAY_THRESHOLD };
    object_t *obj;

    for (size_t i = 0; i < map->objects.count; i++) {
        obj = map->objects.data[i];
        if (type >= 0 && obj->type != type)
            continue;
        if (is_in_range(obj, min, max))
            return obj;
    }
    return NULL;
}

/*
** Shoots a ray with the given rotation.
** If the given ray hits an object, a pointer
** to the object is returned. If no object is
** hit, NULL is returned.
** If the given object type (t) is negative,
** then the hitscan will ignore the type of
** the scanned object.
*/
object_t *crpt_ray_hitscan_object(const map_t *map, double angle, ssize_t type)
{
    vec2_t direction = { cos(angle), - sin(angle) };
    vec2_t current = *crpt_camera_get_position();
    object_t *obj;

    while (!crpt_map_is_solid(map, current)) {
        obj = object_at_position(map, current, type);
        if (obj != NULL)
            return obj;
        current = crpt_vec2_add(current, direction);
    }
    return NULL;
}
