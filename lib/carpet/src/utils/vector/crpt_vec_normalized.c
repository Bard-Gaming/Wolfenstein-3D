/*
** EPITECH PROJECT, 2025
** Project - Carpet Lib
** File description:
** Implementation for
** crpt_vec_normalized
*/

#include <carpet/utils/vector.h>


/*
** Returns a normalized vector,
** i.e. a vector with the same direction,
** but with a magnitude of 1.
*/
vec3_t crpt_vec3_normalized(vec3_t vec)
{
    double length = crpt_vec3_magnitude(vec);

    if (length == 0)
        return vec;
    return (vec3_t){
        .x = vec.x / length,
        .y = vec.y / length,
        .z = vec.z / length,
    };
}

/*
** Returns a normalized vector,
** i.e. a vector with the same direction,
** but with a magnitude of 1.
*/
vec2_t crpt_vec2_normalized(vec2_t vec)
{
    double length = crpt_vec2_magnitude(vec);

    if (length == 0)
        return vec;
    return (vec2_t){
        .x = vec.x / length,
        .y = vec.y / length,
    };
}
