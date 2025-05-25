/*
** EPITECH PROJECT, 2025
** Project - Wolf3D
** File description:
** Implementation for
** settings_scene_mouse_move
*/

#include <wolf/scenes.h>


static const char *widget_ids[] = {
    "forward_key",
    "backward_key",
    "left_key",
    "right_key",
    "sound_toggle",
    "music_toggle",
    "back_button"
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
