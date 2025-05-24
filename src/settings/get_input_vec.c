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
vec2_t get_input_vec(void)
{
    sfKeyCode *controls = get_settings()->controls;

    return (vec2_t){
        .x = get_input_diff(controls[0], controls[1]),
        .y = get_input_diff(controls[3], controls[2]) * 0.0125,
    };
}
