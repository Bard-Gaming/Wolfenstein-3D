/*
** EPITECH PROJECT, 2025
** Project - Carpet Lib
** File description:
** Implementation for
** crpt_ray_draw3
*/

#include "carpet/types.h"
#include <carpet/ray.h>
#include <carpet/map.h>
#include <carpet/game.h>
#include <carpet/object.h>
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
** Tells whether or not the angle is facing
** a North / South wall or not.
*/
#include <stdio.h>
/*
** Computes the tex coords and store them in
** the given 2D vector buffer (buf).
*/
static void compute_tex_coords(vec2_t *buf, ray_t ray,
    const object_t *obj, double height)
{
    const double max_height = buf[0].x;
    sfVector2u texture_dim = sfTexture_getSize(obj->texture);
    double texture_ratio = texture_dim.y / height;
    double height_offset = fmax(height - max_height, 0.0) / 2.0;
    double offset = ray.side == RS_HORIZONTAL ?
        fabs(ray.pos.x - obj->position.x) :
        fabs(ray.pos.y - obj->position.y);
    double tex_x = texture_dim.x * (offset / obj->map->cube_size);

    buf[0].y = height_offset * texture_ratio;
    buf[1].y = (height - height_offset) * texture_ratio;
    buf[0].x = tex_x;
    buf[1].x = tex_x;
}

/*
** Draws a line onto the window.
** This is mainly a wrapper function around crpt_draw_line,
** which is necessary when trying to compute the tex coords.
*/
static void draw_line(window_t *win, ray_t ray,
    const object_t *obj, graphics_line_t line)
{
    const unsigned int max_height = sfRenderWindow_getSize(win).y;
    double height = line.end.y - line.start.y;
    vec2_t tex_coords[2] = { 0 };

    if (obj->texture != NULL) {
        tex_coords[0].x = max_height;
        compute_tex_coords(tex_coords, ray, obj, height);
    }
    line.tex_start = tex_coords[0];
    line.tex_end = tex_coords[1];
    line.end.y = line.start.y + fmin(max_height, height);
    crpt_draw_line(win, line);
}

/*
** Draws the vertical line the given ray has hit
** onto the game's window at the specified x-position.
*/
void crpt_ray_draw3(ray_t ray, unsigned int x,
    const map_t *map, const camera_t *cam)
{
    window_t *win = crpt_game_get()->window;
    const unsigned int max_height = sfRenderWindow_getSize(win).y;
    object_t *obj = crpt_map_get(map, ray.pos);
    double start_y;
    double height;

    if (isinff(ray.dist) || obj == NULL)
        return;
    ray.dist *= cos(ray.angle - cam->rotation);
    height = map->cube_size * max_height / ray.dist;
    start_y = (max_height - fmin(max_height, height)) / 2.0;
    draw_line(win, ray, obj, (graphics_line_t){
        .start = (vec2_t){ x, start_y },
        .end = (vec2_t){ x, start_y + height },
        .texture = obj->texture,
        .color = process_color(ray, obj),
    });
}
