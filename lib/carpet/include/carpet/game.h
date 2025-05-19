/*
** EPITECH PROJECT, 2025
** Project - Carpet Lib
** File description:
** Header file for carpet's
** game singleton.
*/

#ifndef LIB_CARPET_GAME_H
    #define LIB_CARPET_GAME_H
    #include <carpet/types.h>
    #include <carpet/camera.h>

    #define CRPT_DEFAULT_WIDTH 1920
    #define CRPT_DEFAULT_HEIGHT 1080
    #define CRPT_DEFAULT_FPS 144


struct carpet_game {
    camera_t camera;
    scene_t *scene;
    event_handler_t event_handlers[sfEvtCount];

    // Internal data:
    bool is_initialized;
    window_t *window;
};


// User functions:
void crpt_game_init(void);
void crpt_game_mainloop(void);
void crpt_game_stop(void);
void crpt_game_abrt(void);
void crpt_game_term(void);

// Internal functions:
game_t *crpt_game_get(void);


#endif
