/*
** EPITECH PROJECT, 2025
** Project - Carpet Lib
** File description:
** Implementation for
** crpt_draw_line
*/

#include <carpet/utils/graphics.h>


/*
** Draws a line of the given color
** from the start position to the
** end position (screen space).
*/
void crpt_draw_line(window_t *window, vec2_t start, vec2_t end, color_t color)
{
    sfVertexArray *array = sfVertexArray_create();
    sfVertex vertices[2] = {
        { { start.x, start.y }, color, { 0, 0 } },
        { { start.x, end.y }, color, { 0, 0 } },
    };

    sfVertexArray_setPrimitiveType(array, sfLines);
    sfVertexArray_append(array, vertices[0]);
    sfVertexArray_append(array, vertices[1]);
    sfRenderWindow_drawVertexArray(window, array, NULL);
    sfVertexArray_destroy(array);
}
