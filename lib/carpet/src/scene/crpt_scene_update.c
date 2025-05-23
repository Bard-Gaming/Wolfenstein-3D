/*
** EPITECH PROJECT, 2025
** Project - Carpet Lib
** File description:
** Implementation for
** crpt_scene_update
*/

#include <carpet/scene.h>
#include <carpet/object.h>
#include <carpet/game.h>
#include <carpet/map.h>


/*
** Compares the distances between two
** objects.
** cmp_dist(a, b) will is positive if
** a is further away than b, negative
** if b is further than a, and 0 otherwise.
*/
static int cmp_dist(object_t *a, object_t *b)
{
    return b->cam_dist - a->cam_dist;
}

/*
** Runs a single update cycle on the
** objects inside of the scene's map.
*/
static void update_objects(map_t *map)
{
    camera_t *cam = &crpt_game_get()->camera;
    object_t *object;

    for (size_t i = 0; i < map->objects.count; i++) {
        object = map->objects.data[i];
        object->cam_dist = crpt_vec2_distance(object->position, cam->position);
        if (object->update != NULL)
            object->update(object);
    }
    crpt_array_sort(&map->objects, (cmp_fnc_t)cmp_dist);
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
