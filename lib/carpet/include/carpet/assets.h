/*
** EPITECH PROJECT, 2025
** Project - Carpet Lib
** File description:
** Header file for the library's
** asset manager
*/

#ifndef LIB_CARPET_ASSETS_H
    #define LIB_CARPET_ASSETS_H
    #include <carpet/types.h>
    #include <carpet/utils/hashtable.h>

    #define _FNC_NAME(type) crpt_load_ ## type ## _src
    #define _ASS_NAME(name) (void *)crpt_asset_ ## name
    #define _ASS_LEN(name) crpt_asset_ ## name ## _len
    #define _LOAD_DEFAULT(t, n) _FNC_NAME(t) (_ASS_NAME(n), _ASS_LEN(n), #n)


struct carpet_asset_manager {
    crpt_hashtable_t fonts;
    crpt_hashtable_t textures;
    crpt_hashtable_t sprites;
};


// General:
void crpt_assets_init(void);
void crpt_assets_term(void);

// Fonts:
void crpt_load_font(const char *path, const char *id);
void crpt_unload_font(const char *id);
UNSAFE void crpt_load_font_src(void *data, size_t len, const char *id);
font_t *crpt_fetch_font(const char *id);

// Textures:
void crpt_load_texture(const char *path, const char *id);
void crpt_unload_texture(const char *id);
UNSAFE void crpt_load_texture_src(void *data, size_t len, const char *id);
texture_t *crpt_fetch_texture(const char *id);

// Sprite:
void crpt_load_sprite(const texture_t *texture, const char *id);
void crpt_unload_sprite(const char *id);
sprite_t *crpt_fetch_sprite(const char *id);

// Internal:
asset_manager_t *crpt_asset_manager_get(void);
void crpt_asset_manager_load(crpt_hashtable_t *table,
    const char *path, const char *id, asset_load_fnc_t load_asset);

// Default Assets:
extern const unsigned int crpt_asset_arial_len;
extern const unsigned char crpt_asset_arial[];


#endif
