/*
** EPITECH PROJECT, 2025
** Project - Carpet Lib
** File description:
** Header file for carpet lib's
** vector operations
*/

#ifndef LIB_CARPET_VECTOR_H
    #define LIB_CARPET_VECTOR_H
    #include <carpet/types.h>


struct carpet_vec3 {
    double x;
    double y;
    double z;
};


struct carpet_vec2 {
    double x;
    double y;
};


// 3 Dimensional:
vec3_t crpt_vec3_add(vec3_t a, vec3_t b);
vec3_t crpt_vec3_sub(vec3_t a, vec3_t b);
vec3_t crpt_vec3_scale(vec3_t vec, double factor);
vec3_t crpt_vec3_normalized(vec3_t vec);
double crpt_vec3_dot(vec3_t a, vec3_t b);
double crpt_vec3_magnitude(vec3_t vec);
double crpt_vec3_distance(vec3_t a, vec3_t b);

// 2 Dimensional:
vec2_t crpt_vec2_add(vec2_t a, vec2_t b);
vec2_t crpt_vec2_sub(vec2_t a, vec2_t b);
vec2_t crpt_vec2_scale(vec2_t vec, double factor);
vec2_t crpt_vec2_normalized(vec2_t vec);
double crpt_vec2_dot(vec2_t a, vec2_t b);
double crpt_vec2_magnitude(vec2_t vec);
double crpt_vec2_distance(vec2_t a, vec2_t b);


#endif
