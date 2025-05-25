/*
** EPITECH PROJECT, 2025
** Project - Wolf3D
** File description:
** Implementation for
** set_settings_scene
*/

#include <wolf/scenes.h>


/*
** Sets the game's scene to settings.
*/
void set_settings_scene(void)
{
    static scene_t settings = {
        .load = load_settings_scene,
        .unload = unload_settings_scene,
        .draw_ui = draw_settings_scene_ui,
        .event_handlers[sfEvtMouseButtonReleased] = settings_scene_onclick,
        .event_handlers[sfEvtMouseMoved] = settings_scene_mouse_move,
        .event_handlers[sfEvtKeyPressed] = settings_scene_key_pressed,
    };

    crpt_scene_set(&settings);
}
