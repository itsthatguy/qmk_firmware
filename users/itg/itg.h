#pragma once

#include QMK_KEYBOARD_H
#include "keyrecords/process_records.h"


#define ____ KC_TRNS

// #define _QWERTY 0
// #define _GAME 1
// #define _OSX 2
// #define _LOWER 3
// #define _RAISE 4
// #define _ADJUST 5
enum itg_layers {
    _QWERTY,
    _GAME,
    _OSX,
    _LOWER,
    _RAISE,
    _ADJUST,
};

enum custom_keycodes {
    LK_QWRT = SAFE_RANGE,
    LK_OSX,
    LK_GAME,
    VRSN,
    SCREENSHOT,
    KC_SCT1,
    KC_SCT2,
    KC_SCT3,
    KC_SCT4,
    KC_SCT5,
};

