/*
** EPITECH PROJECT, 2025
** Project - Carpet Lib
** File description:
** Implementation for
** crpt_ray_draw3
*/

#include <carpet/ray.h>
#include <carpet/map.h>
#include <carpet/game.h>
#include <carpet/scene.h>
#include <carpet/utils/graphics.h>


/*
** Processes the object's color
** and returns the processed result.
*/
static color_t process_color(ray_t ray, const map_cell_t *cell)
{
    color_t color = cell->color;

    if (ray.side == RS_HORIZONTAL) {
        color.r *= CRPT_SHADOW_INTENSITY;
        color.g *= CRPT_SHADOW_INTENSITY;
        color.b *= CRPT_SHADOW_INTENSITY;
    }
    return color;
}

/*
** Computes the tex coords and store them in
** the given 2D vector buffer (buf).
*/
static void compute_tex_coords(vec2_t *buf, ray_t ray,
    const map_t *map, double height)
{
    const double max_height = crpt_game_get()->camera.height;
    const map_cell_t *cell = crpt_map_get_cell(map, ray.pos);
    vec2_t cell_pos = crpt_map_cell_coords(map, ray.pos);
    sfVector2u texture_dim = sfTexture_getSize(cell->texture);
    double texture_ratio = texture_dim.y / height;
    double height_offset = fmax(height - max_height, 0.0) / 2.0;
    double offset = ray.side == RS_HORIZONTAL ?
        fabs(ray.pos.x - cell_pos.x) :
        fabs(ray.pos.y - cell_pos.y);
    double tex_x = texture_dim.x * (offset / map->cell_size);

    buf[0].x = tex_x;
    buf[0].y = height_offset * texture_ratio;
    buf[1].x = tex_x;
    buf[1].y = (height - height_offset) * texture_ratio;
}

/*
** Draws a line onto the window.
** This is mainly a wrapper function around crpt_draw_line,
** which is necessary when trying to compute the tex coords.
*/
static void draw_line(ray_t ray, const map_t *map,
    const map_cell_t *cell, graphics_line_t line)
{
    double height = line.tex_start.y;
    vec2_t tex_coords[2] = { 0 };

    if (cell->texture != NULL)
        compute_tex_coords(tex_coords, ray, map, height);
    line.tex_start = tex_coords[0];
    line.tex_end = tex_coords[1];
    crpt_draw_line(line);
}

static color_t color_gradient(color_t color)
{
    color.a *= CRPT_DISTANCE_FALLOFF;
    return color;
}

/*
** Draws the floor and ceiling.
*/
static void draw_floor_ceil(game_t *game, double x)
{
    const map_t *map = game->scene->map;
    const camera_t *cam = &game->camera;
    double horizon = cam->height * 0.5;
    graphics_line_t line = {
        .start = { x, horizon },
        .end = { x, cam->height },
        .start_color = color_gradient(map->floor),
        .end_color = map->floor,
    };

    crpt_draw_line(line);
    line.start.y = 0.0;
    line.end.y = horizon;
    line.start_color = map->ceiling;
    line.end_color = color_gradient(map->ceiling);
    crpt_draw_line(line);
}

/*
** Draws the vertical line the given ray has hit
** onto the game's window at the specified x-position.
*/
void crpt_ray_draw3(ray_t ray, double x,
    const map_t *map, const camera_t *cam)
{
    map_cell_t *cell = crpt_map_get_cell(map, ray.pos);
    game_t *game = crpt_game_get();
    double height_uncapped;
    double start_y;
    double height;
    color_t color;

    draw_floor_ceil(game, x);
    if (isinf(ray.dist) || cell == NULL)
        return;
    height_uncapped = map->cell_size * cam->height / ray.dist;
    height = fmin(cam->height, height_uncapped);
    start_y = (cam->height - height) * 0.5;
    color = process_color(ray, cell);
    draw_line(ray, map, cell, (graphics_line_t){
        .start = { x, start_y }, .end = { x, start_y + height },
        .texture = cell->texture,
        .start_color = color, .end_color = color,
        .tex_start = { start_y, height_uncapped },
    });
}
