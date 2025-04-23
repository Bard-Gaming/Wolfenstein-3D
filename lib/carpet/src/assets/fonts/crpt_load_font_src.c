/*
** EPITECH PROJECT, 2025
** Project - Carpet Lib
** File description:
** Implementation for
** crpt_load_font_src
*/

#include <carpet/assets.h>
#include <carpet/errno.h>


/*
** Loads a given font from source and into
** the asset managern associating it to the given id.
*/
void crpt_load_font_src(void *data, size_t len, const char *id)
{
    asset_manager_t *manager = crpt_asset_manager_get();
    font_t *font;

    if (crpt_hashtable_get(&manager->fonts, id) != NULL)
        return crpt_errno_set(CE_AM_REUSED_ID);
    font = sfFont_createFromMemory(data, len);
    if (font == NULL)
        return crpt_errno_set(CE_AM_LOAD_FAIL);
    crpt_hashtable_set(&manager->fonts, id, font);
}
