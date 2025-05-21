/*
** EPITECH PROJECT, 2025
** Project - Carpet Lib
** File description:
** Implementation for
** crpt_map_draw2
*/

#include <carpet/map.h>
#include <carpet/object.h>
#include <carpet/camera.h>
#include <carpet/utils/vector.h>
#include <carpet/utils/graphics.h>


/*
** Draws a block onto the screen at
** the given positions.
*/
static void draw_block(const map_t *map, vec2_t screen_pos, vec2_t pos)
{
    color_t color = crpt_map_is_solid(map, pos) ? sfWhite : sfBlack;

    crpt_draw_solid_square(screen_pos, map->tile_size, color);
}

/*
** Draws the player on the map.
*/
static void draw_player(const map_t *map, vec2_t screen_pos)
{
    double player_size = map->tile_size / 1.5;
    vec2_t offset = { 10.0 * map->tile_size, 10.0 * map->tile_size };

    crpt_draw_solid_square(
        crpt_vec2_add(screen_pos, offset),
        player_size, sfGreen
    );
}

/*
** Draws the thin outline around the map.
*/
static void draw_outline(vec2_t *screen_pos, const map_t *map)
{
    crpt_draw_solid_square(
        *screen_pos, 20.2 * map->tile_size,
        (color_t){ 255, 255, 255, 150 }
    );
    screen_pos->x += 0.1 * map->tile_size;
    screen_pos->y += 0.1 * map->tile_size;
}

/*
** Draws the map in a 2D square onto
** the screen. This can be used as a
** minimap on the HUD.
*/
void crpt_map_draw2(const map_t *map, vec2_t screen_pos)
{
    const double off = 10.0 * map->cube_size;
    vec2_t pos = *crpt_camera_get_position();
    vec2_t cur_screen;

    draw_outline(&screen_pos, map);
    cur_screen = screen_pos;
    for (double y = pos.y - off; y < pos.y + off; y += map->cube_size) {
        cur_screen.x = screen_pos.x;
        for (double x = pos.x - off; x < pos.x + off; x += map->cube_size) {
            draw_block(map, cur_screen, (vec2_t){ x, y });
            cur_screen.x += map->tile_size;
        }
        cur_screen.y += map->tile_size;
    }
    draw_player(map, screen_pos);
}
