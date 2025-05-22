/*
** EPITECH PROJECT, 2025
** Project - Carpet Lib
** File description:
** Implementation for
** crpt_vec3_magnitude &&
** crpt_vec2_magnitude
*/

#include <carpet/utils/vector.h>
#include <math.h>


/*
** Retrieves the magnitude of a given
** 3D vector.
*/
double crpt_vec3_magnitude(vec3_t vec)
{
    return sqrt(
        vec.x * vec.x +
        vec.y * vec.y +
        vec.z * vec.z
    );
}

/*
** Retrieves the magnitude of a given
** 2D vector.
*/
double crpt_vec2_magnitude(vec2_t vec)
{
    return sqrt(
        vec.x * vec.x +
        vec.y * vec.y
    );
}
