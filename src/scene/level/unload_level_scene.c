/*
** EPITECH PROJECT, 2025
** Project - Wolf3D
** File description:
** Implementation for
** unload_level_scene
*/

#include <wolf/scenes.h>


/*
** Unloads the level's scene.
*/
void unload_level_scene(scene_t *scene)
{
    crpt_map_delete(scene->map);
    scene->map = NULL;
}
