/*
** EPITECH PROJECT, 2025
** Project - Wolf3D
** File description:
** Implementation for
** update_level_scene
*/

#include <wolf/scenes.h>
#include <wolf/player.h>


/*
** Updates the level's scene.
** Nothing much to add there, is there?..
*/
void update_level_scene(scene_t *scene, time_micro_t dt)
{
    update_player(scene->map, dt);
}
