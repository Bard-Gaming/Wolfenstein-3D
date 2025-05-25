/*
** EPITECH PROJECT, 2025
** Project - Carpet Lib
** File description:
** Implementation for
** crpt_object_set_texture
*/

#include <carpet/object.h>


/*
** Sets the texture of the object
** and updates the color and texture rect
** to fit the new texture.
*/
void crpt_object_set_texture(object_t *obj, const texture_t *texture)
{
    sfVector2u bounds = sfTexture_getSize(texture);

    obj->texture = texture;
    obj->texture_rect = (vec2_t){ 0.0, bounds.x };
    obj->color = sfWhite;
}
