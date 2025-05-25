/*
** EPITECH PROJECT, 2025
** Project - Wolf3D
** File description:
** Implementation for
** update_level_scene_fixed
*/

#include <wolf/scenes.h>
#include <wolf/player.h>


/*
** Runs the scene's fixed update function.
** This is mainly for animation-related things,
** as they need time-independence.
*/
void update_level_scene_fixed(UNUSED scene_t *scene, UNUSED time_micro_t dt)
{
    update_player_fixed();
}
