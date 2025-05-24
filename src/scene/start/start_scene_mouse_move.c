/*
** EPITECH PROJECT, 2025
** Project - Wolf3D
** File description:
** Implementation for
** start_scene_mouse_move
*/

#include <wolf/scenes.h>


static void update_hover(sprite_t *sprite, int x, int y)
{
    sfFloatRect bounds = sfSprite_getGlobalBounds(sprite);

    if (sfFloatRect_contains(&bounds, x, y))
        sfSprite_setColor(sprite, (color_t){ 255, 255, 255, 180 });
    else
        sfSprite_setColor(sprite, (color_t){ 255, 255, 255, 255 });
}

/*
** Mouse move event handler for the
** game's start menu.
*/
void start_scene_mouse_move(UNUSED scene_t *scene, event_t *event)
{
    int mouse_x = event->mouseMove.x;
    int mouse_y = event->mouseMove.y;
    sprite_t *start_btn = crpt_fetch_sprite("start_button");
    sprite_t *settings_btn = crpt_fetch_sprite("settings_button");

    update_hover(start_btn, mouse_x, mouse_y);
    update_hover(settings_btn, mouse_x, mouse_y);
}
