/*
** EPITECH PROJECT, 2025
** Project - Carpet Lib
** File description:
** Implementation for
** crpt_vec_dot
*/

#include <carpet/utils/vector.h>


/*
** Computes the dot product of two
** 3D vectors.
*/
double crpt_vec3_dot(vec3_t a, vec3_t b)
{
    return
        a.x * b.x +
        a.y * b.y +
        a.z * b.z;
}

/*
** Computes the dot product of two
** 2D vectors.
*/
double crpt_vec2_dot(vec2_t a, vec2_t b)
{
    return
        a.x * b.x +
        a.y * b.y;
}
