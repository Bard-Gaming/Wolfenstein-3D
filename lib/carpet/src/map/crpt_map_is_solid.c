/*
** EPITECH PROJECT, 2025
** Project - Carpet Lib
** File description:
** Implementation for
** crpt_map_is_solid
*/

#include <carpet/map.h>
#include <carpet/utils/vector.h>


/*
** Determines whether or a solid cube
** is located at a given position or
** not.
*/
bool crpt_map_is_solid(const map_t *map, vec2_t position)
{
    map_cell_t *cell = crpt_map_get_cell(map, position);

    return cell != NULL && cell->type == MCT_WALL;
}
