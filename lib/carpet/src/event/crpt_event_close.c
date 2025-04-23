/*
** EPITECH PROJECT, 2025
** Project - Carpet Lib
** File description:
** Implementation for
** crpt_event_close
*/

#include <carpet/event.h>
#include <carpet/game.h>


/*
** Carpet Lib's default close event handler.
** All this does is stop the game.
*/
void crpt_event_close(scene_t *scene, event_t *event)
{
    (void)scene;
    (void)event;
    crpt_game_stop();
}
