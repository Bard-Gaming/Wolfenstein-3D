/*
** EPITECH PROJECT, 2025
** Project - Carpet Lib
** File description:
** Implementation for
** crpt_map_create_border
*/

#include <carpet/map.h>
#include <carpet/object.h>


/*
** Creates a border around the given map.
** The border will be filled with duplicates
** of the given reference object, and won't
** override any existing solid walls.
*/
void crpt_map_create_border(map_t *map, const object_t *ref)
{
    double x_pos;
    double y_pos;

    for (unsigned int x = 1; x < map->width - 1; x++) {
        x_pos = x * map->cube_size;
        y_pos = (map->height - 1) * map->cube_size;
        crpt_object_dup_in_map(ref, map, (vec2_t){ x_pos, 0 });
        crpt_object_dup_in_map(ref, map, (vec2_t){ x_pos, y_pos });
    }
    for (unsigned int y = 1; y < map->height - 1; y++) {
        x_pos = (map->width - 1) * map->cube_size;
        y_pos = y * map->cube_size;
        crpt_object_dup_in_map(ref, map, (vec2_t){ 0, y_pos });
        crpt_object_dup_in_map(ref, map, (vec2_t){ x_pos, y_pos });
    }
}
