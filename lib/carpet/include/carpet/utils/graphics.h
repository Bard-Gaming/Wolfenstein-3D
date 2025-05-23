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
    color_t start_color;
    color_t end_color;
};


struct carpet_graphics_healthbar {
    // Screen position:
    vec2_t pos;
    vec2_t dimensions;

    // Data:
    double progress;  // value between 0.0 and 1.0

    // Display:
    const texture_t *empty;
    const texture_t *full;
    color_t color;
};


struct carpet_graphics_map_texture {
    const texture_t *texture;

    // Screen position:
    double x;
    double y;

    // Spatial info:
    double dist;   // dist to cam
    double scale;  // scale it should be drawn in

    // Texture scale:
    unsigned int width;
    unsigned int height;
};


void crpt_draw_line(graphics_line_t line);
void crpt_draw_map_texture(graphics_map_texture_t texture);
void crpt_draw_sprite(const sprite_t *sprite);
void crpt_draw_solid_square(vec2_t pos, double len, color_t col);
void crpt_draw_healthbar(graphics_healthbar_t healthbar);


#endif
