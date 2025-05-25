/*
** EPITECH PROJECT, 2025
** wolf3d
** File description:
** key_to_string
*/

#include <wolf/scenes.h>
#include <wolf/settings.h>
#include <string.h>

static const char *key_alpha_a_to_g(sfKeyCode code)
{
    switch (code) {
        case sfKeyA:
            return "A";
        case sfKeyB:
            return "B";
        case sfKeyC:
            return "C";
        case sfKeyD:
            return "D";
        case sfKeyE:
            return "E";
        case sfKeyF:
            return "F";
        case sfKeyG:
            return "G";
        default:
            return NULL;
    }
}

static const char *key_alpha_h_to_n(sfKeyCode code)
{
    switch (code) {
        case sfKeyH:
            return "H";
        case sfKeyI:
            return "I";
        case sfKeyJ:
            return "J";
        case sfKeyK:
            return "K";
        case sfKeyL:
            return "L";
        case sfKeyM:
            return "M";
        case sfKeyN:
            return "N";
        default:
            return NULL;
    }
}

static const char *key_alpha_o_to_u(sfKeyCode code)
{
    switch (code) {
        case sfKeyO:
            return "O";
        case sfKeyP:
            return "P";
        case sfKeyQ:
            return "Q";
        case sfKeyR:
            return "R";
        case sfKeyS:
            return "S";
        case sfKeyT:
            return "T";
        case sfKeyU:
            return "U";
        default:
            return NULL;
    }
}

static const char *key_alpha_v_to_z(sfKeyCode code)
{
    switch (code) {
        case sfKeyV:
            return "V";
        case sfKeyW:
            return "W";
        case sfKeyX:
            return "X";
        case sfKeyY:
            return "Y";
        case sfKeyZ:
            return "Z";
        default:
            return NULL;
    }
}

static const char *key_digits(sfKeyCode code)
{
    switch (code) {
        case sfKeyNum0:
            return "0";
        case sfKeyNum1:
            return "1";
        case sfKeyNum2:
            return "2";
        case sfKeyNum3:
            return "3";
        case sfKeyNum4:
            return "4";
        case sfKeyNum5:
            return "5";
        case sfKeyNum6:
            return "6";
        case sfKeyNum7:
            return "7";
        case sfKeyNum8:
            return "8";
        case sfKeyNum9:
            return "9";
        default:
            return NULL;
    }
}

static const char *key_arrows(sfKeyCode code)
{
    switch (code) {
        case sfKeyUp:
            return "Up";
        case sfKeyDown:
            return "Down";
        case sfKeyLeft:
            return "Left";
        case sfKeyRight:
            return "Right";
        default:
            return NULL;
    }
}

static const char *key_special(sfKeyCode code)
{
    switch (code) {
        case sfKeyEscape:
            return "ESC";
        case sfKeySpace:
            return "SPACE";
        case sfKeyEnter:
            return "ENTER";
        case sfKeyLControl:
            return "L CTRL";
        case sfKeyRControl:
            return "R CTRL";
        case sfKeyLShift:
            return "L SHIFT";
        case sfKeyRShift:
            return "R SHIFT";
        default:
            return NULL;
    }
}

const char *key_to_string(sfKeyCode code)
{
    const char *result;

    result = key_alpha_a_to_g(code);
    if (result)
        return result;
    result = key_alpha_h_to_n(code);
    if (result)
        return result;
    result = key_alpha_o_to_u(code);
    if (result)
        return result;
    result = key_alpha_v_to_z(code);
    if (result)
        return result;
    result = key_digits(code);
    if (result)
        return result;
    result = key_arrows(code);
    if (result)
        return result;
    result = key_special(code);
    if (result)
        return result;
    return "?";
}