/*
** EPITECH PROJECT, 2025
** Project - Wolf3D
** File description:
** Implementation for
** level_scene_release_key
*/

#include <wolf/scenes.h>
#include <wolf/player.h>


/*
** Event handler function that is called
** when a key is pressed.
*/
void level_scene_release_key(scene_t *scene, event_t *event)
{
    if (event->key.code == sfKeyEscape)
        return set_start_scene();
    player_press_key(event);
}
