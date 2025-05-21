/*
** EPITECH PROJECT, 2025
** Project - Carpet Lib
** File description:
** Implementation for
** crpt_unload_font
*/

#include <carpet/assets.h>


/*
** Unloads the font associated to the
** given id. If no font is associated to id,
** this does nothing.
*/
void crpt_unload_font(const char *id)
{
    asset_manager_t *manager = crpt_asset_manager_get();

    crpt_hashtable_unset(&manager->fonts, id, (free_fnc_t)sfFont_destroy);
}
