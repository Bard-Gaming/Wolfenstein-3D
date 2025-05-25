/*
** EPITECH PROJECT, 2025
** Project - Wolf3D
** File description:
** Implementation for
** start_scene_onclick
*/

#include <wolf/scenes.h>


/*
** Mouse click event handler for the
** game's start menu.
*/
void start_scene_onclick(UNUSED scene_t *scene, event_t *event)
{
    int mouse_x = event->mouseButton.x;
    int mouse_y = event->mouseButton.y;
    sprite_t *start_btn = crpt_fetch_sprite("start_button");
    sfFloatRect start_btn_bounds = sfSprite_getGlobalBounds(start_btn);
    sprite_t *settings_button = crpt_fetch_sprite("settings_button");
    sfFloatRect sett_btn_bounds = sfSprite_getGlobalBounds(settings_button);

    if (sfFloatRect_contains(&start_btn_bounds, mouse_x, mouse_y))
        set_level_scene();
    if (sfFloatRect_contains(&sett_btn_bounds, mouse_x, mouse_y))
        set_settings_scene();
}
