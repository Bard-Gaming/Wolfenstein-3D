/*
** EPITECH PROJECT, 2025
** Project - Wolf3D
** File description:
** Implementation for
** set_level_scene
*/

#include <wolf/scenes.h>


/*
** Sets the game's scene to the level.
*/
void set_level_scene(void)
{
    static scene_t level = {
        .load = load_level_scene,
        .unload = unload_level_scene,
        .update = update_level_scene,
        .draw_ui = draw_level_scene_ui,
    };

    crpt_scene_set(&level);
}
