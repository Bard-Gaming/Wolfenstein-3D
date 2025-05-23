/*
** EPITECH PROJECT, 2025
** Project - Wolf3D
** File description:
** Header file for the game's
** enemies (base)
*/

#ifndef WOLF_ENEMY_H
    #define WOLF_ENEMY_H
    #include <carpet.h>


typedef enum {
    ES_IDLE,
    ES_MOVE,
    ES_ATTACK,
} enemy_state_t;


/*
** This struct inherits from
** carpet's object struct, hence
** the first field.
*/
typedef struct {
    object_t object;  // /!\ keep first /!|

    enemy_state_t state;
    double health;
    double max_health;
} enemy_t;


enemy_t *create_enemy(const texture_t *texture, vec2_t pos);
void set_enemy_max_health(enemy_t *enemy, double health);


#endif
