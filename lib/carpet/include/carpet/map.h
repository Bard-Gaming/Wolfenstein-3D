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

    #define CRPT_DEFAULT_CUBE_SIZE 64.f
    #define CRPT_DEFAULT_TILE_SIZE 12.f


struct carpet_map {
    float cube_size;
    float tile_size;

    unsigned int width;
    unsigned int height;
    object_t ***blocks;

    // Ceiling / Floor textures:
    color_t ceiling;
    color_t floor;
};


// Map process / lifetime:
map_t *crpt_map_create(unsigned int width, unsigned int height);
void crpt_map_draw2(const map_t *map, vec2_t screen_pos);
void crpt_map_draw3(const map_t *map, const camera_t *cam);
void crpt_map_delete(map_t *map);

// Map objects:
object_t *crpt_map_get(const map_t *map, vec2_t position);
void crpt_map_add(map_t *map, object_t *obj);
void crpt_map_remove(map_t *map, object_t *obj);

// Utils:
void crpt_map_randomize(map_t *map, size_t count, const object_t *ref);
void crpt_map_create_border(map_t *map, const object_t *ref);
void crpt_map_fill_empty(map_t *map, const object_t *ref);
bool crpt_map_is_solid(const map_t *map, vec2_t position);


#endif
