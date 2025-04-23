/*
** EPITECH PROJECT, 2025
** Project - Carpet Lib
** File description:
** Implementation for
** crpt_scene_default_unload
*/

#include <carpet/scene.h>
#include <carpet/map.h>


/*
** Default scene's unload function.
*/
void crpt_scene_default_unload(scene_t *scene)
{
    crpt_map_delete(scene->map);
    scene->map = NULL;
}
