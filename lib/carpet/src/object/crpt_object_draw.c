/*
** EPITECH PROJECT, 2025
** Project - Carpet Lib
** File description:
** Implementation for
** crpt_object_draw
*/

#include <carpet/object.h>
#include <carpet/camera.h>
#include <carpet/utils/graphics.h>
#include <carpet/utils/math.h>


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
    sfVector2u bounds = sfTexture_getSize(obj->texture);
    double dist_scale = cam->height / obj->cam_dist;
    double scale = obj->scale * dist_scale;
    double sprite_angle = norm(atan2(
        cam->position.y - obj->position.y,
        obj->position.x - cam->position.x
    ));
    double angle_diff = sprite_angle - cam->rotation;
    double center_x = (cam->width - scale * bounds.x) * 0.5;
    double start_y = (obj->scale - 2) * bounds.y;

    return (graphics_map_texture_t){
        .x = angle_diff * cam->width / cam->fov + center_x,
        .y = cam->height * 0.5 - (start_y + obj->height) * dist_scale,
        .width = bounds.x * scale,
        .height = bounds.y * scale,
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
    crpt_draw_map_texture(texture_data);
}
