#pragma once

#include "quantum.h"

#define QWE 0
#define OSX 1
#define SYM 2
#define MED 3  // media keys
#define STN 4

enum custom_keycodes {
    DF_QWE,
    DF_OSX,
    KC_SCT1,
    KC_SCT2,
    KC_SCT3,
    KC_SCT4,
    KC_SCT5,
};

bool process_record_secrets(uint16_t keycode, keyrecord_t *record);
bool process_record_keymap( uint16_t keycode, keyrecord_t *record);

