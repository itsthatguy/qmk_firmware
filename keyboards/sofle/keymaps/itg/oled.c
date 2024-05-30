 /* Copyright 2020 Josef Adamcik
  * Modification for VIA support and RGB underglow by Jens Bonk-Wiltfang
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

//Sets up what the OLED screens display.

#ifdef OLED_ENABLE

#define ANIM_INVERT false
#define ANIM_RENDER_WPM true
#define FAST_TYPE_WPM 45 //Switch to fast animation when over words per minute

#include "itg.h"
#include "animation/crab.c"

// #include "oled_driver.h"

// static void render_logo(void) {
//     static const char PROGMEM qmk_logo[] = {
//         0x80,0x81,0x82,0x83,0x84,0x85,0x86,0x87,0x88,0x89,0x8a,0x8b,0x8c,0x8d,0x8e,0x8f,0x90,0x91,0x92,0x93,0x94,
//         0xa0,0xa1,0xa2,0xa3,0xa4,0xa5,0xa6,0xa7,0xa8,0xa9,0xaa,0xab,0xac,0xad,0xae,0xaf,0xb0,0xb1,0xb2,0xb3,0xb4,
//         0xc0,0xc1,0xc2,0xc3,0xc4,0xc5,0xc6,0xc7,0xc8,0xc9,0xca,0xcb,0xcc,0xcd,0xce,0xcf,0xd0,0xd1,0xd2,0xd3,0xd4,0
//     };

//     oled_write_P(qmk_logo, false);
// }

// static void render_logo(void) {
//     static const char PROGMEM qmk_logo[] = {
//         0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8A, 0x8B, 0x8C, 0x8D, 0x8E, 0x8F, 0x90, 0x91, 0x92, 0x93, 0x94,
//         0xA0, 0xA1, 0xA2, 0xA3, 0xA4, 0xA5, 0xA6, 0xA7, 0xA8, 0xA9, 0xAA, 0xAB, 0xAC, 0xAD, 0xAE, 0xAF, 0xB0, 0xB1, 0xB2, 0xB3, 0xB4,
//         0xC0, 0xC1, 0xC2, 0xC3, 0xC4, 0xC5, 0xC6, 0xC7, 0xC8, 0xC9, 0xCA, 0xCB, 0xCC, 0xCD, 0xCE, 0xCF, 0xD0, 0xD1, 0xD2, 0xD3, 0xD4, 0x00
//     };

//     oled_write_P(qmk_logo, false);
// }




// Function to get the current layer name
const char* get_layer_name(uint8_t layer) {
    switch (layer) {
        case _QWERTY:
        case _GAME:
        case _OSX:
            return "";
            break;
        case _RAISE:
            static char const layer_name_raise[] PROGMEM = {0x81, 0};
            return layer_name_raise;
        case _LOWER:
            static char const layer_name_lower[] PROGMEM = {0x82, 0};
            return layer_name_lower;
        case _ADJUST:
            static char const layer_name_adjust[] PROGMEM = {0x83, 0};
            return layer_name_adjust;
        default:
            return "Undefined";
    }
}

// // Function to get icons based on the layer
// const char* get_icon(uint8_t row, const char icons[2][3]) {
//     if (row < 2) {
//         return icons[row];
//     }
//     return NULL;
// }
//     const char* icon = NULL;
//     switch (layer) {
//         case _QWERTY:
//             icon = (const char*)win_icon;
//             break;
//         case _OSX:
//             icon = (const char*)osx_icon;
//             break;
//         case _GAME:
//             icon = (const char*)nix_icon;
//             break;
//         default:
//             return NULL;
//     }

//     write_icon_to_oled((const char*)icon, 0, 0, 2, 2);
// }
static const char osx_icon[2][2] PROGMEM = {{0x95, 0x96},
                                          {0xb5, 0xb6}};

static const char win_icon[2][2] PROGMEM = {{0x97, 0x98},
                                          {0xb7, 0xb8}};

static const char nix_icon[2][2] PROGMEM = {{0x99, 0x9a},
                                          {0xb7, 0xb8}};

// Helper function to write icons to OLED
void write_icon_to_oled(const char* icon, uint8_t x, uint8_t y, uint8_t w, uint8_t h) {

    for (uint8_t row = 0; row < h; row++) {
        for (uint8_t col = 0; col < w; col++) {
            oled_set_cursor(x + col, y + row);
            oled_write_char(icon[row * w + col], false);
        }
    }
}

// Function to get the default layer icons
const void render_default_layer_icon(void) {
    const char* icon = "";

    switch (get_highest_layer(default_layer_state)) {
        case _QWERTY:
            icon = (const char*)win_icon;
            break;
        case _OSX:
            icon = (const char*)osx_icon;
            break;
        case _GAME:
            icon = (const char*)nix_icon;
            break;
    }

    write_icon_to_oled(icon, 0, 0, 2, 2);
}


// // Function to get the tri-layer icons
const void render_tri_layer_icon(void) {
    oled_set_cursor(4, 0);

    switch (get_highest_layer(layer_state)) {
        case TRI_LAYER_LOWER_LAYER:
            oled_write_char(0x19, false);
            break;
        case TRI_LAYER_UPPER_LAYER:
            oled_write_char(0x18, false);
            break;
        case TRI_LAYER_ADJUST_LAYER:
            oled_write_char(0x17, false);
            break; 
        default:
            oled_write_char(0x20, false);
            break;
    }
}

const void render_wpm(void) {
    oled_set_cursor(0, 2);
    oled_write_P(PSTR("WPM: "), false);
    oled_write(get_u8_str(get_current_wpm(), '0'), false);
}

// Function to render the status on the OLED
static void render_status(void) {
    // Write the icons to the OLED
    render_default_layer_icon();
    render_tri_layer_icon();
    render_wpm();
}

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    oled_set_brightness(OLED_DISPLAY_ADDRESS);
    if (is_keyboard_left()) {
        return OLED_ROTATION_270;
    } else {
        return rotation;
    }
}

bool oled_task_user(void) {
    if (is_keyboard_left()) {
        render_status();
    } else {
        oled_render_anim();
    }

    return false;
}

#endif
