/*
** EPITECH PROJECT, 2025
** Project - Carpet Lib
** File description:
** Implementation for
** crpt_draw_line
*/

#include <carpet/utils/graphics.h>


/*
** sfRenderStates_default() doesn't exist in
** CSFML 2.5.X, so create a function that does
** the same.
*/
static sfRenderStates get_default_state(void)
{
    return (sfRenderStates){
        sfBlendAlpha, sfTransform_Identity,
        NULL, NULL
    };
}

/*
** Draws a line with the given data.
*/
void crpt_draw_line(window_t *win, graphics_line_t line)
{
    sfVertexArray *array = sfVertexArray_create();
    sfRenderStates state = get_default_state();
    sfVertex v1 = {
        { line.start.x, line.start.y },
        line.color,
        { line.tex_start.x, line.tex_start.y },
    };
    sfVertex v2 = {
        { line.end.x, line.end.y },
        line.color,
        { line.tex_end.x, line.tex_end.y },
    };

    state.texture = line.texture;
    sfVertexArray_setPrimitiveType(array, sfLines);
    sfVertexArray_append(array, v1);
    sfVertexArray_append(array, v2);
    sfRenderWindow_drawVertexArray(win, array, &state);
    sfVertexArray_destroy(array);
}
