/*
** EPITECH PROJECT, 2025
** Project - Carpet Lib
** File description:
** Implementation for
** crpt_draw_line
*/

#include <SFML/Graphics/RenderWindow.h>
#include <carpet/utils/graphics.h>
#include <carpet/game.h>


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
void crpt_draw_line(graphics_line_t line)
{
    window_t *win = crpt_game_get()->window;
    sfRenderStates state = get_default_state();
    sfVertex vertices[2] = {
        { { line.start.x, line.start.y }, line.start_color,
            { line.tex_start.x, line.tex_start.y } },
        { { line.end.x, line.end.y }, line.end_color,
            { line.tex_end.x, line.tex_end.y } },
    };

    state.texture = line.texture;
    sfRenderWindow_drawPrimitives(win, vertices, 2, sfLines, &state);
}
