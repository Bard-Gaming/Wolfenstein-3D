/*
** EPITECH PROJECT, 2025
** Project - Carpet Lib
** File description:
** Implementation for
** crpt_map_fill_empty
*/

#include <carpet/map.h>


/*
** Fills the given slot with the reference
** if the given slot is empty.
** Does nothing otherwise.
*/
static void fill_map(map_t *map, size_t x, size_t y, const map_cell_t *ref)
{
    if (map->cells[y][x].type != MCT_EMPTY)
        return;
    map->cells[y][x] = *ref;
}

/*
** Fills all empty slots of the map with the
** given reference.
*/
void crpt_map_fill_empty(map_t *map, const map_cell_t *ref)
{
    for (size_t y = 0; y < map->height; y++)
        for (size_t x = 0; x < map->width; x++)
            fill_map(map, x, y, ref);
}
