/*
** EPITECH PROJECT, 2025
** Project - Carpet Lib
** File description:
** Implementation for
** crpt_map_remove
*/

#include <carpet/map.h>
#include <carpet/object.h>


/*
** Removes an object from the given
** map.
*/
void crpt_map_remove(map_t *map, object_t *obj)
{
    size_t x = (size_t)obj->position.x / map->cube_size;
    size_t y = (size_t)obj->position.y / map->cube_size;

    if (x >= map->width || y >= map->height)
        return;
    if (map->blocks[y][x] != obj)
        return;
    obj->map = NULL;
    map->blocks[y][x] = NULL;
}
