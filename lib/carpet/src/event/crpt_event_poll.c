/*
** EPITECH PROJECT, 2025
** Project - Carpet Lib
** File description:
** Implementation for
** crpt_event_poll
*/

#include <carpet/event.h>
#include <carpet/scene.h>
#include <carpet/game.h>


/*
** Polls all events and runs the appropriate event
** handling function(s) (if present).
** The order of execution is as follows:
** - call the active scene's event handler (if any)
** - call the game's event handler (if any)
*/
void crpt_event_poll(game_t *game)
{
    event_handler_t handle_event;
    sfEvent event;

    while (sfRenderWindow_pollEvent(game->window, &event)) {
        handle_event = game->scene->event_handlers[event.type];
        if (handle_event)
            handle_event(game->scene, &event);
        handle_event = game->event_handlers[event.type];
        if (handle_event)
            handle_event(game->scene, &event);
    }
}
