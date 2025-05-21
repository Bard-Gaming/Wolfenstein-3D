/*
** EPITECH PROJECT, 2025
** Project - Carpet Lib
** File description:
** Implementation for
** crpt_scene_draw
*/

#include <carpet/scene.h>
#include <carpet/map.h>


/*
** Draws a scene onto the given
** window.
*/
void crpt_scene_draw(scene_t *scene, camera_t *cam, window_t *window)
{
    if (scene->map != NULL)
        crpt_map_draw3(scene->map, cam);
    DRAW_SCENE_UI(scene, window);
}
