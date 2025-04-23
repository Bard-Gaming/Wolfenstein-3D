/*
** EPITECH PROJECT, 2025
** Project - Carpet Lib
** File description:
** Implementation for
** crpt_game_mainloop
*/

#include <carpet/game.h>
#include <carpet/event.h>
#include <carpet/scene.h>
#include <carpet/errno.h>

/*
** Displays the game.
*/
static void display_game(game_t *game)
{
    sfRenderWindow_clear(game->window, sfBlack);
    crpt_scene_draw(game->scene, &game->camera, game->window);
    sfRenderWindow_display(game->window);
}

/*
** Runs the game's main loop.
** A call to this function will not halt
** unless a call to a stopping function
** is made.
** Stopping functions are:
** - crpt_game_stop()
** - crpt_game_abrt()
*/
void crpt_game_mainloop(void)
{
    game_t *game = crpt_game_get();
    time_micro_t delta = 0;
    sfClock *clock;

    if (!game->is_initialized)
        return crpt_errno_set(CE_GAME_NO_INIT);
    clock = sfClock_create();
    while (sfRenderWindow_isOpen(game->window)) {
        crpt_event_poll(game);
        delta += sfClock_restart(clock).microseconds;
        UPDATE_SCENE(game->scene, delta);
        while (delta >= CRPT_FIXED_RATE) {
            UPDATE_SCENE_FIXED(game->scene);
            delta -= CRPT_FIXED_RATE;
        }
        display_game(game);
    }
    sfClock_destroy(clock);
}
