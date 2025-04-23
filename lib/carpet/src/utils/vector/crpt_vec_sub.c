/*
** EPITECH PROJECT, 2025
** Project - Carpet Lib
** File description:
** Implementation for
** crpt_vec3_sub &&
** crpt_vec2_sub
*/

#include <carpet/utils/vector.h>


/*
** 3D Vector subtraction.
*/
vec3_t crpt_vec3_sub(vec3_t a, vec3_t b)
{
    return (vec3_t){
        .x = a.x - b.x,
        .y = a.y - b.y,
        .z = a.z - b.z,
    };
}

/*
** 2D Vector subtraction.
*/
vec2_t crpt_vec2_sub(vec2_t a, vec2_t b)
{
    return (vec2_t){
        .x = a.x - b.x,
        .y = a.y - b.y,
    };
}
