/*
** EPITECH PROJECT, 2025
** Project - Carpet Lib
** File description:
** Implementation for
** crpt_map_cell_coords
*/

#include <carpet/map.h>


/*
** Computes the coordinates of the
** cell that is located at the given
** position.
**
** Example (for cell size = 32):
** { 35.2, 68.2 } -> { 32.0, 64.0 }
*/
vec2_t crpt_map_cell_coords(const map_t *map, vec2_t position)
{
    size_t x = position.x / map->cell_size;
    size_t y = position.y / map->cell_size;

    return (vec2_t){
        .x = x * map->cell_size,
        .y = y * map->cell_size,
    };
}
