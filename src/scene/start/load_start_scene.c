/*
** EPITECH PROJECT, 2025
** Project - Wolf3D
** File description:
** Implementation for
** load_start_scene
*/

#include <wolf/scenes.h>
#include <wolf/player.h>


static const char *widget_ids[] = {
    "menu_background",
    "logo",
    "start_button",
    "settings_button",
};


static const sfVector2f positions[] = {
    { 0.f, 50.f },
    { 700.f, 280.f },
    { 880.f, 800.f },
    { 860.f, 900.f },
};


static void load_textures(void)
{
    crpt_load_texture("assets/textures/widgets/menu_background.png",
        widget_ids[0]);
    crpt_load_texture("assets/textures/widgets/logo.png",
        widget_ids[1]);
    crpt_load_texture("assets/textures/widgets/start_button.png",
        widget_ids[2]);
    crpt_load_texture("assets/textures/widgets/settings_button.png",
        widget_ids[3]);
}

void load_start_scene(scene_t *scene)
{
    texture_t *texture;
    sprite_t *sprite;

    (void)scene;
    load_textures();
    for (unsigned int i = 0; i < 4; i++) {
        texture = crpt_fetch_texture(widget_ids[i]);
        crpt_load_sprite(texture, widget_ids[i]);
        sprite = crpt_fetch_sprite(widget_ids[i]);
        sfSprite_setPosition(sprite, positions[i]);
    }
}
