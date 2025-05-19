/*
** EPITECH PROJECT, 2025
** Project - Carpet Lib
** File description:
** Implementation for
** crpt_vec3_scale &&
** crpt_vec2_scale
*/

#include <carpet/utils/vector.h>


/*
** 3D Vector scaling.
*/
vec3_t crpt_vec3_scale(vec3_t vec, double factor)
{
    return (vec3_t){
        .x = vec.x * factor,
        .y = vec.y * factor,
        .z = vec.z * factor,
    };
}

/*
** 2D Vector scaling.
*/
vec2_t crpt_vec2_scale(vec2_t vec, double factor)
{
    return (vec2_t){
        .x = vec.x * factor,
        .y = vec.y * factor,
    };
}
