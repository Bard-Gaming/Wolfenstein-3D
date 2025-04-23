/*
** EPITECH PROJECT, 2025
** Project - Carpet Lib
** File description:
** Implementation for
** crpt_map_delete
*/

#include <carpet/map.h>
#include <carpet/object.h>
#include <stdlib.h>


/*
** Frees all of the allocated memory
** stored within a map.
*/
void crpt_map_delete(map_t *map)
{
    for (unsigned int row = 0; row < map->height; row++) {
        for (unsigned int col = 0; col < map->width; col++)
            crpt_object_delete(map->blocks[row][col]);
        free(map->blocks[row]);
    }
    free(map->blocks);
    free(map);
}
