/*
** EPITECH PROJECT, 2025
** Project - Wolf3D
** File description:
** Implementation for
** update_start_scene
*/

#include <wolf/scenes.h>
#include <wolf/scenes.h>

void start_menu_events(scene_t *scene, event_t *event)
{
    int mouse_x = event->mouseButton.x;
    int mouse_y = event->mouseButton.y;
    int btn_x;
    int btn_y;
    int width;
    int height;

    crpt_sprite_get_position("btn_start", &btn_x, &btn_y);
    crpt_sprite_get("btn_start", &width, &height);
    if (mouse_x >= btn_x && mouse_x <= btn_x + width &&
        mouse_y >= btn_y && mouse_y <= btn_y + height)
        set_level_scene();
    crpt_sprite_get_position("btn_settings", &btn_x, &btn_y);
    crpt_sprite_get("btn_settings", &width, &height);
    if (mouse_x >= btn_x && mouse_x <= btn_x + width &&
        mouse_y >= btn_y && mouse_y <= btn_y + height)
        set_settings_scene();
    ;
}


void update_start_scene(scene_t *scene)
{
    ;
}
