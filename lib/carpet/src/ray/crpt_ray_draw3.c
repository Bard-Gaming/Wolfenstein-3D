/*
** EPITECH PROJECT, 2025
** Project - Carpet Lib
** File description:
** Implementation for
** crpt_ray_draw3
*/

#include <SFML/Graphics/Texture.h>
#include <carpet/ray.h>
#include <carpet/map.h>
#include <carpet/game.h>
#include <carpet/object.h>
#include <carpet/scene.h>
#include <carpet/utils/graphics.h>


/*
** Processes the object's color
** and returns the processed result.
*/
static color_t process_color(ray_t ray, const object_t *obj)
{
    color_t color = obj->color;

    if (ray.side == RS_HORIZONTAL)
        color.a *= CRPT_SHADOW_INTENSITY;
    return color;
}

/*
** Computes the tex coords and store them in
** the given 2D vector buffer (buf).
*/
static void compute_tex_coords(vec2_t *buf, ray_t ray,
    const object_t *obj, double height)
{
    const double max_height = crpt_game_get()->camera.height;
    sfVector2u texture_dim = sfTexture_getSize(obj->texture);
    double texture_ratio = texture_dim.y / height;
    double height_offset = fmax(height - max_height, 0.0) / 2.0;
    double offset = ray.side == RS_HORIZONTAL ?
        fabs(ray.pos.x - obj->position.x) :
        fabs(ray.pos.y - obj->position.y);
    double tex_x = texture_dim.x * (offset / obj->map->cube_size);

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
static void draw_line(window_t *win, ray_t ray,
    const object_t *obj, graphics_line_t line)
{
    double height = line.tex_start.y;
    vec2_t tex_coords[2] = { 0 };

    if (obj->texture != NULL)
        compute_tex_coords(tex_coords, ray, obj, height);
    line.tex_start = tex_coords[0];
    line.tex_end = tex_coords[1];
    crpt_draw_line(win, line);
}

/*
** Draws the floor and ceiling.
*/
static void draw_floor_ceil(game_t *game, ray_t ray, double x, double y)
{
    const map_t *map = game->scene->map;
    const camera_t *cam = &game->camera;
    graphics_line_t line = {
        .start = { x, y },
        .end = { x, cam->height },
        .color = map->floor,
    };

    crpt_draw_line(game->window, line);
    line.start.y = 0.0;
    line.end.y = cam->height - y;
    line.color = map->ceiling;
    crpt_draw_line(game->window, line);
}

/*
** Draws the vertical line the given ray has hit
** onto the game's window at the specified x-position.
*/
void crpt_ray_draw3(ray_t ray, double x,
    const map_t *map, const camera_t *cam)
{
    game_t *game = crpt_game_get();
    double height_uncapped;
    double start_y;
    double height;
    object_t *obj;

    if (isinff(ray.dist))
        return;
    obj = crpt_map_get(map, ray.pos);
    if (obj == NULL)
        return;
    height_uncapped = map->cube_size * cam->height / ray.dist;
    height = fmin(cam->height, height_uncapped);
    start_y = (cam->height - height) * 0.5;
    draw_line(game->window, ray, obj, (graphics_line_t){
        .start = { x, start_y }, .end = { x, start_y + height },
        .texture = obj->texture, .color = process_color(ray, obj),
        .tex_start = { start_y, height_uncapped },
    });
    draw_floor_ceil(game, ray, x, start_y + height);
}
