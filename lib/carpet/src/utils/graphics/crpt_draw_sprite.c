/*
** EPITECH PROJECT, 2025
** Project - Carpet Lib
** File description:
** Implementation for
** crpt_draw_sprite
*/

#include <carpet/utils/graphics.h>
#include <carpet/game.h>


/*
** Utility function to draw a
** sprite onto the screen. Nothing
** much to add there.
*/
void crpt_draw_sprite(const sprite_t *sprite)
{
    game_t *game = crpt_game_get();

    sfRenderWindow_drawSprite(game->window, sprite, NULL);
}
