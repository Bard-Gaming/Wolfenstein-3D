/*
** EPITECH PROJECT, 2025
** Project - Carpet Lib
** File description:
** Implementation for
** crpt_map_draw3
*/

#include <carpet/map.h>
#include <carpet/object.h>
#include <carpet/game.h>
#include <carpet/ray.h>
#include <carpet/utils/graphics.h>


/*
** Changes the given color to appear
** as though a shadow is cast on it.
*/
static color_t apply_shadow(color_t color)
{
    return (color_t){
        color.r, color.g, color.b,
        color.a * CRPT_SHADOW_INTENSITY,
    };
}

/*
** Casts a ray and draws the resulting vertical line on
** the screen.
** If the ray doesn't hit anything, this function does
** nothing.
*/
static void draw_raycast(const map_t *map, const camera_t *cam,
    unsigned int x, double angle)
{
    game_t *game = crpt_game_get();
    const unsigned int max_height = sfRenderWindow_getSize(game->window).y;
    ray_t ray = crpt_raycast(cam->position, angle, map);
    object_t *obj = crpt_map_get(map, ray.pos);
    double height;
    double start_y;

    if (isinff(ray.dist) || obj == NULL)
        return;
    ray.dist *= cos(angle - cam->rotation);
    height = crpt_umin(max_height, map->cube_size * max_height / ray.dist);
    start_y = (max_height - height) / 2;
    crpt_draw_line(
        game->window, (vec2_t){ x, start_y },
        (vec2_t){ x, start_y + height },
        ray.draw_shadow ? apply_shadow(obj->color) : obj->color
    );
}

/*
** Draws the 3D view of a map with a
** given camera's settings.
**
** Note: the projection distance is
** assumed to be 1.0.
** Note that no define exists for this
** as (for some unknown reason) changing
** the projection plane's distance does
** not affect the outcome.
*/
void crpt_map_draw3(const map_t *map, const camera_t *cam, window_t *window)
{
    const unsigned int ray_count = sfRenderWindow_getSize(window).x;
    const double half_width = tan(cam->fov / 2);
    double angle;
    double x;

    for (unsigned int i = 0; i < ray_count; i++) {
        x = (2.0 * (i / (ray_count - 1.0)) - 1.0) * half_width;
        angle = norm(atan2(x, 1.0) + cam->rotation);
        draw_raycast(map, cam, i, angle);
    }
}
