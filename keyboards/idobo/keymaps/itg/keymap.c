/* Copyright 2018 Milton Griffin
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include QMK_KEYBOARD_H
#include "keymap_steno.h"
#include "itg.h"

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* QWERTY
 * .--------------------------------------------------------------------------------------------------------------------------------------.
 * | ESC~   | 1      | 2      | 3      | 4      | 5      | `      | -      | =      | 6      | 7      | 8      | 9      | 0      | BACKSP |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------|
 * | TAB    | Q      | W      | E      | R      | T      | NP 7   | NP 8   | NP 9   | Y      | U      | I      | O      | P      | \      |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------+--------|
 * | LCTRL  | A      | S      | D      | F      | G      | NP 4   | NP 5   | NP 6   | H      | J      | K      | L      | ;      | '      |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------------------------+--------|
 * | LSHIFT | Z      | X      | C      | V      | B      | NP 1   | NP 2   | NP 3   | N      | M      | ,      | .      | /      | ENTER  |
 * |--------+--------+--------+--------+--------+-----------------+--------+--------+--------+--------+-----------------+--------+--------|
 * |        | LGUI   | LALT   | MO(MED)| MO(SYM)| SPACE  | NP 0   | DOT    | RETURN | SPACE  | MO(SYM)| MO(MED)| RALT   | RGUI   |        |
 * '--------------------------------------------------------------------------------------------------------------------------------------'
 */

 [QWE] = LAYOUT_ortho_5x15(
        KC_GESC, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_GRV,  KC_MINS, KC_EQL,  KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC, \
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_KP_7, KC_KP_8, KC_KP_9, KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSLS, \
  CTL_T(KC_ESC), KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_KP_4, KC_KP_5, KC_KP_6, KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, \
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_KP_1, KC_KP_2, KC_KP_3, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, RSFT_T(KC_ENT), \
        MO(MED), KC_LGUI, KC_LALT, MO(MED), MO(SYM), KC_SPC,  KC_KP_0, KC_PDOT, KC_PENT, KC_SPC,  MO(SYM), MO(MED), KC_RALT, KC_RGUI, MO(MED) \
 ),


 [OSX] = LAYOUT_ortho_5x15(
        KC_GESC, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_GRV,  KC_MINS, KC_EQL,  KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC, \
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_KP_7, KC_KP_8, KC_KP_9, KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSLS, \
  CTL_T(KC_ESC), KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_KP_4, KC_KP_5, KC_KP_6, KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, \
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_KP_1, KC_KP_2, KC_KP_3, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, RSFT_T(KC_ENT), \
        MO(MED), KC_LCTL, KC_LALT, KC_LGUI, MO(SYM), KC_SPC,  KC_KP_0, KC_PDOT, KC_PENT, KC_SPC,  MO(SYM), KC_RGUI, KC_RALT, KC_RCTL, MO(MED) \
 ),
/* SYMBOL
 * .--------------------------------------------------------------------------------------------------------------------------------------.
 * | `      | F1     | F2     | F3     | F4     | F5     | F6     | F7     | F8     | F9     | F10    | F11    | F12    |        | DEL    |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * |        |        |        |        |        |        | NP 7   | NP 8   | NP 9   |        |        |        |        |        | DEL    |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * |        |        |        |        |        |        | NP 4   | NP 5   | NP 6   | LEFT   | DOWN   | UP     | RIGHT  |        |        |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * |        |        |        |        |        |        | NP 1   | NP 2   | NP 3   |        |        | [      | ]      |        |        |
 * |--------+--------+--------+--------+--------+-----------------+--------+--------+--------+--------+--------+--------+--------+--------|
 * |        |        |        |        |        |        | NP 0   | DOT    | RETURN |        |        |        |        |        |        |
 * '--------------------------------------------------------------------------------------------------------------------------------------'
 */
 [SYM] = LAYOUT_ortho_5x15(
    KC_GRV,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______, KC_DEL,  \
    _______, _______, _______, _______, _______, _______, KC_P7,   KC_P8,   KC_P9,   _______, _______, _______, _______, _______, KC_DEL,  \
    _______, _______, _______, _______, _______, _______, KC_P4,   KC_P5,   KC_P6,   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______, _______, \
    _______, _______, _______, _______, _______, _______, KC_P1,   KC_P2,   KC_P3,   _______, _______, KC_LBRC, KC_RBRC, _______, _______, \
    _______, _______, _______, _______, _______, _______, KC_P0,   _______, KC_PDOT, _______, _______, _______, _______, _______, _______ \
 ),

/* MEDIA
 * .--------------------------------------------------------------------------------------------------------------------------------------.
 * |        |        |        |        |        |        |        |        |        |        |        |        |        |        | RESET  |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * |        |        |        |        |        |        |        |        |        |        |        |        |        |        |        |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * |        |        |        |        |        |        |        |        |        |        |        |        |        |        |        |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * |        |        |        |        |        |        |        |        |        |        |        |        |        |        |        |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * |        |        |        |        |        |        |        |        |        |        |        |        |        |        | TO(STN)|
 * '--------------------------------------------------------------------------------------------------------------------------------------'
 */
 [MED] = LAYOUT_ortho_5x15(
    _______, DF_QWE,  DF_OSX,  _______, _______, _______, _______, _______, KC_SCT1,    _______, _______, _______, _______, _______, RESET,   \
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, TO(STN) \
 ),

/* STENO
 * .--------------------------------------------------------------------------------------------------------------------------------------.
 * |        | STN_N1 | STN_N2 | STN_N3 | STN_N4 | STN_N5 |        |        | STN_N6 | STN_N7 | STN_N8 | STN_N9 | STN_NA | STN_NB |        |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * |        | STN_S1 | STN_TL | STN_PL | STN_HL | STN_ST1|        |        | STN_ST3| STN_FR | STN_PR | STN_LR | STN_TR | STN_DR |        |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * |        | STN_S2 | STN_KL | STN_WL | STN_RL | STN_ST2|        |        | STN_ST4| STN_RR | STN_BR | STN_GR | STN_SR | STN_ZR |        |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * |        |        |        |        |        |        |        |        |        |        |        |        |        |        |        |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * |        |        |        |        |        | STN_A  | STN_O  | STN_E  | STN_U  |        |        |        |        |        | TO(QWE)|
 * '--------------------------------------------------------------------------------------------------------------------------------------'
 */
[STN] = LAYOUT_ortho_5x15(
    XXXXXXX, STN_N1,  STN_N2,  STN_N3,  STN_N4,  STN_N5,  _______, XXXXXXX, STN_N6,  STN_N7,  STN_N8,  STN_N9,  STN_NA,  STN_NB,  _______, \
    XXXXXXX, STN_S1,  STN_TL,  STN_PL,  STN_HL,  STN_ST1, XXXXXXX, XXXXXXX, STN_ST3, STN_FR,  STN_PR,  STN_LR,  STN_TR,  STN_DR,  _______, \
    XXXXXXX, STN_S2,  STN_KL,  STN_WL,  STN_RL,  STN_ST2, XXXXXXX, XXXXXXX, STN_ST4, STN_RR,  STN_BR,  STN_GR,  STN_SR,  STN_ZR,  _______, \
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, _______, _______, \
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, STN_A,   STN_O,   STN_E,   STN_U,   XXXXXXX, XXXXXXX, XXXXXXX, _______, _______, TO(QWE) \
  ),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        switch (keycode) {
          // case VRSN:
          //     SEND_STRING(QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
          //     return false;
          case DF_QWE:
              set_single_persistent_default_layer(QWE);
              return false;
          case DF_OSX:
              set_single_persistent_default_layer(OSX);
              return false;
        }
    }

    return process_record_keymap(keycode, record) && process_record_secrets(keycode, record);
}

void matrix_init_user() {
  steno_set_mode(STENO_MODE_GEMINI); // or STENO_MODE_BOLT
}

// layer_state_t layer_state_set_user(layer_state_t state) {
//   #ifdef AUDIO_ENABLE
//     if (IS_LAYER_ON_STATE(state, QWE)) {
//       PLAY_SONG(QWERTY_SOUND);
//     }
//     if (IS_LAYER_ON_STATE(state, MAC)) {
//       PLAY_SONG(PLANCK_SOUND);
//     }
//   #endif
//   return state;
// }
