/*
** EPITECH PROJECT, 2025
** Project - Wolf3D
** File description:
** Implementation for
** load_start_scene
*/

#include <wolf/scenes.h>
#include <wolf/player.h>
#include <wolf/player.h>
#include <carpet/assets.h>
#include <SFML/Graphics.h>

static void load_textures(void)
{
    crpt_load_texture("assets/textures/wolf_start_bg.png", "start_bg");
    crpt_load_texture("assets/textures/logo.png", "logo");
    crpt_load_texture("assets/textures/button_start.png", "btn_start");
    crpt_load_texture("assets/textures/button_settings.png", "btn_settings");
}

void load_start_scene(scene_t *scene)
{
    sfTexture *texture;
    sfSprite *sprite;
    const char *sprites[] =
        { "start_bg", "logo", "btn_start", "btn_settings" };
    sfVector2f positions[] = {
        {0, 50},
        {700, 280},
        {880, 800},
        {860, 900}
    };

    (void)scene;
    load_textures();
    for (long unsigned int i = 0; i <
            sizeof(sprites) / sizeof(sprites[0]); ++i) {
        texture = crpt_fetch_texture(sprites[i]);
        crpt_load_sprite(texture, sprites[i]);
        sprite = crpt_fetch_sprite(sprites[i]);
        sfSprite_setPosition(sprite, positions[i]);
    }
}
