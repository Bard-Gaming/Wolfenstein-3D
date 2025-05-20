/*
** EPITECH PROJECT, 2025
** Project - Carpet Lib
** File description:
** Header
*/

#ifndef LIB_CARPET_TYPES_H
    #define LIB_CARPET_TYPES_H
    #include <SFML/Graphics.h>
    #include <stdbool.h>

    #define NULLABLE
    #define UNSAFE

    // Constants:
    #define CRPT_FIXED_RATE (10 * 1000)  // 10 ms


/////////////////////////////////////////////////////////////
//                                                         //
//                       Type aliases                      //
//                                                         //
/////////////////////////////////////////////////////////////

typedef unsigned long long time_micro_t;  // time (in µs)
typedef sfRenderStates render_state_t;
typedef sfRenderWindow window_t;
typedef sfTexture texture_t;
typedef sfShader shader_t;
typedef sfEvent event_t;
typedef sfColor color_t;
typedef sfFont font_t;


/////////////////////////////////////////////////////////////
//                                                         //
//                        Structures                       //
//                                                         //
/////////////////////////////////////////////////////////////

typedef struct carpet_asset_manager asset_manager_t;
typedef struct carpet_graphics_line graphics_line_t;
typedef struct carpet_map_face map_face_t;
typedef struct carpet_camera camera_t;
typedef struct carpet_object object_t;
typedef struct carpet_scene scene_t;
typedef struct carpet_game game_t;
typedef struct carpet_vec3 vec3_t;
typedef struct carpet_vec2 vec2_t;
typedef struct carpet_ray ray_t;
typedef struct carpet_map map_t;
typedef struct carpet_ui ui_t;

// Utils (prefixed with crpt):
typedef struct carpet_hashtable crpt_hashtable_t;
typedef struct carpet_array crpt_array_t;


/////////////////////////////////////////////////////////////
//                                                         //
//                       Enumerations                      //
//                                                         //
/////////////////////////////////////////////////////////////

typedef enum carpet_object_type object_type_t;
typedef enum carpet_ray_side ray_side_t;
typedef enum carpet_errno crpt_errno_t;


/////////////////////////////////////////////////////////////
//                                                         //
//                         Functions                       //
//                                                         //
/////////////////////////////////////////////////////////////

typedef void (*update_fnc_t)(scene_t *, time_micro_t);
typedef void (*event_handler_t)(scene_t *, event_t *);
typedef void (*ui_draw_fnc_t)(scene_t *, window_t *);
typedef void *(*asset_load_fnc_t)(const char *);
typedef void (*scene_fnc_t)(scene_t *);
typedef void (*free_fnc_t)(void *);


#endif
