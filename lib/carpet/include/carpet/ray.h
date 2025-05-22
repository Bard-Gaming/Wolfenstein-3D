/*
** EPITECH PROJECT, 2025
** Project - Carpet Lib
** File description:
** Header file for everything
** to do with raycasting
*/

#ifndef LIB_CARPET_RAY_H
    #define LIB_CARPET_RAY_H
    #include <carpet/types.h>
    #include <carpet/utils/vector.h>
    #include <carpet/utils/math.h>

    #define CRPT_SHADOW_INTENSITY 0.65f
    #define CRPT_DISTANCE_FALLOFF 0.55


enum carpet_ray_side {
    RS_VERTICAL,
    RS_HORIZONTAL,
};


struct carpet_ray {
    ray_side_t side;
    double angle;
    double dist;
    vec2_t pos;
};


ray_t crpt_raycast(vec2_t origin, double rotation, const map_t *map);
void crpt_ray_draw3(ray_t ray, double x,
    const map_t *map, const camera_t *cam);


#endif
