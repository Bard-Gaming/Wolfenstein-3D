/*
** EPITECH PROJECT, 2025
** Project - Carpet Lib
** File description:
** Implementation for
** crpt_map_create_border
*/

#include <carpet/map.h>


/*
** Creates a border around the given map.
** The border will be filled with duplicates
** of the given reference object, and won't
** override any existing solid walls.
*/
void crpt_map_create_border(map_t *map, const map_cell_t *ref)
{
    for (unsigned int x = 0; x < map->width; x++) {
        map->cells[0][x] = *ref;
        map->cells[map->height - 1][x] = *ref;
    }
    for (unsigned int y = 1; y < map->height - 1; y++) {
        map->cells[y][0] = *ref;
        map->cells[y][map->width - 1] = *ref;
    }
}
