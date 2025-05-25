/*
** EPITECH PROJECT, 2025
** Project - Wolf3D
** File description:
** Implementation for
** settings_scene_onclick
*/

#include <wolf/scenes.h>


#include <wolf/scenes.h>
#include <wolf/settings.h>
#include <stdio.h>
#include <SFML/Window/Keyboard.h>
#include <SFML/Graphics.h>

/*
** Handles key input after clicking a control button.
*/
void settings_scene_key_pressed(scene_t *scene, event_t *event)
{
    settings_state_t *state = scene->data;
    int key = event->key.code;
    int index = state->waiting_for_key;
    settings_t *settings;

    if (index < 0)
        return;
    settings = get_settings();
    settings->controls[index] = key;
    printf("[DEBUG] Rebound control[%d] to keycode %d\n", index, key);
    state->waiting_for_key = -1;
}

/*
** Helper: Check if a sprite with the given ID is clicked.
*/
static int is_sprite_clicked(const char *id, int x, int y)
{
    sfFloatRect bounds = sfSprite_getGlobalBounds(crpt_fetch_sprite(id));

    return sfFloatRect_contains(&bounds, x, y);
}

/*
** Handle clicking the back button.
*/
static int handle_back_button(int x, int y)
{
    if (is_sprite_clicked("back_button", x, y)) {
        set_start_scene();
        return 1;
    }
    return 0;
}

/*
** Wait for key press after clicking a control.
*/
static int rebind_control(settings_state_t *state, int index, const char *id)
{
    sfEvent event;
    settings_t *settings;

    state->waiting_for_key = index;
    printf("[DEBUG] Clicked %s — waiting for key input...\n", id);
    while (sfRenderWindow_waitEvent(crpt_game_get()->window, &event)) {
        if (event.type == sfEvtKeyPressed) {
            settings = get_settings();
            settings->controls[index] = event.key.code;
            printf("[DEBUG] Rebound control[%d] to keycode %d\n",
                index, event.key.code);
            state->waiting_for_key = -1;
            break;
        }
    }
    return 1;
}

/*
** Handle clicking any control button (ZQSD).
*/
static int handle_control_click(settings_state_t *state, int x, int y)
{
    const char *ids[] = {
        "forward_key", "backward_key", "left_key", "right_key"
    };

    for (int i = 0; i < 4; ++i) {
        if (is_sprite_clicked(ids[i], x, y))
            return rebind_control(state, i, ids[i]);
    }
    return 0;
}

static int toggle_sound(settings_t *settings, int x, int y)
{
    if (!settings->sound_enabled) {
        if (is_sprite_clicked("sound_on_red", x, y) ||
            is_sprite_clicked("sound_on_green", x, y)) {
            settings->sound_enabled = 1;
            printf("[DEBUG] Sound toggled: ON\n");
            return 1;
        }
    } else {
        if (is_sprite_clicked("sound_off_red", x, y) ||
            is_sprite_clicked("sound_off_green", x, y)) {
            settings->sound_enabled = 0;
            printf("[DEBUG] Sound toggled: OFF\n");
            return 1;
        }
    }
    return 0;
}

static int toggle_music(settings_t *settings, int x, int y)
{
    if (!settings->music_enabled) {
        if (is_sprite_clicked("music_on_red", x, y) ||
            is_sprite_clicked("music_on_green", x, y)) {
            settings->music_enabled = 1;
            printf("[DEBUG] Music toggled: ON\n");
            return 1;
        }
    } else {
        if (is_sprite_clicked("music_off_red", x, y) ||
            is_sprite_clicked("music_off_green", x, y)) {
            settings->music_enabled = 0;
            printf("[DEBUG] Music toggled: OFF\n");
            return 1;
        }
    }
    return 0;
}

/*
** Main mouse click handler for the settings scene.
*/
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
