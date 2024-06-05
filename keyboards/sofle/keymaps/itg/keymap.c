// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later
#include QMK_KEYBOARD_H

#include "oled.c"
#include "itg.h"

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
 [_QWERTY_WIN] = LAYOUT(
        QK_GESC,  KC_1,   KC_2,    KC_3,    KC_4,    KC_5,                             KC_6,    KC_7,    KC_8,    KC_9,       KC_0,    KC_BSPC, \
        KC_TAB,   KC_Q,   KC_W,    KC_E,    KC_R,    KC_T,                             KC_Y,    KC_U,    KC_I,    KC_O,       KC_P,    KC_BSLS, \
        KC_LCTL,  KC_A,   KC_S,    KC_D,    KC_F,    KC_G,                             KC_H,    KC_J,    KC_K,    KC_L,       KC_SCLN, KC_QUOT, \
        KC_LSFT,  KC_Z,   KC_X,    KC_C,    KC_V,    KC_B,    KC_MUTE,        KC_MNXT, KC_N,    KC_M,    KC_COMM, KC_DOT,     KC_SLSH, RSFT_T(KC_ENT), \
                          _______, KC_LGUI, KC_LALT, TL_LOWR, KC_SPC,         KC_SPC,  TL_UPPR, KC_RALT, KC_RGUI, _______ \
 ),


 /* GAME - Disables hybrid keys */
 [_QWERTY_GAME] = LAYOUT(
        _______, _______, _______, _______, _______, _______,                            _______, _______, _______, _______, _______, _______, \
        _______, _______, _______, _______, _______, _______,                            _______, _______, _______, _______, _______, _______, \
        _______, _______, _______, _______, _______, _______,                            _______, _______, _______, _______, _______, _______, \
        _______, _______, _______, _______, _______, _______, _______,          _______, _______, _______, _______, _______, _______, KC_ENT,  \
                          _______, XXXXXXX, _______, _______, _______,          _______, _______, KC_RGUI, _______, _______ \
 ),

 [_QWERTY_OSX] = LAYOUT(
        _______, _______, _______, _______, _______, _______,                            _______, _______, _______, _______, _______, _______, \
        _______, _______, _______, _______, _______, _______,                            _______, _______, _______, _______, _______, _______, \
        _______, _______, _______, _______, _______, _______,                            _______, _______, _______, _______, _______, _______, \
        _______, _______, _______, _______, _______, _______, _______,          _______, _______, _______, _______, _______, _______, KC_ENT,  \
                          _______, KC_LALT, KC_LGUI, _______, _______,          _______, _______, KC_RGUI, KC_RALT, _______  \
 ),

 [_COLEMAK_WIN] = LAYOUT(
        QK_GESC,  KC_1,   KC_2,    KC_3,    KC_4,    KC_5,                             KC_6,    KC_7,    KC_8,    KC_9,       KC_0,    KC_BSPC, \
        KC_TAB,   KC_Q,   KC_W,    KC_F,    KC_P,    KC_G,                             KC_L,    KC_L,    KC_U,    KC_Y,       KC_SCLN, KC_BSLS, \
        KC_LCTL,  KC_A,   KC_R,    KC_D,    KC_T,    KC_D,                             KC_H,    KC_N,    KC_E,    KC_I,       KC_O, KC_QUOT, \
        KC_LSFT,  KC_Z,   KC_X,    KC_C,    KC_V,    KC_B,    KC_MUTE,        KC_MNXT, KC_K,    KC_M,    KC_COMM, KC_DOT,     KC_SLSH, RSFT_T(KC_ENT), \
                          _______, KC_LGUI, KC_LALT, TL_LOWR, KC_SPC,         KC_SPC,  TL_UPPR, KC_RALT, KC_RGUI, _______ \
 ),

 [_COLEMAK_GAME] = LAYOUT(
        _______, _______, _______, _______, _______, _______,                            _______, _______, _______, _______, _______, _______, \
        _______, _______, _______, _______, _______, _______,                            _______, _______, _______, _______, _______, _______, \
        _______, _______, _______, _______, _______, _______,                            _______, _______, _______, _______, _______, _______, \
        _______, _______, _______, _______, _______, _______, _______,          _______, _______, _______, _______, _______, _______, KC_ENT,  \
                          _______, XXXXXXX, _______, _______, _______,          _______, _______, KC_RGUI, _______, _______ \
 ),

 [_COLEMAK_OSX] = LAYOUT(
        _______, _______, _______, _______, _______, _______,                            _______, _______, _______, _______, _______, _______, \
        _______, _______, _______, _______, _______, _______,                            _______, _______, _______, _______, _______, _______, \
        _______, _______, _______, _______, _______, _______,                            _______, _______, _______, _______, _______, _______, \
        _______, _______, _______, _______, _______, _______, _______,          _______, _______, _______, _______, _______, _______, KC_ENT,  \
                          _______, KC_LALT, KC_LGUI, _______, _______,          _______, _______, KC_RGUI, KC_RALT, _______  \
 ),

 [_LOWER] = LAYOUT(
        KC_GRV,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                              _______, _______, _______, KC_MINS, KC_EQL, KC_DEL,  \
        G(____), G(KC_Q), G(KC_W), G(KC_E), G(KC_R), G(KC_T),                            _______, _______, _______, _______, KC_LBRC, KC_RBRC, \
        G(____), G(KC_A), G(KC_S), G(KC_D), G(KC_F), G(KC_G),                            KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______, _______, \
        G(____), G(KC_Z), G(KC_X), G(KC_C), G(KC_V), G(KC_B), _______,          _______, _______, _______, _______, _______, _______, _______, \
                          _______, _______, _______, _______, _______,          _______, _______, _______, _______, _______ \
 ),

/* MEDIA */
 [_RAISE] = LAYOUT(
        KC_GRV,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                              KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  \
        _______, _______, _______, _______, _______, _______,                            KC_KP_7, KC_KP_8, KC_KP_9, _______, _______, KC_F12,  \
        _______, _______, _______, _______, _______, _______,                            KC_KP_4, KC_KP_5, KC_KP_6, _______, _______, _______, \
        _______, _______, _______, _______, _______, _______, _______,          _______, KC_KP_1, KC_KP_2, KC_KP_3, _______, _______, _______, \
                          _______, _______, _______, _______, _______,          _______, _______, _______, _______, _______ \
 ),

 [_ADJUST] = LAYOUT(
        _______, LK_QW,   LK_QO,   LK_QG,   _______, _______,                            KC_SCT1, KC_SCT2, KC_SCT3, KC_SCT4, KC_SCT5, _______, \
        _______, LK_CW,   LK_CO,   LK_CG,   _______, _______,                            _______, _______, _______, _______, _______, _______, \
        _______, _______, _______, _______, _______, _______,                            _______, _______, _______, _______, _______, _______, \
        _______, _______, _______, _______, _______, _______, _______,          _______, _______, _______, _______, _______, _______, _______, \
                          _______, _______, _______, _______, _______,          _______, _______, _______, _______, _______ \
 ),
};

// _QWERTY_WIN,
// _QWERTY_GAME,
// _QWERTY_OSX,
// _COLEMAK_WIN,
// _COLEMAK_GAME,
// _COLEMAK_OSX,
// _LOWER,
// _RAISE,
// _ADJUST,

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [0] =   { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_WH_U, KC_WH_D)  },
    [1] =   { ENCODER_CCW_CW(_______, _______), ENCODER_CCW_CW(_______, _______)  },
    [2] =   { ENCODER_CCW_CW(_______, _______), ENCODER_CCW_CW(_______, _______)  },
    [3] =   { ENCODER_CCW_CW(_______, _______), ENCODER_CCW_CW(_______, _______)  },
    [4] =   { ENCODER_CCW_CW(_______, _______), ENCODER_CCW_CW(_______, _______)  },
    [5] =   { ENCODER_CCW_CW(_______, _______), ENCODER_CCW_CW(_______, _______)  },
    [6] =   { ENCODER_CCW_CW(_______, _______), ENCODER_CCW_CW(KC_PGUP, KC_PGDN)  },
    [7] =   { ENCODER_CCW_CW(_______, _______), ENCODER_CCW_CW(_______, _______)  },
    [8] =   { ENCODER_CCW_CW(_______, _______), ENCODER_CCW_CW(_______, _______)  }
};
#endif

layer_state_t layer_state_set_user(layer_state_t state) {
  return state;
}

// bool process_detected_host_os_kb(os_variant_t detected_os) {
//     if (!process_detected_host_os_user(detected_os)) {
//         return false;
//     }
//     switch (detected_os) {
//         case OS_IOS:
//             break;
//         case OS_MACOS:
//             set_single_persistent_default_layer(_OSX);
//             break;
//         case OS_WINDOWS:
//             set_single_persistent_default_layer(_QWERTY);
//             break;
//         case OS_LINUX:
//             set_single_persistent_default_layer(_QWERTY);
//             break;
//         case OS_UNSURE:
//             break;
//     }
    
//     return true;
// }
