![SofleKeyboard default keymap](https://i.imgur.com/MZxVvm9.png)
![SofleKeyboard adjust layer](https://i.imgur.com/f5sKy0I.png)

# Default keymap for Sofle Keyboard

Layout in [Keyboard Layout Editor](http://www.keyboard-layout-editor.com/#/gists/76efb423a46cbbea75465cb468eef7ff) and [adjust layer](http://www.keyboard-layout-editor.com/#/gists/4bcf66f922cfd54da20ba04905d56bd4)

Features:

- Symmetric modifiers (CMD/Super, Alt/Opt, Ctrl, Shift)
- Various modes, can be switched (using Adjust layer and the selected one is stored in EEPROM.
- Modes for Qwerty and Colemak support
- Modes for Mac vs Linux/Win support -> different order of modifiers and different action shortcuts on the "UPPER" layer (the red one in the image). Designed to simplify transtions when switching between operating systems often.
- The OLED on master half shows selected mode and caps lock state and is rotated.
- Left encoder controls volume up/down/mute. Right encoder PGUP/PGDOWN.

## Files:

- users/itg/
  - [config.h](/users/itg/config.h)
  - [itg.c](/users/itg/itg.c)
  - [itg.h](/users/itg/itg.h)
  - [rules.mk](/users/itg/rules.mk)
- keyboards/sofle/itg/
  - [config.h](/keyboards/sofle/itg/config.h)
  - [info.json](/keyboards/sofle/itg/info.json)
  - [rules.mk](/keyboards/sofle/itg/rules.mk)
- keyboards/sofle/keymaps/itg/
  - [config.h](config.h)
  - [keymap.c](keymap.c)
  - [oled.c](oled.c)
  - [rules.mk](rules.mk)
