#include "itg.h"
#include "version.h"
#include "process_records.h"

__attribute__((weak)) bool process_record_keymap(uint16_t keycode, keyrecord_t *record) { return true; }
__attribute__((weak)) bool process_record_secrets(uint16_t keycode, keyrecord_t *record) { return true; }
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
    switch (keycode) {
      case VRSN:
        SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
        return false;
      case LK_QWRT:
        set_single_persistent_default_layer(_QWERTY);
        return false;
      case LK_GAME:
        set_single_persistent_default_layer(_GAME);
        return false;
      case LK_OSX:
        set_single_persistent_default_layer(_OSX);
        return false;
      case SCREENSHOT:
        tap_code16(C(S(G(KC_4))));
        return false;
    }
  }
  return process_record_keymap(keycode, record) && process_record_secrets(keycode, record);
}
