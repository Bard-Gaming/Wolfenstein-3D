/*
** EPITECH PROJECT, 2025
** Project - Carpet Lib
** File description:
** Header file for everything
** related to event handling
*/

#ifndef LIB_CARPET_EVENT_H
    #define LIB_CARPET_EVENT_H
    #include <carpet/types.h>


void crpt_event_init(game_t *game);
void crpt_event_poll(game_t *game);
void crpt_event_close(scene_t *scene, event_t *event);


#endif
