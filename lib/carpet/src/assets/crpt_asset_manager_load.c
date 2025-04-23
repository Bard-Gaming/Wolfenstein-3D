/*
** EPITECH PROJECT, 2025
** Project - Carpet Lib
** File description:
** Implementation for
** crpt_asset_manager_load
*/

#include <carpet/assets.h>
#include <carpet/memory.h>
#include <carpet/errno.h>
#include <stdlib.h>


/*
** Exits the program with a critical error.
*/
static void critical_error(void)
{
    crpt_errno_set(CE_AM_LOAD_FAIL);
    crpt_perror("carpet");
    exit(CRPT_CRITICAL_ERROR);
}

/*
** Loads a given asset into the given hashtable
** and associates it to the id.
*/
void crpt_asset_manager_load(crpt_hashtable_t *table,
    const char *path, const char *id, asset_load_fnc_t load_asset)
{
    void *asset;

    if (crpt_hashtable_get(table, id) != NULL)
        return crpt_errno_set(CE_AM_REUSED_ID);
    asset = load_asset(path);
    if (asset == NULL)
        return critical_error();
    crpt_hashtable_set(table, id, asset);
}
