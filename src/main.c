/*
** EPITECH PROJECT, 2024
** Project - Wolf3D
** File description:
** Program Entry
*/

#include <wolf.h>


int main(void)
{
    settings_t *settings = get_settings();

    settings->controls[0] = sfKeyUp;  // change les contrôles pour avancer à W
    settings->controls[1] = sfKeyDown;  // change les contrôles pour reculer à S
    settings->controls[2] = sfKeyLeft;  // change les contrôles pour tourner à gauche à A
    settings->controls[3] = sfKeyRight;  // change les contrôles pour avancer à droite à D
    crpt_game_init();
    set_start_scene();
    crpt_game_mainloop();
    crpt_game_term();
}
