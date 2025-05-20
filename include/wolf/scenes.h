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


// Level Scene:
void set_level_scene(void);
void load_level_scene(scene_t *scene);
void unload_level_scene(scene_t *scene);
void update_level_scene(scene_t *scene, time_micro_t dt);
void draw_level_scene_ui(scene_t *scene, window_t *window);


#endif
