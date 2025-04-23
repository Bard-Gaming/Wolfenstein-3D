/*
** EPITECH PROJECT, 2025
** Project - Carpet Lib
** File description:
** Implementation for
** crpt_scene_default_load
*/

#include <carpet/scene.h>
#include <carpet/object.h>
#include <carpet/memory.h>
#include <carpet/map.h>


/*
** Default scene's load function.
*/
void crpt_scene_default_load(scene_t *scene)
{
    object_t border = {
        .color = sfRed, .draw_solid = true,
    };

    scene->map = crpt_map_create(50, 50);
    crpt_map_create_border(scene->map, &border);
    crpt_map_randomize(scene->map, 20);
}
