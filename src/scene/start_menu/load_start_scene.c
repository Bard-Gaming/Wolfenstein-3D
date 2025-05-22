/*
** EPITECH PROJECT, 2025
** Project - Wolf3D
** File description:
** Implementation for
** load_start_scene
*/

#include <wolf/scenes.h>
#include <wolf/player.h>

static void load_textures(void)
{
    crpt_load_texture("assets/textures/start_bg.png", "start_bg");
    crpt_load_texture("assets/textures/logo.png", "logo");
    crpt_load_texture("assets/textures/button_start.png", "btn_start");
    crpt_load_texture("assets/textures/button_settings.png", "btn_settings");
    crpt_load_texture("assets/textures/button_selected.png", "btn_selected");
}

void load_start_scene(scene_t *scene)
{
    load_textures();
    ;
}

