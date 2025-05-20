/*
** EPITECH PROJECT, 2025
** Project - Carpet Lib
** File description:
** Implementation for
** crpt_scene_update
*/

#include <carpet/scene.h>


/*
** Runs an update cycle for the
** given scene.
*/
void crpt_scene_update(scene_t *scene, time_micro_t delta)
{
    UPDATE_SCENE(scene, delta);
    while (delta >= CRPT_FIXED_RATE) {
        UPDATE_SCENE_FIXED(scene);
        delta -= CRPT_FIXED_RATE;
    }
}
