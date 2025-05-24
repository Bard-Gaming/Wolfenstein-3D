/*
** EPITECH PROJECT, 2025
** Project - Carpet Lib
** File description:
** Utility mathematics header.
** This header contains utility
** math functions that might be
** used everywhere
*/

#ifndef LIB_CARPET_UTILS_MATH_H
    #define LIB_CARPET_UTILS_MATH_H
    #include <stdlib.h>
    #include <stdint.h>
    #include <math.h>

    #define M_2PI 6.283185307179586


/*
** Normalizes an angle to the range
** [0; 2PI[.
*/
static inline double norm(double angle)
{
    double res = fmod(angle, M_2PI);

    if (res < 0.0)
        res += M_2PI;
    return res;
}

/*
** Normalizes an angle to the range
** ]-PI; PI]. This is especially useful
** for some mathematical formulas, hence
** the name.
*/
static inline double math_norm(double angle)
{
    return angle - M_2PI * floor((angle + M_PI) / M_2PI);
}

/*
** Returns a 32bit random value
** between [0; 2^32[.
*/
static inline uint32_t crpt_rand(uint32_t max)
{
    return ((uint64_t)random() * max) >> 31;
}

/*
** Max function for unsigned integers.
** Note that it's better to use a function
** than a macro to avoid having to recompute
** values that may or may not be expensive.
*/
static inline unsigned int crpt_umin(unsigned int a, unsigned int b)
{
    return a < b ? a : b;
}

static inline unsigned int crpt_umax(unsigned int a, unsigned int b)
{
    return a > b ? a : b;
}



#endif
