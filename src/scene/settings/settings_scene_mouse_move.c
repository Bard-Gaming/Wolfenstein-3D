/*
** EPITECH PROJECT, 2025
** Project - Wolf3D
** File description:
** Implementation for
** settings_scene_mouse_move
*/

#include <wolf/scenes.h>


static const char *widget_ids[] = {
    "buffer_forward",
    "buffer_backward",
    "buffer_left",
    "buffer_right",
    "back_button",

    // Toggle buttons (2 for sound, 2 for music)
    "sound_on_red",
    "sound_on_green",
    "sound_off_red",
    "sound_off_green",
    "music_on_red",
    "music_on_green",
    "music_off_red",
    "music_off_green"
};

/*
** Updates the color of the sprite
** depending on the sprite's state
** (i.e. hovered, active, etc...).
*/
static void update_sprite_color(sprite_t *sprite, int x, int y)
{
    sfFloatRect bounds = sfSprite_getGlobalBounds(sprite);

    if (sfFloatRect_contains(&bounds, x, y))
        sfSprite_setColor(sprite, (color_t){ 255, 255, 255, 180 });
    else
        sfSprite_setColor(sprite, (color_t){ 255, 255, 255, 255 });
}

/*
** Mouse move event handler for the
** game's settings menu.
*/
void settings_scene_mouse_move(scene_t *scene, event_t *event)
{
    int x = event->mouseMove.x;
    int y = event->mouseMove.y;

    for (unsigned int i = 0; i <
            sizeof(widget_ids) / sizeof(widget_ids[0]); i++) {
        update_sprite_color(crpt_fetch_sprite(widget_ids[i]), x, y);
    }
}
