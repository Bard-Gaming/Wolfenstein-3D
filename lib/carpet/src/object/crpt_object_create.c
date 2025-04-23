/*
** EPITECH PROJECT, 2025
** Project - Carpet Lib
** File description:
** Implementation for
** crpt_object_create
*/

#include <carpet/object.h>
#include <carpet/memory.h>
#include <carpet/errno.h>
#include <carpet/scene.h>
#include <carpet/game.h>
#include <carpet/map.h>
#include <stdlib.h>


/*
** Creates a new object in the
** current scene's map. This results
** in a critical error if the scene
** doesn't contain a map.
*/
object_t *crpt_object_create(vec2_t pos)
{
    map_t *map = crpt_game_get()->scene->map;

    if (map == NULL) {
        crpt_errno_set(CE_OBJECT_NO_MAP);
        crpt_perror("carpet");
        exit(CRPT_CRITICAL_ERROR);
    }
    return crpt_object_create_in_map(map, pos);
}
