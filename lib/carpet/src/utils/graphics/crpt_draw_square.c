/*
** EPITECH PROJECT, 2025
** Project - Carpet Lib
** File description:
** Implementation for
** crpt_draw_square
*/

#include <SFML/Graphics/RectangleShape.h>
#include <SFML/Graphics/RenderWindow.h>
#include <carpet/utils/graphics.h>


/*
** Draws a solid square onto the screen.
** Nothing much to add there.
*/
void crpt_draw_square(window_t *win, vec2_t pos, double len, color_t col)
{
    sfRectangleShape *rect = sfRectangleShape_create();

    if (rect == NULL)
        return;
    sfRectangleShape_setPosition(rect, (sfVector2f){ pos.x, pos.y });
    sfRectangleShape_setSize(rect, (sfVector2f){ len, len });
    sfRectangleShape_setFillColor(rect, col);
    sfRenderWindow_drawRectangleShape(win, rect, NULL);
    sfRectangleShape_destroy(rect);
}
