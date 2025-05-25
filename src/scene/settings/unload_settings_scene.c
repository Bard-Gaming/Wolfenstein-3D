/*
** EPITECH PROJECT, 2025
** Project - Wolf3D
** File description:
** Implementation for
** unload_settings_scene
*/

#include <wolf/scenes.h>


static const char *widget_ids[] = {
    "settings_bg",
    "forward_key",
    "backward_key",
    "left_key",
    "right_key",
    "sound_toggle",
    "music_toggle",
    "back_button"
};

static void unload_widget(const char *id)
{
    crpt_unload_sprite(id);
    crpt_unload_texture(id);
}

void unload_settings_scene(scene_t *scene)
{
    (void)scene;
    for (unsigned int i = 0; i <
            sizeof(widget_ids) / sizeof(widget_ids[0]); i++) {
        unload_widget(widget_ids[i]);
    }
    free(scene->data);
}
