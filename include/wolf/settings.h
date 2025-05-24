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


typedef struct {
    sfKeyCode controls[5];  // front, back, left, right, sprint
} settings_t;


settings_t *get_settings(void);
vec2_t get_input_vec(void);


#endif
