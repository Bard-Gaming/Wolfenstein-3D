/*
** EPITECH PROJECT, 2025
** Project - Wolf3D
** File description:
** Implementation for
** set_start_scene
*/

#include <wolf/scenes.h>


/*
** Sets the game's scene to the start.
*/
void set_start_scene(void)
{
    static scene_t start = {
        .load = load_start_scene,
        .unload = unload_start_scene,
        .draw_ui = draw_start_scene_ui,
        .event_handlers[sfEvtMouseButtonReleased] = start_scene_onclick,
        .event_handlers[sfEvtMouseMoved] = start_scene_mouse_move,
    };

    crpt_scene_set(&start);
}
