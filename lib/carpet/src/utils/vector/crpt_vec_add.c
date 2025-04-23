/*
** EPITECH PROJECT, 2025
** Project - Carpet Lib
** File description:
** Implementation for
** crpt_vec3_add &&
** crpt_vec2_add
*/

#include <carpet/utils/vector.h>


/*
** 3D Vector addition.
*/
vec3_t crpt_vec3_add(vec3_t a, vec3_t b)
{
    return (vec3_t){
        .x = a.x + b.x,
        .y = a.y + b.y,
        .z = a.z + b.z,
    };
}

/*
** 2D Vector addition.
*/
vec2_t crpt_vec2_add(vec2_t a, vec2_t b)
{
    return (vec2_t){
        .x = a.x + b.x,
        .y = a.y + b.y,
    };
}
