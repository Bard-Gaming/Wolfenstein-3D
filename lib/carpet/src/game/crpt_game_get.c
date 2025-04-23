/*
** EPITECH PROJECT, 2025
** Project - Carpet Lib
** File description:
** Implementation for
** crpt_game_get
*/

#include <carpet/game.h>


/*
** Returns a pointer to the engine's
** game singleton.
** The game's singleton is initialized
** to 0, meaning that the is_initialized
** boolean is false by default (as expected).
*/
game_t *crpt_game_get(void)
{
    static game_t game = { 0 };

    return &game;
}
