/*
** EPITECH PROJECT, 2025
** Project - Carpet Lib
** File description:
** Implementation for
** crpt_draw_map_texture
*/

#include <carpet/utils/graphics.h>
#include <carpet/game.h>


/*
** sfRenderStates_default() doesn't exist in
** CSFML 2.5.X, so create a function that does
** the same.
*/
static sfRenderStates get_texture_state(const texture_t *texture)
{
    return (sfRenderStates){
        .blendMode = sfBlendAlpha,
        .transform = sfTransform_Identity,
        .texture = texture,
    };
}

/*
** Adds a line of the texture to the vertex
** array.
*/
static void add_line(vertex_array_t *va,
    graphics_map_texture_t texture, unsigned int x, const camera_t *cam)
{
    double screen_x = texture.x + x;
    float texture_x;
    float texture_y;

    if (0.0 > screen_x || screen_x > cam->width)
        return;
    if (cam->depth_buffer[(unsigned int)screen_x] < texture.dist)
        return;
    texture_x = x / texture.scale;
    texture_y = sfTexture_getSize(texture.texture).y;
    sfVertexArray_append(va, (sfVertex){
        { texture.x + x, texture.y }, sfWhite, { texture_x, 0.f }
    });
    sfVertexArray_append(va, (sfVertex){
        { texture.x + x, texture.y + texture.height },
        sfWhite, { texture_x, texture_y }
    });
}

/*
** Draws a given texture onto the screen.
** This function takes the camera's depth buffer
** into account, meaning the texture won't be drawn
** over walls.
*/
void crpt_draw_map_texture(graphics_map_texture_t texture)
{
    game_t *game = crpt_game_get();
    vertex_array_t *va = sfVertexArray_create();
    sfRenderStates state = get_texture_state(texture.texture);
    window_t *win = game->window;
    camera_t *cam = &game->camera;

    sfVertexArray_setPrimitiveType(va, sfLines);
    for (unsigned int x = 0; x < texture.width; x++)
        add_line(va, texture, x, cam);
    sfRenderWindow_drawVertexArray(win, va, &state);
    sfVertexArray_destroy(va);
}
