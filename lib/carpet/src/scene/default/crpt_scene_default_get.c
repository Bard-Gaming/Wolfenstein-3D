/*
** EPITECH PROJECT, 2025
** Project - Carpet Lib
** File description:
** Implementation for
** crpt_scene_default_get
*/

#include <carpet/scene.h>


/*
** Retrieves a pointer to the library's
** default theme.
*/
scene_t *crpt_scene_default_get(void)
{
    static scene_t default_scene = {
        .load = crpt_scene_default_load,
        .unload = crpt_scene_default_unload,
        .update = crpt_scene_default_update,
    };

    return &default_scene;
}
