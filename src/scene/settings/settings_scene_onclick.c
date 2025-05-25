/*
** EPITECH PROJECT, 2025
** Project - Wolf3D
** File description:
** Implementation for
** settings_scene_onclick
*/

#include <wolf/scenes.h>


/*
** Mouse click event handler for the
** game's settings menu.
*/
#include <wolf/scenes.h>
#include <wolf/settings.h>
#include <stdio.h>


void settings_scene_key_pressed(scene_t *scene, event_t *event)
{
    settings_state_t *state = scene->data;
    int key = event->key.code;
    int index = state->waiting_for_key;
    settings_t *settings;

    if (state->waiting_for_key < 0)
        return;
    settings = get_settings();
    settings->controls[index] = key;
    printf("[DEBUG] Rebound control[%d] to keycode %d\n", index, key);
    state->waiting_for_key = -1;
}

static int is_sprite_clicked(const char *id, int x, int y)
{
    sfFloatRect bounds = sfSprite_getGlobalBounds(crpt_fetch_sprite(id));

    return sfFloatRect_contains(&bounds, x, y);
}

static int handle_back_button(int x, int y)
{
    if (is_sprite_clicked("back_button", x, y)) {
        set_start_scene();
        return 1;
    }
    return 0;
}

static int handle_control_click(settings_state_t *state, int x, int y)
{
    const char *ids[] = {
        "forward_key", "backward_key", "left_key", "right_key"
    };

    for (int i = 0; i < 4; ++i) {
        if (is_sprite_clicked(ids[i], x, y)) {
            state->waiting_for_key = i;
            printf("[DEBUG] Clicked %s — waiting for key input...\n", ids[i]);
            return 1;
        }
    }
    return 0;
}

static int toggle_sound(settings_t *settings, int x, int y)
{
    if (is_sprite_clicked("sound_toggle", x, y)) {
        settings->sound_enabled = !settings->sound_enabled;
        printf("[DEBUG] Sound toggled: %s\n", settings->sound_enabled ? "ON" : "OFF");
        return 1;
    }
    return 0;
}

static int toggle_music(settings_t *settings, int x, int y)
{
    if (is_sprite_clicked("music_toggle", x, y)) {
        settings->music_enabled = !settings->music_enabled;
        printf("[DEBUG] Music toggled: %s\n", settings->music_enabled ? "ON" : "OFF");
        return 1;
    }
    return 0;
}


void settings_scene_onclick(scene_t *scene, event_t *event)
{
    int x = event->mouseButton.x;
    int y = event->mouseButton.y;
    settings_state_t *state = scene->data;
    settings_t *settings = get_settings();

    if (handle_back_button(x, y))
        return;
    if (handle_control_click(state, x, y))
        return;
    if (toggle_sound(settings, x, y))
        return;
    if (toggle_music(settings, x, y))
        return;
}

