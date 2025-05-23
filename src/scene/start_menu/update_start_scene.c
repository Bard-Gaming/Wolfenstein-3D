/*
** EPITECH PROJECT, 2025
** Project - Wolf3D
** File description:
** Implementation for
** update_start_scene
*/

#include <wolf/scenes.h>
#include <SFML/Graphics.h>
#include <wolf/scenes.h>
#include <carpet/assets.h>

void start_menu_events(scene_t *scene, event_t *event)
{
    int mouse_x = event->mouseButton.x;
    int mouse_y = event->mouseButton.y;
    sprite_t *btn_start = crpt_fetch_sprite("btn_start");
    sfFloatRect start_bounds = sfSprite_getGlobalBounds(btn_start);

    (void)scene;
    if (sfFloatRect_contains(&start_bounds, mouse_x, mouse_y))
        set_level_scene();
}

void update_start_scene(scene_t *scene, time_micro_t dt)
{
    (void)scene;
    (void)dt;
}
