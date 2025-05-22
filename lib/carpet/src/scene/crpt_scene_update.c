/*
** EPITECH PROJECT, 2025
** Project - Carpet Lib
** File description:
** Implementation for
** crpt_scene_update
*/

#include <carpet/scene.h>
#include <carpet/object.h>
#include <carpet/map.h>


/*
** Runs a single update cycle on the
** objects inside of the scene's map.
*/
static void update_objects(map_t *map)
{
    object_t *object;

    for (size_t i = 0; i < map->objects.count; i++) {
        object = map->objects.data[i];
        if (object->update != NULL)
            object->update(object);
    }
}

/*
** Runs an update cycle for the
** given scene.
*/
void crpt_scene_update(scene_t *scene, time_micro_t delta)
{
    UPDATE_SCENE(scene, delta);
    while (delta >= CRPT_FIXED_RATE) {
        UPDATE_SCENE_FIXED(scene);
        if (scene->map != NULL)
            update_objects(scene->map);
        delta -= CRPT_FIXED_RATE;
    }
}
