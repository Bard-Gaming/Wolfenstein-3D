/*
** EPITECH PROJECT, 2025
** Project - Carpet Lib
** File description:
** Header file for the game's
** objects.
*/

#ifndef LIB_CARPET_OBJECT_H
    #define LIB_CARPET_OBJECT_H
    #include <carpet/types.h>
    #include <carpet/utils/vector.h>

    #define CRPT_OBJECT_MAX_SIZE 1920


/*
** This structure shouldn't be
** modified directly. Please use
** the helper functions in this
** header file to manipulate
** objects.
**
** Note: This struct is a base
** object struct. As a user,
** you are free to "derive" from
** this struct and use your own.
*/
struct carpet_object {
    // Drawing:
    const texture_t *texture;

    // Process:
    /* the following is fixed update (for animations & such) */
    NULLABLE object_update_fnc_t update;
    /* Function used to free the memory allocated for the object */
    NULLABLE free_fnc_t free;

    // World data:
    size_t index;     // object index in map (good for optimization)
    vec2_t position;  // object's position in the map
    double height;    // height (0 for floor level)
    double scale;     // object scale (default: 1.0)
    double cam_dist;  // distance to camera (cached)
};


// Object creation:
object_t *crpt_object_create(const texture_t *texture, vec2_t pos);
void crpt_object_defaults(object_t *object);

// Object utils:
void crpt_object_set_position(object_t *object, vec2_t new);
void crpt_object_move(object_t *object, vec2_t offset);

// Object rendering:
void crpt_object_draw(const object_t *object, const camera_t *cam);


#endif
