/*
** EPITECH PROJECT, 2025
** Project - Wolf3D
** File description:
** Implementation for
** unload_start_scene
*/

#include <wolf/scenes.h>


/*
** Unloads the widget with the given
** ID. This means the texture that is
** associated with the given widget, as
** well as its corresponding sprite, will
** get unloaded.
*/
static void unload_widget(const char *id)
{
    crpt_unload_sprite(id);
    crpt_unload_texture(id);
}

/*
** Unloads all sprites related to the start menu.
*/
void unload_start_scene(UNUSED scene_t *scene)
{
    unload_widget("menu_background");
    unload_widget("logo");
    unload_widget("start_button");
    unload_widget("settings_button");
}
