/*
** EPITECH PROJECT, 2025
** Project - Carpet Lib
** File description:
** Header file for the carpet lib's
** maps.
*/

#ifndef LIB_CARPET_MAP_H
    #define LIB_CARPET_MAP_H
    #include <carpet/types.h>
    #include <carpet/utils/array.h>
    #include <carpet/utils/vector.h>

    #define CRPT_DEFAULT_CUBE_SIZE 64.f
    #define CRPT_DEFAULT_TILE_SIZE 12.f


enum carpet_map_cell_type {
    MCT_EMPTY,  // Nothing. No collisions and doesn't draw anything.
    MCT_WALL,   // Solid wall. Does collisions and draws texture + color.
};


struct carpet_map_cell {
    map_cell_type_t type;
    const texture_t *texture;
    color_t color;
};


struct carpet_map {
    // Absolute to world position:
    float cell_size;
    float tile_size;

    // Cells:
    unsigned int width;
    unsigned int height;
    map_cell_t **cells;

    // Objects:
    crpt_array_t objects;

    // Ceiling / Floor textures:
    color_t ceiling;
    color_t floor;
};


// Map process / lifetime:
map_t *crpt_map_create(unsigned int width, unsigned int height);
void crpt_map_delete(map_t *map);

// Drawing:
void crpt_map_draw2(const map_t *map, vec2_t screen_pos);
void crpt_map_draw3(const map_t *map, camera_t *cam);

// Map cells:
map_cell_t *crpt_map_get_cell(const map_t *map, vec2_t position);
vec2_t crpt_map_cell_coords(const map_t *map, vec2_t position);

// Objects:
void crpt_map_add_object(map_t *map, object_t *object);
void crpt_map_remove_object(map_t *map, object_t *object);
void crpt_map_delete_object(map_t *map, object_t *object);

// Utils:
void crpt_map_randomize(map_t *map, size_t count, const map_cell_t *ref);
void crpt_map_create_border(map_t *map, const map_cell_t *ref);
void crpt_map_fill_empty(map_t *map, const map_cell_t *ref);
bool crpt_map_is_solid(const map_t *map, vec2_t position);


#endif
