/*
** EPITECH PROJECT, 2025
** Project - Wolf3D
** File description:
** Implementation for
** draw_level_scene_ui
*/

#include <wolf/scenes.h>
#include <wolf/player.h>


/*
** Draws the UI for the level.
*/
void draw_level_scene_ui(scene_t *scene, window_t *window)
{
    const sfVector2u window_dim = sfRenderWindow_getSize(window);
    player_t *player = get_player();

    crpt_map_draw2(scene->map, (vec2_t){ 0, 0 });
    crpt_draw_healthbar((graphics_healthbar_t){
        .pos = { 10.0, window_dim.y - 90.0 },
        .dimensions = { 228.0, 80.0 },
        .progress = player->health / PLAYER_MAX_HEALTH,
        .full = crpt_fetch_texture("hb_full"),
        .empty = crpt_fetch_texture("hb_empty"),
        .color = sfWhite,
    });
}
