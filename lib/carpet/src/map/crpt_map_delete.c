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
** Deletes the map's object array and all
** of its contained data.
*/
static void delete_objects(crpt_array_t *objects)
{
    object_t *object;

    for (size_t i = 0; i < objects->count; i++) {
        object = objects->data[i];
        if (object->free != NULL)
            object->free(object);
    }
    crpt_array_delete(objects, NULL);
}

/*
** Frees all of the allocated memory
** stored within a map.
*/
void crpt_map_delete(map_t *map)
{
    for (unsigned int row = 0; row < map->height; row++)
        free(map->cells[row]);
    delete_objects(&map->objects);
    free(map->cells);
    free(map);
}
