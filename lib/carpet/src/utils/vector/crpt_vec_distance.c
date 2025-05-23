/*
** EPITECH PROJECT, 2025
** Project - Carpet Lib
** File description:
** Implementation for
** crpt_vec3_distance &&
** crpt_vec2_distance
*/

#include <carpet/utils/vector.h>


/*
** Retrieves the distance
** between two 3D vectors.
*/
double crpt_vec3_distance(vec3_t a, vec3_t b)
{
    vec3_t diff = crpt_vec3_sub(b, a);

    return crpt_vec3_magnitude(diff);
}

/*
** Retrieves the distance
** between 2D vectors.
*/
double crpt_vec2_distance(vec2_t a, vec2_t b)
{
    vec2_t diff = crpt_vec2_sub(b, a);

    return crpt_vec2_magnitude(diff);
}
