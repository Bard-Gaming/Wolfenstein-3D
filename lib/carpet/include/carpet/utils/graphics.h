/*
** EPITECH PROJECT, 2025
** Project - Carpet Lib
** File description:
** Header file for
** graphics utilities
*/

#ifndef LIB_CARPET_UTILS_GRAPHICS_H
    #define LIB_CARPET_UTILS_GRAPHICS_H
    #include <carpet/types.h>
    #include <carpet/utils/vector.h>


struct carpet_graphics_line {
    // Screen Position:
    vec2_t start;
    vec2_t end;

    // Texture:
    const texture_t *texture;
    vec2_t tex_start;
    vec2_t tex_end;

    // Color:
    color_t color;
};


void crpt_draw_line(window_t *win, graphics_line_t line);
void crpt_draw_square(window_t *win, vec2_t pos, double len, color_t col);



#endif
