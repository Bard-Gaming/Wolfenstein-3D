/*
** EPITECH PROJECT, 2025
** Project - Wolf3D
** File description:
** Implementation for
** get_input_vec
*/

#include <wolf/settings.h>


/*
** Gets the difference between the input
** values of the given keys.
*/
static double get_input_diff(sfKeyCode a, sfKeyCode b)
{
    return
        sfKeyboard_isKeyPressed(a) -
        sfKeyboard_isKeyPressed(b);
}

/*
** Retrieves the input vector of the user.
** The vector contains the forward momentum (x),
** as well as the rotation offset (y).
*/
vec2_t get_input_vec(time_micro_t dt)
{
    settings_t *settings = get_settings();
    sfKeyCode *controls = settings->controls;
    double r_speed = settings->sensitivity * ROTATION_SPEED_MAX;

    return (vec2_t){
        .x = get_input_diff(controls[CK_FRONT], controls[CK_BACK]) *
            dt * DELTA_TIME_FACTOR * MOVE_SPEED,
        .y = get_input_diff(controls[CK_RIGHT], controls[CK_LEFT]) *
            r_speed * dt * DELTA_TIME_FACTOR,
    };
}
