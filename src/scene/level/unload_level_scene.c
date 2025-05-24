/*
** EPITECH PROJECT, 2025
** Project - Wolf3D
** File description:
** Implementation for
** unload_level_scene
*/

#include <wolf/scenes.h>
#include <wolf/player.h>


/*
** Unloads the level's scene.
*/
void unload_level_scene(scene_t *scene)
{
    crpt_unload_texture("bricks");
    crpt_unload_texture("hb_full");
    crpt_unload_texture("hb_empty");
    unload_player_assets();
    crpt_map_delete(scene->map);
    scene->map = NULL;
}
