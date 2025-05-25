/*
** EPITECH PROJECT, 2025
** Project - Wolf3D
** File description:
** Implementation for
** death_scene_onclick
*/

#include <wolf/scenes.h>


/*
** Mouse click event handler for the
** game's death menu.
*/
void death_scene_onclick(UNUSED scene_t *scene, event_t *event)
{
    int mouse_x = event->mouseButton.x;
    int mouse_y = event->mouseButton.y;
    sprite_t *start_btn = crpt_fetch_sprite("start_button");
    sfFloatRect button_bounds = sfSprite_getGlobalBounds(start_btn);

    if (sfFloatRect_contains(&button_bounds, mouse_x, mouse_y))
        set_level_scene();
}
