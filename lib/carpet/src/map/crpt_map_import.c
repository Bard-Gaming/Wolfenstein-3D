/*
** EPITECH PROJECT, 2025
** Project - Carpet Lib
** File description:
** Implementation for
** crpt_map_import
*/

#include <carpet/map.h>
#include <carpet/errno.h>
#include <carpet/assets.h>
#include <stdlib.h>
#include <stdio.h>


/*
** Causes a critical error with the
** appropriate error message.
*/
static void critical_error(crpt_errno_t error)
{
    crpt_errno_set(error);
    crpt_perror("carpet");
    exit(CRPT_CRITICAL_ERROR);
}

/*
** Basically fread with automatic error
** handling. Nothing much to add there.
*/
static void read_file(void *restrict ptr, size_t size, size_t n, FILE *stream)
{
    if (fread(ptr, size, n, stream) != n)
        critical_error(CE_MAP_INVALID_FILE);
}

static void load_texture_id(char *buf, FILE *stream)
{
    unsigned int i;
    char current;

    read_file(&current, sizeof(char), 1, stream);
    for (i = 0; current != '\0' && i < CRPT_MAP_TEXTURE_MAX - 1; i++) {
        buf[i] = current;
        read_file(&current, sizeof(char), 1, stream);
    }
    buf[i] = '\0';
}

/*
** Loads a single cell into the map
** buffer.
*/
static void load_cell(map_t *map, FILE *stream, unsigned int x, unsigned int y)
{
    char texture_id[CRPT_MAP_TEXTURE_MAX];
    unsigned char is_wall;
    color_t color;
    char current;

    read_file(&is_wall, sizeof(char), 1, stream);
    if (!is_wall)
        return;
    load_texture_id(texture_id, stream);
    read_file(&color, sizeof(char), 4, stream);
    map->cells[y][x].texture = crpt_fetch_texture(texture_id);
    map->cells[y][x].color = color;
    map->cells[y][x].type = MCT_WALL;
}

/*
** Loads the map's cells into the
** given map buffer.
*/
static void load_cells(map_t *map, FILE *stream)
{
    for (unsigned int x = 0; x < map->width; x++)
        for (unsigned int y = 0; y < map->height; y++)
            load_cell(map, stream, x, y);
}

/*
** Imports a map from the given file.
** This results in a critical error if
** the file doesn't exist, as this would
** most likely be a programmer error.
*/
map_t *crpt_map_import(const char *path)
{
    FILE *file = fopen(path, "rb");
    unsigned int x;
    unsigned int y;
    map_t *map;

    if (file == NULL)
        critical_error(CE_AM_LOAD_FAIL);
    read_file(&x, sizeof(int), 1, file);
    read_file(&y, sizeof(int), 1, file);
    map = crpt_map_create(x, y);
    load_cells(map, file);
    fclose(file);
    return map;
}
