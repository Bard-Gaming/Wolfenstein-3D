/*
** EPITECH PROJECT, 2025
** Project - Wolf3D
** File description:
** Implementation for
** load_settings_scene
*/

#include <wolf/scenes.h>
#include <wolf/player.h>
#include <wolf/settings.h>


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

static const sfVector2f positions[] = {
    { 0.f, 50.f },    // background
    { 850.f, 400.f }, // forward
    { 850.f, 460.f }, // back
    { 850.f, 520.f }, // left
    { 850.f, 580.f }, // right
    { 850.f, 720.f }, // sound toggle
    { 850.f, 800.f }, // music toggle
    { 850.f, 950.f }, // back button
};

static void load_textures(void)
{
    crpt_load_texture(SETTINGS_PATH"settings_bg.png", widget_ids[0]);
    crpt_load_texture(SETTINGS_PATH"forward_key.png", widget_ids[1]);
    crpt_load_texture(SETTINGS_PATH"backward_key.png", widget_ids[2]);
    crpt_load_texture(SETTINGS_PATH"left_key.png", widget_ids[3]);
    crpt_load_texture(SETTINGS_PATH"right_key.png", widget_ids[4]);
    crpt_load_texture(SETTINGS_PATH"sound_toggle.png", widget_ids[5]);
    crpt_load_texture(SETTINGS_PATH"music_toggle.png", widget_ids[6]);
    crpt_load_texture(SETTINGS_PATH"back_button.png", widget_ids[7]);
}

void load_settings_scene(scene_t *scene)
{
    texture_t *texture;
    sprite_t *sprite;
    settings_state_t *state = malloc(sizeof(*state));

    (void)scene;
    load_textures();
    for (unsigned int i = 0; i <
            sizeof(widget_ids) / sizeof(widget_ids[0]); i++) {
        texture = crpt_fetch_texture(widget_ids[i]);
        crpt_load_sprite(texture, widget_ids[i]);
        sprite = crpt_fetch_sprite(widget_ids[i]);
        sfSprite_setPosition(sprite, positions[i]);
    }
    state->waiting_for_key = -1;
    scene->data = state;
}
