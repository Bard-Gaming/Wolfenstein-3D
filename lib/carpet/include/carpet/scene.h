/*
** EPITECH PROJECT, 2025
** Project - Carpet Lib
** File description:
** Header file for everything
** related to the game's scenes
*/

#ifndef LIB_CARPET_SCENE_H
    #define LIB_CARPET_SCENE_H
    #include <carpet/types.h>

    #define _CND_FNC(fnc, ...) if (fnc) fnc(__VA_ARGS__)
    #define _SCENE_FNC(s, f, ...) _CND_FNC(s->f, s, ##__VA_ARGS__)
    #define LOAD_SCENE(scene) _SCENE_FNC(scene, load)
    #define UNLOAD_SCENE(scene) _SCENE_FNC(scene, unload)
    #define UPDATE_SCENE(scene, delta) _SCENE_FNC(scene, update, delta)
    #define UPDATE_SCENE_FIXED(s) _SCENE_FNC(s, fixed_update, CRPT_FIXED_RATE)


struct carpet_ui {
    // User data:
    void *data;

    // Functions:
    ui_draw_fnc_t draw;
    ui_update_fnc_t update;
};


struct carpet_scene {
    // User data:
    NULLABLE map_t *map;
    NULLABLE ui_t *ui;

    // Load:
    NULLABLE scene_fnc_t load;
    NULLABLE scene_fnc_t unload;

    // Process:
    NULLABLE update_fnc_t update;
    NULLABLE update_fnc_t fixed_update;
    event_handler_t event_handlers[sfEvtCount];
};


void crpt_scene_set(NULLABLE scene_t *scene);
void crpt_scene_draw(scene_t *scene, camera_t *cam, window_t *window);

// Default scene:
scene_t *crpt_scene_default_get(void);
void crpt_scene_default_load(scene_t *scene);
void crpt_scene_default_unload(scene_t *scene);
void crpt_scene_default_update(scene_t *scene, time_micro_t dt);


#endif
