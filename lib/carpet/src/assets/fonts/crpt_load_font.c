/*
** EPITECH PROJECT, 2025
** Project - Carpet Lib
** File description:
** Implementation for
** crpt_load_font
*/

#include <carpet/assets.h>
#include <carpet/errno.h>


/*
** Loads a given font into the asset manager
** and associates it to the given id.
*/
void crpt_load_font(const char *path, const char *id)
{
    asset_manager_t *manager = crpt_asset_manager_get();

    return crpt_asset_manager_load(
        &manager->fonts, path, id,
        (asset_load_fnc_t)sfFont_createFromFile
    );
}
