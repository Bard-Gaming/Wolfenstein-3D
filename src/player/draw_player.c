/*
** EPITECH PROJECT, 2025
** Project - Wolf3D
** File description:
** Implementation for
** draw_player
*/

#include <wolf/player.h>


/*
** Draws the player's healthbar,
** having it fill depending on the
** player's health.
*/
static void draw_healthbar(const player_t *player)
{
    const vec2u_t window_dim = crpt_camera_get_size();

    crpt_draw_healthbar((graphics_healthbar_t){
        .pos = { 10.0, window_dim.y - 90.0 },
        .dimensions = { 228.0, 80.0 },
        .progress = player->health / PLAYER_MAX_HEALTH,
        .full = crpt_fetch_texture("hb_full"),
        .empty = crpt_fetch_texture("hb_empty"),
        .color = sfWhite,
    });
}

/*
** Draws a semi-transparent red square over
** the screen to emulate blood.
*/
static void draw_red_screen(const player_t *player)
{
    vec2u_t size = crpt_camera_get_size();
    color_t color = { 150, 20, 20, player->hurt_time * 100 };

    crpt_draw_solid_square((vec2_t){ 0.0, 0.0 }, size.x, color);
}

/*
** Draws the player's arms and other
** related elements.
*/
void draw_player(void)
{
    player_t *player = get_player();

    draw_healthbar(player);
    crpt_draw_sprite(player->weapon_sprite);
    if (player->hurt_time > 0.0)
        draw_red_screen(player);
}
