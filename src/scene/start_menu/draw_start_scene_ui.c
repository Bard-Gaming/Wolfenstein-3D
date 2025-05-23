/*
** EPITECH PROJECT, 2025
** Project - Wolf3D
** File description:
** Implementation for
** draw_start_scene_ui
*/

#include <wolf/scenes.h>
#include <wolf/player.h>
#include <wolf/scenes.h>
#include <carpet/assets.h>

/**
 * Draws the start menu UI: background, logo, and buttons.
 */
void draw_start_scene_ui(scene_t *scene, window_t *window)
{
    sprite_t *sprite;
    const char *sprites[] = {
        "start_bg",
        "logo",
        "btn_start",
        "btn_settings"
    };

    (void)scene;
    (void)window;
    for (long unsigned int i = 0; i <
            sizeof(sprites) / sizeof(sprites[0]); i++) {
        sprite = crpt_fetch_sprite(sprites[i]);
        if (sprite)
            crpt_draw_sprite(sprite);
    }
}
