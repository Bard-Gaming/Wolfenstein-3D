/*
** EPITECH PROJECT, 2025
** Project - Carpet Lib
** File description:
** Implementation for
** crpt_scene_set
*/

#include <carpet/scene.h>
#include <carpet/game.h>
#include <carpet/errno.h>


/*
** Set the game's active scene to the
** given scene. If NULL is given,
** the game will switch to its default
** scene.
*/
void crpt_scene_set(scene_t *scene)
{
    game_t *game = crpt_game_get();

    if (!game->is_initialized)
        return crpt_errno_set(CE_GAME_NO_INIT);
    UNLOAD_SCENE(game->scene);
    game->scene = scene ?: crpt_scene_default_get();
    LOAD_SCENE(game->scene);
}
