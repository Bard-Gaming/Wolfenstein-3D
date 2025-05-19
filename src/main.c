/*
** EPITECH PROJECT, 2024
** Project - Wolf3D
** File description:
** Program Entry
*/

#include <wolf/scenes.h>


int main(void)
{
    crpt_game_init();
    set_level_scene();
    crpt_game_mainloop();
    crpt_game_term();
}
