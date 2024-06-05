#pragma once

#include QMK_KEYBOARD_H
#include "keyrecords/process_records.h"


#define ____ KC_TRNS

enum itg_layers {
    _QWERTY_WIN,
    _QWERTY_GAME,
    _QWERTY_OSX,
    _COLEMAK_WIN,
    _COLEMAK_GAME,
    _COLEMAK_OSX,
    _LOWER,
    _RAISE,
    _ADJUST,
};

enum custom_keycodes {
    LK_QW = SAFE_RANGE,
    LK_QG,
    LK_QO,
    LK_CW,
    LK_CG,
    LK_CO,
    VRSN,
    SCREENSHOT,
    KC_SCT1,
    KC_SCT2,
    KC_SCT3,
    KC_SCT4,
    KC_SCT5,
};

