#include "action_util.h"
#include "keycodes.h"
#include QMK_KEYBOARD_H
#include "declare.h"
#include "quantum.h"
#include "encoder.c"
#include "oled.c"

#define PIPE S(KC_NUBS)
#define G_LSFT LSFT_T(KC_LPRN)
#define G_RSFT RSFT_T(KC_RPRN)
#define G_LALT LALT_T(KC_LBRC)
#define G_RALT RALT_T(KC_RBRC)
#define G_CENT LCTL_T(KC_ENT)
#define G_ASPC ALT_T(KC_SPC)
#define G_RCTL LCTL_T(KC_APP)
#define G_BESC LT(0, KC_BSPC)

#define G_LOWER LT(_LOWER, KC_LCBR)
#define G_RAISE LT(_RAISE, KC_RCBR)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/*
 * QWERTY
 */
[_QWERTY] = LAYOUT(
  KC_GRV,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                               KC_6,    KC_7,    KC_8,    KC_9,    KC_0, KC_MINS,
  KC_ESC,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                               KC_Y,    KC_U,    KC_I,    KC_O,    KC_P, KC_BSPC,
  KC_TAB,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                               KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN, KC_QUOT,
  G_LSFT,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B, KC_MPLY,         KC_GUITB,    KC_N,    KC_M, KC_COMM, KC_DOT , KC_SLSH,  G_RSFT,
                     KC_GAME, KC_LCTL, G_LALT, G_LOWER, G_CENT,          G_ASPC, G_RAISE, G_RALT, G_RCTL, KC_RGUI
),

/*
 * GAME
 */
[_GAME] = LAYOUT(
  KC_GRV,   KC_1,   KC_2,    KC_3,    KC_4,    KC_5,                             KC_6,    KC_7,    KC_8,    KC_9,    KC_0,  KC_MINS,
  KC_ESC,   KC_Q,   KC_W,    KC_E,    KC_R,    KC_T,                             KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,  KC_BSPC,
  KC_TAB,   KC_A,   KC_S,    KC_D,    KC_F,    KC_G,                             KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN,  KC_QUOT,
  KC_LSFT,  KC_Z,   KC_X,    KC_C,    KC_V,    KC_B, KC_MPLY,           KC_GUITB,KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH,  KC_RSFT,
                 KC_GAME,KC_LALT,KC_LCTL, KC_SPC, G_CENT,                   KC_SPC,  KC_RAISE, KC_RCTL, KC_RALT, KC_RGUI
),

/*
 *LOWER
 */
[_LOWER] = LAYOUT(
  _______,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                           KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_F11,
  KC_GRV,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                            KC_6,    KC_7,    KC_8,    KC_9,    KC_0,  KC_F12,
  KC_GNZALTAB , KC_EXLM,   KC_AT, KC_HASH,  KC_DLR, KC_PERC,                      PIPE , KC_AMPR, KC_ASTR, KC_SLSH, KC_CIRC, KC_BSLS,
  _______,  KC_CIRC, KC_MINS, KC_PLUS, KC_LCBR, KC_RCBR, _______,         _______, KC_PLUS, KC_MINS, KC_UNDS, KC_EQL, KC_NUBS, _______,
                       _______, _______, _______, _______, G_CENT,       _______, _______, _______, _______, _______
),

/*
 * RAISE
 */
[_RAISE] = LAYOUT(
  _______, _______ , _______ , _______ , _______ , _______,                           _______,  _______ , _______,  _______,  _______, KC_GAME,
  _______, KC_BTN4 , KC_MS_U , KC_BTN5 , KC_WH_U , KC_INS ,                           KC_PGUP , KC_PRVWD,  KC_UP , KC_NXTWD, KC_DLINE, KC_BSPC,
  _______, KC_MS_L , KC_MS_D , KC_MS_R , KC_WH_D , KC_CAPS,                           KC_PGDN , KC_LEFT , KC_DOWN, KC_RGHT , KC_DEL  , KC_BSPC,
  _______, KC_UNDO , KC_CUT , KC_COPY , KC_PASTE , KC_BTN3,  _______,       _______,  KC_BTN1 , KC_LSTRT, XXXXXXX, KC_LEND , G_RCTL, _______,
                         _______, _______, KC_BTN2, _______, KC_BTN1,       _______, _______, _______, _______, _______
),

/*
 * ADJUST
 */
  [_ADJUST] = LAYOUT(
  XXXXXXX , XXXXXXX,  XXXXXXX ,  XXXXXXX , XXXXXXX, XXXXXXX,                     CG_TOGG, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  QK_REBOOT , XXXXXXX, XXXXXXX, XXXXXXX ,XXXXXXX,XXXXXXX,                          XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX , XXXXXXX,XXXXXXX, XXXXXXX,    XXXXXXX,  XXXXXXX,                      XXXXXXX, KC_VOLD, KC_MUTE, KC_VOLU, XXXXXXX, XXXXXXX,
  XXXXXXX , XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX,  XXXXXXX, XXXXXXX,     XXXXXXX, XXXXXXX, KC_MPRV, KC_MPLY, KC_MNXT, XXXXXXX, XXXXXXX,
                   _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______
  )
};

static bool isGnzaltabEnabled = false;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {

    //intercept any key different than the gnzaltab keys to disable the alt mod
    //
    if(isGnzaltabEnabled==true){
        switch(keycode){
            case KC_GNZALTAB:
            case KC_LSFT:
            case KC_RSFT:
            case KC_TAB:
            case KC_LALT:
            case KC_RALT:
            break;
            default:
                if(get_mods() & MOD_MASK_ALT){
                    unregister_mods(MOD_BIT(KC_LALT));
                }
                isGnzaltabEnabled=false;
            break;
        }
    }


    switch (keycode) {
        case KC_QWERTY:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_QWERTY);
            }
            return false;
        case KC_GAME:
            if (record->event.pressed)
            {
                switch (get_highest_layer(default_layer_state))
                {
                    case _QWERTY:
                        set_single_persistent_default_layer(_GAME);
                        break;
                    case _GAME:
                        set_single_persistent_default_layer(_QWERTY);
                        break;
                    default:
                        set_single_persistent_default_layer(_QWERTY);
                        break;
                }
            }
            return false;
        case KC_LOWER:
            if (record->event.pressed) {
                layer_on(_LOWER);
                update_tri_layer(_LOWER, _RAISE, _ADJUST);
            } else {
                layer_off(_LOWER);
                update_tri_layer(_LOWER, _RAISE, _ADJUST);
            }
            return false;
        case KC_RAISE:
            if (record->event.pressed) {
                layer_on(_RAISE);
                update_tri_layer(_LOWER, _RAISE, _ADJUST);
            } else {
                layer_off(_RAISE);
                update_tri_layer(_LOWER, _RAISE, _ADJUST);
            }
            return false;
        case KC_ADJUST:
            if (record->event.pressed) {
                layer_on(_ADJUST);
            } else {
                layer_off(_ADJUST);
            }
            return false;
        case KC_PRVWD:
            if (record->event.pressed) {
                if (keymap_config.swap_lctl_lgui) {
                    register_mods(MOD_BIT(KC_LALT));
                    register_code(KC_LEFT);
                } else {
                    register_mods(MOD_BIT(KC_LCTL));
                    register_code(KC_LEFT);
                }
            } else {
                if (keymap_config.swap_lctl_lgui) {
                    unregister_mods(MOD_BIT(KC_LALT));
                    unregister_code(KC_LEFT);
                } else {
                    unregister_mods(MOD_BIT(KC_LCTL));
                    unregister_code(KC_LEFT);
                }
            }
            break;
        case KC_NXTWD:
             if (record->event.pressed) {
                if (keymap_config.swap_lctl_lgui) {
                    register_mods(MOD_BIT(KC_LALT));
                    register_code(KC_RIGHT);
                } else {
                    register_mods(MOD_BIT(KC_LCTL));
                    register_code(KC_RIGHT);
                }
            } else {
                if (keymap_config.swap_lctl_lgui) {
                    unregister_mods(MOD_BIT(KC_LALT));
                    unregister_code(KC_RIGHT);
                } else {
                    unregister_mods(MOD_BIT(KC_LCTL));
                    unregister_code(KC_RIGHT);
                }
            }
            break;
        case KC_LSTRT:
            if (record->event.pressed) {
                if (keymap_config.swap_lctl_lgui) {
                     //CMD-arrow on Mac, but we have CTL and GUI swapped
                    register_mods(MOD_BIT(KC_LCTL));
                    register_code(KC_LEFT);
                } else {
                    register_code(KC_HOME);
                }
            } else {
                if (keymap_config.swap_lctl_lgui) {
                    unregister_mods(MOD_BIT(KC_LCTL));
                    unregister_code(KC_LEFT);
                } else {
                    unregister_code(KC_HOME);
                }
            }
            break;
        case KC_LEND:
            if (record->event.pressed) {
                if (keymap_config.swap_lctl_lgui) {
                    //CMD-arrow on Mac, but we have CTL and GUI swapped
                    register_mods(MOD_BIT(KC_LCTL));
                    register_code(KC_RIGHT);
                } else {
                    register_code(KC_END);
                }
            } else {
                if (keymap_config.swap_lctl_lgui) {
                    unregister_mods(MOD_BIT(KC_LCTL));
                    unregister_code(KC_RIGHT);
                } else {
                    unregister_code(KC_END);
                }
            }
            break;
        case KC_DLINE:
            if (record->event.pressed) {
                register_mods(MOD_BIT(KC_LCTL));
                register_code(KC_BSPC);
            } else {
                unregister_mods(MOD_BIT(KC_LCTL));
                unregister_code(KC_BSPC);
            }
            break;
        case KC_COPY:
            if (record->event.pressed) {
                register_mods(MOD_BIT(KC_LCTL));
                register_code(KC_C);
            } else {
                unregister_mods(MOD_BIT(KC_LCTL));
                unregister_code(KC_C);
            }
            return false;
        case KC_PASTE:
            if (record->event.pressed) {
                register_mods(MOD_BIT(KC_LCTL));
                register_code(KC_V);
            } else {
                unregister_mods(MOD_BIT(KC_LCTL));
                unregister_code(KC_V);
            }
            return false;
        case KC_CUT:
            if (record->event.pressed) {
                register_mods(MOD_BIT(KC_LCTL));
                register_code(KC_X);
            } else {
                unregister_mods(MOD_BIT(KC_LCTL));
                unregister_code(KC_X);
            }
            return false;
            break;
        case KC_UNDO:
            if (record->event.pressed) {
                register_mods(MOD_BIT(KC_LCTL));
                register_code(KC_Z);
            } else {
                unregister_mods(MOD_BIT(KC_LCTL));
                unregister_code(KC_Z);
            }
            return false;
            break;
        case KC_GUITB:
            if(record->event.pressed){
                register_mods(MOD_BIT(KC_LGUI));
                register_code(KC_TAB);
            } else {
                unregister_mods(mod_config((MOD_LGUI)));
                unregister_code(KC_TAB);
            }
            return false;

        case KC_GNZALTAB:
            if (record->event.pressed){
                if(!isGnzaltabEnabled){
                    isGnzaltabEnabled=true;
                    register_mods(MOD_BIT(KC_LALT));
                }
                tap_code(KC_TAB);
            }
            break;

        case G_LOWER:
            if (record->tap.count && record->event.pressed) {
                tap_code16(KC_LCBR);
                return false;
            }
            break;

        case G_RAISE:
            if (record->tap.count && record->event.pressed) {
                tap_code16(KC_RCBR);
                return false;
            }
            break;

        case G_LSFT:
            if (record->tap.count && record->event.pressed) {
                tap_code16(KC_LPRN);
                return false;
            }
            break;

        case G_RSFT:
            if (record->tap.count && record->event.pressed) {
                tap_code16(KC_RPRN);
                return false;
            }
            break;

        case G_LALT:
            if (record->tap.count && record->event.pressed) {
                tap_code16(KC_LBRC);
                return false;
            }
            break;

        case G_RALT:
            if (record->tap.count && record->event.pressed) {
                tap_code16(KC_RBRC);
                return false;
            }
            break;
        case G_BESC:
            if (record->tap.count && record->event.pressed) {
                tap_code16(KC_BSPC); //tap
            } else if ( record->event.pressed){
                tap_code16(KC_ESC); // hold
            }
            return false;
            break;
        case G_ASPC:
            if (record->tap.count && record->event.pressed) {
                if((get_mods() & MOD_MASK_SHIFT) || is_caps_word_on()){
                    tap_code16(KC_UNDS);
                }else {
                    tap_code16(KC_SPC);
                }
                return false;
            }
            break;
    }
    return true;
}

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case G_CENT:
        case G_ASPC:
            return TAPPING_TERM + 100;
        default:
            return TAPPING_TERM;
    }
}

bool get_hold_on_other_key_press(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case SFT_T(KC_SPC):
            // Do not select the hold action when another key is pressed.
            return false;
        default:
            // Immediately select the hold action when another key is pressed.
            return true;
    }
}

#undef PIPE
