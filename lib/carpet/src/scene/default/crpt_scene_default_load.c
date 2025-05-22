/*
** EPITECH PROJECT, 2025
** Project - Carpet Lib
** File description:
** Implementation for
** crpt_scene_default_load
*/

#include <carpet/scene.h>
#include <carpet/memory.h>
#include <carpet/map.h>


/*
** Default scene's load function.
*/
void crpt_scene_default_load(scene_t *scene)
{
    map_cell_t border = { .type = MCT_WALL, .color = sfGreen };
    map_cell_t walls = { .type = MCT_WALL, .color = sfBlue };
    map_cell_t room = { .type = MCT_EMPTY, .color = sfWhite };

    scene->map = crpt_map_create(50, 50);
    crpt_map_create_border(scene->map, &border);
    crpt_map_randomize(scene->map, 20, &walls);
    crpt_map_fill_empty(scene->map, &room);
}
