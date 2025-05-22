/*
** EPITECH PROJECT, 2025
** Project - Carpet Lib
** File description:
** Implementation for
** crpt_map_get_wall
*/

#include <carpet/map.h>
#include <carpet/utils/vector.h>


/*
** Retrieves the pointer to a wall within the
** map, as specified by the given position
** vector.
** Note that depending on the given position,
** the returned wall may be NULL.
*/
map_cell_t *crpt_map_get_cell(const map_t *map, vec2_t position)
{
    size_t x = (size_t)position.x / map->cell_size;
    size_t y = (size_t)position.y / map->cell_size;

    return x >= map->width || y >= map->height ?
        NULL : map->cells[y] + x;
}
