/*
** EPITECH PROJECT, 2025
** Project - Carpet Lib
** File description:
** Header file for Carpet Lib's
** map objects.
*/

#ifndef LIB_CARPET_OBJECT_H
    #define LIB_CARPET_OBJECT_H
    #include <carpet/types.h>
    #include <carpet/utils/vector.h>


struct carpet_object {
    // Map Info:
    vec2_t position;
    map_t *map;

    // Display:
    const texture_t *texture;
    color_t color;
    bool draw_solid;  // whether or not to draw the object as a solid cube
};


object_t *crpt_object_create(vec2_t pos);
void crpt_object_delete(object_t *object);
object_t *crpt_object_dup(const object_t *reference, vec2_t pos);

// Internal:
object_t *crpt_object_create_in_map(map_t *map, vec2_t pos);
object_t *crpt_object_dup_in_map(const object_t *ref, map_t *map, vec2_t pos);


#endif
