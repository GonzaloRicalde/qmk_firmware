 /* moved over from dofle default keymap
  * Copyright 2020 Josef Adamcik
  */

//Setting up what encoder rotation does. If your encoder can be pressed as a button, that function can be set in Via.

#ifdef ENCODER_ENABLE

bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) {
        if (clockwise) {
            tap_code(KC_MPRV);
        } else {
            tap_code(KC_MNXT);
        }
    } else if (index == 1) {
        if (!clockwise) {
            tap_code16(C(KC_Z));
        } else {
            tap_code16(C(KC_Y));
        }
    }
    return false;
}

#endif
