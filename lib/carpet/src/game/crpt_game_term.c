/*
** EPITECH PROJECT, 2025
** Project - Carpet Lib
** File description:
** Implementation for
** crpt_game_term
*/

#include <carpet/game.h>
#include <carpet/scene.h>


/*
** Terminates the game engine, freeing
** all necessary memory in the process.
** The game engine is then state in its
** initial state, meaning that starting
** the engine anew after this call is
** still possible.
*/
void crpt_game_term(void)
{
    game_t *game = crpt_game_get();

    UNLOAD_SCENE(game->scene);
    sfRenderWindow_destroy(game->window);
    *game = (game_t){ 0 };
}
