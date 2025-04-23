/*
** EPITECH PROJECT, 2025
** Project - Carpet Lib
** File description:
** Implementation for
** crpt_game_stop
*/

#include <carpet/game.h>


/*
** Stops the game from running.
** This closes the game's window.
*/
void crpt_game_stop(void)
{
    game_t *game = crpt_game_get();

    sfRenderWindow_close(game->window);
}
