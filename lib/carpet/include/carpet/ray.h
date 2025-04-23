/*
** EPITECH PROJECT, 2025
** Project - Carpet Lib
** File description:
** Header file for everything
** to do with raycasting
*/

#ifndef LIB_CARPET_CAMERA_H
    #define LIB_CARPET_CAMERA_H
    #include <carpet/types.h>
    #include <carpet/utils/vector.h>
    #include <carpet/utils/math.h>

    #define CRPT_SHADOW_INTENSITY 0.65f


struct carpet_ray {
    vec2_t pos;
    double dist;
    bool draw_shadow;  // whether or not to draw a shadow
};


ray_t crpt_raycast(vec2_t origin, double rotation, const map_t *map);


#endif
