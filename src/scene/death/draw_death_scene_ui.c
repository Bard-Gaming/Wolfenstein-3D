/*
** EPITECH PROJECT, 2025
** Project - Wolf3D
** File description:
** Implementation for
** draw_death_scene_ui
*/

#include <wolf/scenes.h>


/*
** Draws the widget with the given
** ID onto the screen.
*/
static void draw_widget(const char *id)
{
    sprite_t *sprite = crpt_fetch_sprite(id);

    crpt_draw_sprite(sprite);
}

/*
** Draws the menu for the starting
** scene.
*/
void draw_death_scene_ui(UNUSED scene_t *scene, UNUSED window_t *window)
{
    draw_widget("menu_background");
    draw_widget("logo");
    draw_widget("start_button");
    draw_widget("settings_button");
}
