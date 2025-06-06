/*
** EPITECH PROJECT, 2025
** Project - Carpet Lib
** File description:
** Implementation for
** crpt_map_create
*/

#include <carpet/map.h>
#include <carpet/memory.h>


/*
** Creates a map of the given dimensions.
**
** Returns NULL if the given width or height
** is 0.
*/
map_t *crpt_map_create(unsigned int width, unsigned int height)
{
    map_t *map;

    if (width == 0 || height == 0)
        return NULL;
    map = cmalloc(sizeof(map_t));
    *map = (map_t){
        .cell_size = CRPT_DEFAULT_CUBE_SIZE,
        .tile_size = CRPT_DEFAULT_TILE_SIZE,
        .width = width, .height = height,
        .cells = cmalloc(height * sizeof(map_cell_t *)),
        .objects = { 0 },
    };
    for (unsigned int row = 0; row < height; row++)
        map->cells[row] = ccalloc(width, sizeof(map_cell_t));
    return map;
}
