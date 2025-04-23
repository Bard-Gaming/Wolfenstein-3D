/*
** EPITECH PROJECT, 2025
** Project - Carpet Lib
** File description:
** Implementation for
** crpt_event_init
*/

#include <carpet/event.h>
#include <carpet/game.h>


/*
** Initializes the game's default event handlers.
** These event handlers are used if the user doesn't
** define event handlers for a given event.
*/
void crpt_event_init(game_t *game)
{
    game->event_handlers[sfEvtClosed] = crpt_event_close;
}
