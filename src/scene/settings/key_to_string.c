/*
** EPITECH PROJECT, 2025
** wolf3d
** File description:
** key_to_string
*/

#include <wolf/scenes.h>
#include <wolf/settings.h>


static const char *key_repr[sfKeyCount] = {
    "A", "B", "C", "D", "E", "F", "G", "H", "I",
    "J", "K", "L", "M", "N", "O", "P", "Q", "R",
    "S", "T", "U", "V", "W", "X", "Y", "Z",

    "0", "1", "2", "3", "4", "5", "6", "7", "8",
    "9",

    [sfKeyLeft] = "Left",
    [sfKeyRight] = "Right",
    [sfKeyUp] = "Up",
    [sfKeyDown] = "Down",

    [sfKeyEscape ... sfKeyDivide] = "?",
    [sfKeyNumpad0 ... sfKeyPause] = "?",
};


const char *key_to_string(sfKeyCode code)
{
    return key_repr[code];
}
