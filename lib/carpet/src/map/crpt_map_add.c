/*
** EPITECH PROJECT, 2025
** Project - Carpet Lib
** File description:
** Implementation for
** crpt_map_add
*/

#include <carpet/map.h>
#include <carpet/object.h>


/*
** Adds an object to the given
** map (at the object's position).
*/
void crpt_map_add(map_t *map, object_t *obj)
{
    size_t x = (size_t)obj->position.x / map->cube_size;
    size_t y = (size_t)obj->position.y / map->cube_size;

    if (x >= map->width || y >= map->height)
        return;
    obj->map = map;
    map->blocks[y][x] = obj;
}
