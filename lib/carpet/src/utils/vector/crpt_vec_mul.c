/*
** EPITECH PROJECT, 2025
** Project - Carpet Lib
** File description:
** Implementation for
** crpt_vec3_mul &&
** crpt_vec2_mul
*/

#include <carpet/utils/vector.h>


/*
** 3D Vector scaling.
*/
vec3_t crpt_vec3_mul(vec3_t vec, float mul)
{
    return (vec3_t){
        .x = vec.x * mul,
        .y = vec.y * mul,
        .z = vec.z * mul,
    };
}

/*
** 2D Vector scaling.
*/
vec2_t crpt_vec2_mul(vec2_t vec, float mul)
{
    return (vec2_t){
        .x = vec.x * mul,
        .y = vec.y * mul,
    };
}
