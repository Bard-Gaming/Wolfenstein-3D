/*
** EPITECH PROJECT, 2025
** Project - Wolf3D
** File description:
** Header file for the game's
** settings.
*/

#ifndef WOLF_SETTINGS_H
    #define WOLF_SETTINGS_H
    #include <carpet.h>
    #define SETTINGS_PATH "assets/textures/widgets/settings/"


typedef struct {
    sfKeyCode controls[5];  // front, back, left, right, sprint
    bool sound_enabled;
    bool music_enabled;
} settings_t;

typedef struct {
    int waiting_for_key;
} settings_state_t;


settings_t *get_settings(void);
vec2_t get_input_vec(void);


#endif
