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

    #define DELTA_TIME_FACTOR 0.00005
    #define ROTATION_SPEED_MAX 0.05
    #define SENSITIVITY_DEFAULT 0.40
    #define MOVE_SPEED 2.0


typedef enum {
    CK_FRONT,
    CK_BACK,
    CK_LEFT,
    CK_RIGHT,
    CK_SPRINT,

    CK_SHOOT,

    CK_WEAPON_NEXT,
    CK_WEAPON_PREV,

    CK_COUNT,  // keep last
} control_key_t;


typedef struct {
    sfKeyCode controls[CK_COUNT];
    double sensitivity;  // between 0.0 and 1.0
    bool sound;
    bool music;
} settings_t;

typedef struct {
    int waiting_for_key;
} settings_state_t;


settings_t *get_settings(void);
vec2_t get_input_vec(time_micro_t dt);
bool is_key_pressed(control_key_t key);


#endif
