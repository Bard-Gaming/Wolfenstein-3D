/*
** EPITECH PROJECT, 2025
** Project - Carpet Lib
** File description:
** Implementation for
** crpt_draw_healthbar
*/

#include <SFML/Graphics/RenderStates.h>
#include <SFML/Graphics/VertexArray.h>
#include <carpet/utils/graphics.h>
#include <carpet/game.h>


/*
** sfRenderStates_default() doesn't exist in
** CSFML 2.5.X, so create a function that does
** the same.
*/
static sfRenderStates texture_state(const texture_t *texture)
{
    return (sfRenderStates){
        sfBlendAlpha, sfTransform_Identity,
        texture, NULL
    };
}

sfVector2f get_tex_max(const texture_t *texture)
{
    sfVector2u dims = sfTexture_getSize(texture);

    return (sfVector2f){ dims.x, dims.y };
}

/*
** Draws the full section of the
** health bar.
*/
static void draw_full_bar(const graphics_healthbar_t *bar, window_t *win)
{
    sfRenderStates state = texture_state(bar->full);
    sfVector2f texmax = get_tex_max(bar->full);
    float tex_end = texmax.x * bar->progress;
    float end_x = bar->pos.x + bar->progress * bar->dimensions.x;
    float end_y = bar->pos.y + bar->dimensions.y;
    sfVertex vertices[4] = {
        { { bar->pos.x, bar->pos.y }, bar->color, { 0.f, 0.f } },
        { { end_x, bar->pos.y }, bar->color, { tex_end, 0.f } },
        { { end_x, end_y }, bar->color, { tex_end, texmax.y } },
        { { bar->pos.x, end_y }, bar->color, { 0.f, texmax.y } },
    };
    sfVertexArray *va = sfVertexArray_create();

    sfVertexArray_setPrimitiveType(va, sfQuads);
    for (int i = 0; i < 4; i++)
        sfVertexArray_append(va, vertices[i]);
    sfRenderWindow_drawVertexArray(win, va, &state);
    sfVertexArray_destroy(va);
}

/*
** Draws the empty section of the
** health bar.
*/
static void draw_empty_bar(const graphics_healthbar_t *bar, window_t *win)
{
    sfRenderStates state = texture_state(bar->empty);
    sfVector2f texmax = get_tex_max(bar->empty);
    float tex_start = texmax.x * bar->progress;
    float start_x = bar->pos.x + bar->progress * bar->dimensions.x;
    float end_x = bar->pos.x + bar->dimensions.x;
    float end_y = bar->pos.y + bar->dimensions.y;
    sfVertex vertices[4] = {
        { { start_x, bar->pos.y }, bar->color, { tex_start, 0.f } },
        { { end_x, bar->pos.y }, bar->color, { texmax.x, 0.f } },
        { { end_x, end_y }, bar->color, { texmax.x, texmax.y } },
        { { start_x, end_y }, bar->color, { tex_start, texmax.y } },
    };
    sfVertexArray *va = sfVertexArray_create();

    sfVertexArray_setPrimitiveType(va, sfQuads);
    for (int i = 0; i < 4; i++)
        sfVertexArray_append(va, vertices[i]);
    sfRenderWindow_drawVertexArray(win, va, &state);
    sfVertexArray_destroy(va);
}

/*
** Draws a healthbar.
*/
void crpt_draw_healthbar(graphics_healthbar_t healthbar)
{
    window_t *win = crpt_game_get()->window;

    if (healthbar.progress != 0.0)
        draw_full_bar(&healthbar, win);
    if (healthbar.progress != 1.0)
        draw_empty_bar(&healthbar, win);
}
