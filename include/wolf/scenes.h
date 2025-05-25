/*
** EPITECH PROJECT, 2025
** Project - Wolf3D
** File description:
** Header file for the game's
** scenes
*/

#ifndef WOLF_SCENES_H
    #define WOLF_SCENES_H
    #include <carpet.h>
    #define UNUSED __attribute__((unused))


// Start Scene:
void set_start_scene(void);
void load_start_scene(scene_t *scene);
void unload_start_scene(scene_t *scene);
void draw_start_scene_ui(scene_t *scene, window_t *window);
void start_scene_onclick(scene_t *scene, event_t *event);
void start_scene_mouse_move(scene_t *scene, event_t *event);

// settings scene:
void set_settings_scene(void);
void load_settings_scene(scene_t *scene);
void unload_settings_scene(scene_t *scene);
void draw_settings_scene_ui(scene_t *scene, window_t *window);
void settings_scene_onclick(scene_t *scene, event_t *event);
void settings_scene_mouse_move(scene_t *scene, event_t *event);
void settings_scene_key_pressed(scene_t *scene, event_t *event);
const char *key_to_string(sfKeyCode code);

// Level Scene:
void set_level_scene(void);
void load_level_scene(scene_t *scene);
void unload_level_scene(scene_t *scene);
void update_level_scene(scene_t *scene, time_micro_t dt);
void update_level_scene_fixed(scene_t *scene, time_micro_t dt);
void draw_level_scene_ui(scene_t *scene, window_t *window);
void level_scene_release_key(scene_t *scene, event_t *event);


// Death Scene:
void set_death_scene(void);
void load_death_scene(scene_t *scene);
void unload_death_scene(scene_t *scene);
void draw_death_scene_ui(scene_t *scene, window_t *window);
void death_scene_onclick(scene_t *scene, event_t *event);
void death_scene_mouse_move(scene_t *scene, event_t *event);


#endif
