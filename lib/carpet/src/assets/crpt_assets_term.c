/*
** EPITECH PROJECT, 2025
** Project - Carpet Lib
** File description:
** Implementation for
** crpt_assets_term
*/

#include <carpet/assets.h>
#include <carpet/utils/hashtable.h>


/*
** Unloads all assets and resets the asset manager
** to its original state.
*/
void crpt_assets_term(void)
{
    asset_manager_t *manager = crpt_asset_manager_get();

    crpt_hashtable_delete(&manager->fonts, (free_fnc_t)sfFont_destroy);
    crpt_hashtable_delete(&manager->textures, (free_fnc_t)sfTexture_destroy);
}
