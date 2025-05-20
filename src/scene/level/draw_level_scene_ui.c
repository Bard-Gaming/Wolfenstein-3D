/*
** EPITECH PROJECT, 2025
** Project - Wolf3D
** File description:
** Implementation for
** draw_level_scene_ui
*/

#include <wolf/scenes.h>


/*
** Draws the UI for the level.
*/
void draw_level_scene_ui(scene_t *scene, window_t *window)
{
    crpt_map_draw2(scene->map, (vec2_t){ 0, 0 }, window);
}
