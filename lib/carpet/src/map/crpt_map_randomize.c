/*
** EPITECH PROJECT, 2025
** Project - Carpet Lib
** File description:
** Implementation for
** crpt_map_randomize
*/

#include <carpet/map.h>
#include <carpet/object.h>
#include <carpet/utils/math.h>


/*
** Randomly Fills the map with (at most)
** <count> walls.
** This function will never place walls on the
** border of the map.
*/
void crpt_map_randomize(map_t *map, size_t count)
{
    size_t x;
    size_t y;
    vec2_t pos;
    object_t *obj;

    for (size_t i = 0; i < count; i++) {
        x = crpt_rand(map->width - 2) + 1;
        y = crpt_rand(map->height - 2) + 1;
        pos = (vec2_t){ x * map->cube_size, y * map->cube_size };
        obj = crpt_object_create_in_map(map, pos, OT_WALL);
        obj->color = sfBlue;
    }
}
