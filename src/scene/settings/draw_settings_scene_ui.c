/*
** EPITECH PROJECT, 2025
** Project - Wolf3D
** File description:
** Implementation for
** draw_settings_scene_ui
*/

#include <wolf/scenes.h>
#include <wolf/settings.h>
#include <string.h>

static const char *widget_ids[] = {
    "settings_bg",
    "forward_key",
    "backward_key",
    "left_key",
    "right_key",
    "sound_toggle",
    "music_toggle",
    "back_button",

    // Key buffer displays for ZQSD
    "buffer_forward",
    "buffer_backward",
    "buffer_left",
    "buffer_right",

    // Toggle states for SOUND (ON/OFF)
    "sound_on_red",
    "sound_on_green",
    "sound_off_red",
    "sound_off_green",

    // Toggle states for MUSIC (ON/OFF)
    "music_on_red",
    "music_on_green",
    "music_off_red",
    "music_off_green"
};

static void draw_widget(const char *id)
{
    sprite_t *sprite = crpt_fetch_sprite(id);

    crpt_draw_sprite(sprite);
}

static void crpt_draw_text(sfText *text)
{
    window_t *win = crpt_game_get()->window;

    sfRenderWindow_drawText(win, text, NULL);
}

static void draw_base_widgets(void)
{
    const char *id;

    for (unsigned int i = 0;
            i < sizeof(widget_ids) / sizeof(widget_ids[0]); i++) {
        id = widget_ids[i];
        if (strncmp(id, "sound_o", 7) == 0 ||
            strncmp(id, "music_o", 7) == 0)
            continue;
        draw_widget(id);
    }
}

static void draw_sound_toggle(int enabled)
{
    if (enabled) {
        draw_widget("sound_on_green");
        draw_widget("sound_off_red");
    } else {
        draw_widget("sound_on_red");
        draw_widget("sound_off_green");
    }
}

static void draw_music_toggle(int enabled)
{
    if (enabled) {
        draw_widget("music_on_green");
        draw_widget("music_off_red");
    } else {
        draw_widget("music_on_red");
        draw_widget("music_off_green");
    }
}

static void draw_key_label(const char *text, float x, float y)
{
    sfFont *font = crpt_fetch_font("arial");
    sfText *label = sfText_create();

    sfText_setString(label, text);
    sfText_setFont(label, font);
    sfText_setCharacterSize(label, 36);
    sfText_setFillColor(label, sfWhite);
    sfText_setPosition(label, (sfVector2f){ x, y });
    crpt_draw_text(label);
    sfText_destroy(label);
}

static void draw_key_labels(const settings_t *settings)
{
    float label_x = 1100.f;
    float label_y[] = { 415.f, 475.f, 535.f, 600.f };
    const char *key;

    for (int i = 0; i < 4; i++) {
        key = key_to_string(settings->controls[i]);
        if (!key)
            key = "?";
        draw_key_label(key, label_x, label_y[i]);
    }
}

void draw_settings_scene_ui(scene_t *scene, window_t *window)
{
    settings_t *settings = get_settings();

    (void)scene;
    (void)window;
    draw_base_widgets();
    draw_sound_toggle(settings->sound_enabled);
    draw_music_toggle(settings->music_enabled);
    draw_key_labels(settings);
}
