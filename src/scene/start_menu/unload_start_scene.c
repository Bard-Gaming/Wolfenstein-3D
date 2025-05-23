/*
** EPITECH PROJECT, 2025
** Project - Wolf3D
** File description:
** Implementation for
** unload_start_scene
*/

#include <wolf/scenes.h>
#include <carpet/assets.h>

/**
 * Unloads all sprites related to the start menu.
 */
void unload_start_scene(scene_t *scene)
{
    const char *sprites[] = {
        "start_bg",
        "logo",
        "btn_start",
        "btn_settings",
    };

    (void)scene;
    for (long unsigned int i = 0;
            i < sizeof(sprites) / sizeof(sprites[0]); i++)
        crpt_unload_sprite(sprites[i]);
}
