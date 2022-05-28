 /* moved over from dofle default keymap
  * Copyright 2020 Josef Adamcik
  */

//Setting up what encoder rotation does. If your encoder can be pressed as a button, that function can be set in Via.

#ifdef ENCODER_ENABLE


//there's probably a correct way of detecting the steps on the encoder but for now i just have this flip flop hack
static bool flipFlop = false;

bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) {
        flipFlop=!flipFlop;
        if(flipFlop)
        {
            if (clockwise) {
                tap_code(KC_MPRV);
            } else {
                tap_code(KC_MNXT);
            }
        }
    } else if (index == 1) {
        //second encoder is reversed, is it because this is a split keyboard?
        if (!clockwise) {
            tap_code16(RALT(KC_TAB));
        } else {
            tap_code16(RALT(S(KC_TAB)));
        }
    }
    return true;
}

#endif
