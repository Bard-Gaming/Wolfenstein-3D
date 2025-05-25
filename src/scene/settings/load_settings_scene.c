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
    "back_button",

    // Key buffer displays
    "buffer_forward",
    "buffer_backward",
    "buffer_left",
    "buffer_right",

    // Sound toggle states (ON/OFF)
    "sound_on_red",
    "sound_on_green",
    "sound_off_red",
    "sound_off_green",

    // Music toggle states (ON/OFF)
    "music_on_red",
    "music_on_green",
    "music_off_red",
    "music_off_green"
};

static const sfVector2f positions[] = {
    { 0.f, 50.f },       // settings_bg
    { 700.f, 400.f },    // forward
    { 700.f, 460.f },    // backward
    { 700.f, 520.f },    // left
    { 700.f, 580.f },    // right
    { 700.f, 720.f },    // sound toggle label
    { 700.f, 800.f },    // music toggle label
    { 850.f, 950.f },    // back button

    { 1000.f, 400.f },   // buffer_forward
    { 1000.f, 460.f },   // buffer_backward
    { 1000.f, 520.f },   // buffer_left
    { 1000.f, 580.f },   // buffer_right

    // sound toggles (ON/OFF)
    { 1020.f, 720.f },   // sound_on_red
    { 1020.f, 720.f },   // sound_on_green
    { 1120.f, 720.f },   // sound_off_red
    { 1120.f, 720.f },   // sound_off_green

    // music toggles (ON/OFF)
    { 1020.f, 800.f },   // music_on_red
    { 1020.f, 800.f },   // music_on_green
    { 1120.f, 800.f },   // music_off_red
    { 1120.f, 800.f }    // music_off_green
};

static void load_textures(void)
{
    crpt_load_texture(SETTINGS_PATH"settings_bg.png", "settings_bg");
    crpt_load_texture(SETTINGS_PATH"forward_key.png", "forward_key");
    crpt_load_texture(SETTINGS_PATH"backward_key.png", "backward_key");
    crpt_load_texture(SETTINGS_PATH"left_key.png", "left_key");
    crpt_load_texture(SETTINGS_PATH"right_key.png", "right_key");
    crpt_load_texture(SETTINGS_PATH"sound_toggle.png", "sound_toggle");
    crpt_load_texture(SETTINGS_PATH"music_toggle.png", "music_toggle");
    crpt_load_texture(SETTINGS_PATH"back_button.png", "back_button");
    crpt_load_texture(SETTINGS_PATH"key_buffer.png", "buffer_forward");
    crpt_load_texture(SETTINGS_PATH"key_buffer.png", "buffer_backward");
    crpt_load_texture(SETTINGS_PATH"key_buffer.png", "buffer_left");
    crpt_load_texture(SETTINGS_PATH"key_buffer.png", "buffer_right");
    crpt_load_texture(SETTINGS_PATH"on_red.png", "sound_on_red");
    crpt_load_texture(SETTINGS_PATH"on_green.png", "sound_on_green");
    crpt_load_texture(SETTINGS_PATH"off_red.png", "sound_off_red");
    crpt_load_texture(SETTINGS_PATH"off_green.png", "sound_off_green");
    crpt_load_texture(SETTINGS_PATH"on_red.png", "music_on_red");
    crpt_load_texture(SETTINGS_PATH"on_green.png", "music_on_green");
    crpt_load_texture(SETTINGS_PATH"off_red.png", "music_off_red");
    crpt_load_texture(SETTINGS_PATH"off_green.png", "music_off_green");
}

void load_settings_scene(scene_t *scene)
{
    texture_t *texture;
    sprite_t *sprite;
    settings_state_t *state = malloc(sizeof(*state));

    (void)scene;
    load_textures();
    for (unsigned int i = 0;
            i < sizeof(widget_ids) / sizeof(widget_ids[0]); i++) {
        texture = crpt_fetch_texture(widget_ids[i]);
        crpt_load_sprite(texture, widget_ids[i]);
        sprite = crpt_fetch_sprite(widget_ids[i]);
        sfSprite_setPosition(sprite, positions[i]);
    }
    state->waiting_for_key = -1;
    scene->data = state;
}
