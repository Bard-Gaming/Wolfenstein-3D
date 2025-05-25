/*
** EPITECH PROJECT, 2025
** Project - Wolf3D
** File description:
** Implementation for
** draw_settings_scene_ui
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

static void draw_widget(const char *id)
{
    sprite_t *sprite = crpt_fetch_sprite(id);

    crpt_draw_sprite(sprite);
}

void draw_settings_scene_ui(scene_t *scene, window_t *window)
{
    (void)scene;
    (void)window;
    for (unsigned int i = 0; i <
            sizeof(widget_ids) / sizeof(widget_ids[0]); i++) {
        draw_widget(widget_ids[i]);
    }
}
