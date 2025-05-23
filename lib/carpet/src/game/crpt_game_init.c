/*
** EPITECH PROJECT, 2025
** Project - Carpet Lib
** File description:
** Implementation for
** crpt_game_init
*/

#include <carpet/game.h>
#include <carpet/assets.h>
#include <carpet/errno.h>
#include <carpet/scene.h>
#include <carpet/event.h>
#include <carpet/memory.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>


/*
** Gets the best available full screen
** mode for the giv
*/
static sfVideoMode get_best_video_mode(void)
{
    size_t count;
    const sfVideoMode *modes = sfVideoMode_getFullscreenModes(&count);

    if (count == 0)
        return (sfVideoMode){ CRPT_DEFAULT_WIDTH, CRPT_DEFAULT_HEIGHT, 32 };
    return modes[0];
}

/*
** Intializes the engine's window.
*/
static void initialize_window(game_t *game)
{
    sfVideoMode mode = get_best_video_mode();

    game->window = sfRenderWindow_create(
        mode, "Carpet Engine Window",
        sfFullscreen, NULL
    );
    sfRenderWindow_setFramerateLimit(game->window, CRPT_DEFAULT_FPS);
    sfRenderWindow_setPosition(game->window, (sfVector2i){ 0, 0 });
}

static void initialize_camera(camera_t *camera, window_t *window)
{
    sfVector2u window_dim = sfRenderWindow_getSize(window);

    *camera = (camera_t){
        .position = { 66.f, 66.f },
        .rotation = 0.f,
        .fov = M_PI_2,
        .width = window_dim.x,
        .height = window_dim.y,
        .depth_buffer = cmalloc(window_dim.x * sizeof(double)),
    };
}

/*
** Initializes the engine.
*/
void crpt_game_init(void)
{
    game_t *game = crpt_game_get();

    if (game->is_initialized)
        return crpt_errno_set(CE_GAME_DOUBLE_INIT);
    srandom(time(NULL));
    initialize_window(game);
    initialize_camera(&game->camera, game->window);
    crpt_assets_init();
    crpt_event_init(game);
    game->scene = crpt_scene_default_get();
    LOAD_SCENE(game->scene);
    game->is_initialized = true;
}
