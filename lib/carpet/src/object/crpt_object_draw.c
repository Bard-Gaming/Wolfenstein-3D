/*
** EPITECH PROJECT, 2025
** Project - Carpet Lib
** File description:
** Implementation for
** crpt_object_draw
*/

#include <carpet/object.h>
#include <carpet/camera.h>
#include <carpet/scene.h>
#include <carpet/game.h>
#include <carpet/map.h>
#include <carpet/utils/graphics.h>
#include <carpet/utils/math.h>


/*
** Computes the floor offset.
** This is simply the map's cell size
** divided by two.
*/
static double get_floor_offset(void)
{
    game_t *game = crpt_game_get();

    return (game->scene->map == NULL ?
        CRPT_DEFAULT_CUBE_SIZE : game->scene->map->cell_size
    ) / 2.0;
}

/*
** Refer to the following link for information on
** the formulas:
** https://github.com/ssloy/tinyraycaster/wiki/Part-3:-populating-the-world
**
** The vector represents the 2D screen space coordinates, as well as
** the scale of the sprite (z).
*/
static graphics_map_texture_t compute_texture_data(const object_t *obj,
    const camera_t *cam)
{
    double bound_x = obj->texture_rect.y - obj->texture_rect.x;
    double bound_y = sfTexture_getSize(obj->texture).y;
    double dist_scale = cam->height / obj->cam_dist;
    double scale = obj->scale * dist_scale;
    double sprite_angle = atan2(
        cam->position.y - obj->position.y,
        obj->position.x - cam->position.x);
    double angle_det = math_norm(sprite_angle - cam->rotation) / cam->fov;
    double center_x = (cam->width - scale * bound_x) * 0.5;
    double start_y = get_floor_offset() - obj->scale * bound_y;

    return (graphics_map_texture_t){
        .x = angle_det * cam->width + center_x,
        .y = cam->height * 0.5 + (start_y - obj->height) * dist_scale,
        .width = obj->texture_rect.y * scale,
        .width_offset = obj->texture_rect.x * scale,
        .height = bound_y * scale,
        .dist = obj->cam_dist,
        .scale = scale,
    };
}

/*
** Draws an object onto the window.
** If there are walls that appear over the object,
** the object might not be fully drawn.
*/
void crpt_object_draw(const object_t *object, const camera_t *cam)
{
    graphics_map_texture_t texture_data;

    if (object->texture == NULL)
        return;
    texture_data = compute_texture_data(object, cam);
    texture_data.texture = object->texture;
    texture_data.color = object->color;
    crpt_draw_map_texture(texture_data);
}
