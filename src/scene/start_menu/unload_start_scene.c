/*
** EPITECH PROJECT, 2025
** Project - Wolf3D
** File description:
** Implementation for
** unload_start_scene
*/

#include <wolf/scenes.h>


/*
** Unloads the start scene.
*/
void unload_start_scene(scene_t *scene)
{
    crpt_unload_texture("bricks");
    crpt_unload_texture("hb_full");
    crpt_unload_texture("hb_empty");
    crpt_map_delete(scene->map);
}
