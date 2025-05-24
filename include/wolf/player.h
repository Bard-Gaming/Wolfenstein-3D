/*
** EPITECH PROJECT, 2025
** Project - Wolf3D
** File description:
** Header file for everything
** related to the player
*/

#ifndef WOLF_PLAYER_H
    #define WOLF_PLAYER_H
    #include <carpet.h>

    #define PLAYER_MAX_HEALTH 20.0
    #define PLAYER_START_AMMO 130
    #define PLAYER_FOV (M_PI_2 - 0.225)
    #define PLAYER_SPRINT_FOV (M_PI_2 - 0.15)


typedef struct {
    // Player stats:
    double health;
    unsigned int ammo;
    double shoot_delay;

    // World Data:
    vec2_t *pos;
} player_t;


player_t *get_player(void);
void init_player(void);

// Assets:
void load_player_assets(void);
void unload_player_assets(void);

void update_player(const map_t *map, time_micro_t dt);
void draw_player(void);


#endif
