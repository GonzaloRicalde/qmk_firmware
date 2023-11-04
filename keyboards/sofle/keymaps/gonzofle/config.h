#pragma once

/* The way how "handedness" is decided (which half is which),
see https://docs.qmk.fm/#/feature_split_keyboard?id=setting-handedness
for more options.
*/

#define TAPPING_TERM_PER_KEY
#define HOLD_ON_OTHER_KEY_PRESS_PER_KEY // used to allow the space/shift key to prefer space over shift to prevent accidental caps when writing normally

#define BOTH_SHIFTS_TURNS_ON_CAPS_WORD

//this is so the secondary screen logo updates when game mode is on, it's a bit easier to see
#define SPLIT_LED_STATE_ENABLE
#define SPLIT_LAYER_STATE_ENABLE
