/*
** EPITECH PROJECT, 2025
** Project - Carpet Lib
** File description:
** Header file for carpet lib's
** camera / player view
*/

#ifndef LIB_CARPET_CAMERA_H
    #define LIB_CARPET_CAMERA_H
    #include <carpet/types.h>
    #include <carpet/utils/vector.h>


struct carpet_camera {
    // Camera world pos:
    vec2_t position;
    double rotation;
    double fov;

    // Screen data:
    unsigned int width;
    unsigned int height;
};


// User functions:
void crpt_camera_set_fov(double new);
double crpt_camera_get_fov(void);
void crpt_camera_interpolate_fov(double end, double step);

void crpt_camera_set_rotation(double new);
double crpt_camera_get_rotation(void);
void crpt_camera_rotate(double offset);

vec2_t *crpt_camera_get_position(void);


#endif
