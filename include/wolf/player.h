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

    #define PLAYER_MAX_HEALTH 40.0
    #define PLAYER_START_AMMO 130
    #define PLAYER_FOV (M_PI_2 - 0.225)
    #define PLAYER_SPRINT_FOV (M_PI_2 - 0.15)


typedef enum {
    WT_PISTOL,
    WT_SUBMACHINE_GUN,
    WT_MINIGUN,
    WT_REVOLVER,

    WT_COUNT,  // keep last
} weapon_type_t;


typedef struct {
    double damage;
    double cooldown;  // in seconds
    bool autofire;
    const char *asset_id;
} weapon_t;


typedef struct {
    // Player stats:
    double health;
    unsigned int ammo;

    // Weapon data:
    weapon_type_t weapon;     // selected weapon
    double shoot_delay;       // in seconds
    sprite_t *weapon_sprite;  // cached for performance
    bool holding_fire;

    // Animations:
    sfText *ammo_display;       // ammo counter
    bool is_anim;               // tells whether or not to play an anim
    unsigned int anim_frame;    // current animation frame (neg for no anim)
    unsigned int time_elapsed;  // time elapsed in current frame
    double hurt_time;

    // World Data:
    vec2_t *pos;
} player_t;


extern const weapon_t weapon_lookup[WT_COUNT];


player_t *get_player(void);
void init_player(void);

// Assets:
void load_player_assets(void);
void unload_player_assets(void);

// Runtime:
void player_press_key(event_t *event);
void update_player(const map_t *map, time_micro_t dt);
void update_player_fixed(void);
void draw_player(void);

// Actions:
void player_use_weapon(void);
void set_player_weapon(weapon_type_t weapon);
void hurt_player(double damage);


#endif
