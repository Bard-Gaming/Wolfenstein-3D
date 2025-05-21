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

    #define PLAYER_MAX_HEALTH 20


typedef struct {
    // Player stats:
    unsigned int health;

    // World Data:
    vec2_t *pos;
} player_t;


player_t *get_player(void);
void init_player(void);


#endif
