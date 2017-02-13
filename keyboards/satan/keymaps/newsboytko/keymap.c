#include "satan.h"

// Readability
#define _______ KC_TRNS
#define XXXXXXX KC_NO

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
enum layer_id
{
    _DL_WINDOWS,
    _DL_MAC,
    _DL_KIDS,
    _DL_MAX,
    _FL = _DL_MAX,
    _RL,
    _GL_MAC,
    _GL_MAC_GUITAB,
};

enum function_id {
    SHIFT_ESC,
    NEXT_DEFAULT_LAYER,
    MAC_GUITAB_ENABLE,
    MAC_GUITAB_DISABLE,
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  /* Keymap _DL_WINDOWS: Default Layer for Windows
   * ,------------------------------------------------------------------------.
   * |Esc~|   1|   2|   3|   4|   5|   6|   7|   8|   9|   0|   -|   =|Backspc|
   * |------------------------------------------------------------------------|
   * |Tab   |   Q|   W|   E|   R|   T|   Y|   U|   I|   O|   P|   [|   ]|  \  |
   * |------------------------------------------------------------------------|
   * | FN    |   A|   S|   D|   F|   G|   H|   J|   K|   L|   ;|   '|  Return |
   * |------------------------------------------------------------------------|
   * |Shift    |   Z|   X|   C|   V|   B|   N|   M|   ,|   .|   /|      Shift |
   * |------------------------------------------------------------------------|
   * |Ctrl | Gui | Alt |            Space             | Alt | RL  | FN  | Ctrl|
   * `------------------------------------------------------------------------'
   *
   * Foot switches:
   *                ,--------.         ,--------.
   *                |        |         |        |
   *                |   FN   |         | Shift  |
   *                `--------'         `--------'
   */
[_DL_WINDOWS] = KEYMAP_ANSI_FOOTSWITCHES(
  F(SHIFT_ESC),    KC_1,    KC_2,    KC_3,   KC_4,    KC_5,    KC_6,    KC_7,     KC_8,    KC_9,   KC_0,    KC_MINS, KC_EQL,  KC_BSPC, \
  KC_TAB,  KC_Q,    KC_W,    KC_E,   KC_R,    KC_T,    KC_Y,    KC_U,     KC_I,    KC_O,   KC_P,    KC_LBRC, KC_RBRC, KC_BSLS, \
  MO(_FL), KC_A,    KC_S,    KC_D,   KC_F,    KC_G,    KC_H,    KC_J,     KC_K,    KC_L,   KC_SCLN, KC_QUOT,          KC_ENT,  \
  KC_LSFT, KC_Z,    KC_X,    KC_C,   KC_V,    KC_B,    KC_N,    KC_M,     KC_COMM, KC_DOT, KC_SLSH,                   KC_RSFT, \
  KC_LCTL, KC_LGUI, KC_LALT,                           KC_SPC,                             KC_RALT, MO(_RL), MO(_FL), KC_RCTL, \
  MO(_FL), KC_LSFT),

  /* Keymap _DL_MAC: Default Layer for Mac
   * ,------------------------------------------------------------------------.
   * |Esc~|   1|   2|   3|   4|   5|   6|   7|   8|   9|   0|   -|   =|Backspc|
   * |------------------------------------------------------------------------|
   * |Tab   |   Q|   W|   E|   R|   T|   Y|   U|   I|   O|   P|   [|   ]|  \  |
   * |------------------------------------------------------------------------|
   * | FN    |   A|   S|   D|   F|   G|   H|   J|   K|   L|   ;|   '|  Return |
   * |------------------------------------------------------------------------|
   * |Shift    |   Z|   X|   C|   V|   B|   N|   M|   ,|   .|   /|      Shift |
   * |------------------------------------------------------------------------|
   * |Ctrl | Alt | Gui |            Space             | GL  | RL  | FN  | Ctrl|
   * `------------------------------------------------------------------------'
   *
   * Foot switches:
   *                ,--------.         ,--------.
   *                |        |         |        |
   *                |   FN   |         | Shift  |
   *                `--------'         `--------'
   */
[_DL_MAC] = KEYMAP_ANSI_FOOTSWITCHES(
  F(SHIFT_ESC),    KC_1,    KC_2,    KC_3,   KC_4,    KC_5,    KC_6,    KC_7,     KC_8,    KC_9,   KC_0,    KC_MINS, KC_EQL,  KC_BSPC, \
  KC_TAB,  KC_Q,    KC_W,    KC_E,   KC_R,    KC_T,    KC_Y,    KC_U,     KC_I,    KC_O,   KC_P,    KC_LBRC, KC_RBRC, KC_BSLS, \
  MO(_FL), KC_A,    KC_S,    KC_D,   KC_F,    KC_G,    KC_H,    KC_J,     KC_K,    KC_L,   KC_SCLN, KC_QUOT,          KC_ENT,  \
  KC_LSFT, KC_Z,    KC_X,    KC_C,   KC_V,    KC_B,    KC_N,    KC_M,     KC_COMM, KC_DOT, KC_SLSH,                   KC_RSFT, \
  KC_LCTL, KC_LALT, KC_LGUI,                           KC_SPC,                             MO(_GL_MAC), MO(_RL), MO(_FL), KC_RCTL, \
  MO(_FL), KC_LSFT),

  /* Keymap _DL_KIDS: Default layer for child's play
   * ,------------------------------------------------------------------------.
   * |`   |   1|   2|   3|   4|   5|   6|   7|   8|   9|   0|   -|   =|Backspc|
   * |------------------------------------------------------------------------|
   * |Tab   |   Q|   W|   E|   R|   T|   Y|   U|   I|   O|   P|   [|   ]|  \  |
   * |------------------------------------------------------------------------|
   * | CAPS  |   A|   S|   D|   F|   G|   H|   J|   K|   L|   ;|   '|  Return |
   * |------------------------------------------------------------------------|
   * |Shift    |   Z|   X|   C|   V|   B|   N|   M|   ,|   .|   /|      Shift |
   * |------------------------------------------------------------------------|
   * |     |     |     |            Space             |     | RL  |     |     |
   * `------------------------------------------------------------------------'
   *
   * Foot switches:
   *                ,--------.         ,--------.
   *                |        |         |        |
   *                |   FN   |         | Shift  |
   *                `--------'         `--------'
   */
[_DL_KIDS] = KEYMAP_ANSI_FOOTSWITCHES(
  KC_GRV,  KC_1,    KC_2,    KC_3,   KC_4,    KC_5,    KC_6,    KC_7,     KC_8,    KC_9,   KC_0,    KC_MINS, KC_EQL,  KC_BSPC, \
  KC_TAB,  KC_Q,    KC_W,    KC_E,   KC_R,    KC_T,    KC_Y,    KC_U,     KC_I,    KC_O,   KC_P,    KC_LBRC, KC_RBRC, KC_BSLS, \
  KC_CAPS, KC_A,    KC_S,    KC_D,   KC_F,    KC_G,    KC_H,    KC_J,     KC_K,    KC_L,   KC_SCLN, KC_QUOT,          KC_ENT,  \
  KC_LSFT, KC_Z,    KC_X,    KC_C,   KC_V,    KC_B,    KC_N,    KC_M,     KC_COMM, KC_DOT, KC_SLSH,                   KC_RSFT, \
  KC_NO, KC_NO, KC_NO,                           KC_SPC,                             KC_NO, MO(_RL), KC_NO, KC_NO, \
  MO(_FL), KC_LSFT),

/* Keymap _FL: Function Layer
   * ,------------------------------------------------------------------------.
   * |`   |  F1|  F2|  F3|  F4|  F5|  F6|  F7|  F8|  F9| F10| F11| F12|  Del  |
   * |------------------------------------------------------------------------|
   * |      |Home|  Up| End|PgUp|    |PgUp|Home|  Up| End|    |PrSc|ScLk|Pause|
   * |------------------------------------------------------------------------|
   * |       |Left|Down|Rght|PgDn|    |PgDn|Left|Down|Rght|    | Ins|         |
   * |------------------------------------------------------------------------|
   * |         |    |    |    |    |Mute|Vol-|Vol+|Skp-|Skp+|Stop|            |
   * |------------------------------------------------------------------------|
   * |     |     |     |          Play/Pause          |     |     |     |     |
   * `------------------------------------------------------------------------'
   *
   * Foot switches:
   *                ,--------.         ,--------.
   *                |        |         |        |
   *                |        |         |        |
   *                `--------'         `--------'
   */
[_FL] = KEYMAP_ANSI_FOOTSWITCHES(
  KC_GRV,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_DEL,  \
  _______, KC_HOME, KC_UP,   KC_END,  KC_PGUP, _______, KC_PGUP, KC_HOME, KC_UP,   KC_END,  _______, KC_PSCR, KC_SLCK, KC_PAUS, \
  _______, KC_LEFT, KC_DOWN, KC_RGHT, KC_PGDN, _______, KC_PGDN, KC_LEFT, KC_DOWN, KC_RGHT, _______, KC_INS,          _______, \
  _______, _______, _______, _______, _______, KC_MUTE, KC_VOLD, KC_VOLU, KC_MPRV, KC_MNXT, KC_MSTP,                  _______, \
  _______, _______, _______,                            KC_MPLY,                            _______, _______, _______, _______, \
  _______, _______),
  
/* Keymap _RL: Extended Function Layer
   * ,------------------------------------------------------------------------.
   * |    |    |    |    |    |    |    |    |    |    |    |    |    | RESET |
   * |------------------------------------------------------------------------|
   * |      |    |    |    |    |    |    |    |    |    |    | BL-| BL+|  BL |
   * |------------------------------------------------------------------------|
   * |       |    |    |    |    |    |    |    |    |    |    |    |         |
   * |------------------------------------------------------------------------|
   * |         |RGB |Mode|Hue+|Hue-|Sat+|Sat-|Val+|Val-|    |    |            |
   * |------------------------------------------------------------------------|
   * |     | DL+ |     |                              |     |     |     |     |
   * `------------------------------------------------------------------------'
   *
   * Foot switches:
   *                ,--------.         ,--------.
   *                |        |         |        |
   *                |        |         |        |
   *                `--------'         `--------'
   */
[_RL] = KEYMAP_ANSI_FOOTSWITCHES(
  #ifdef RGBLIGHT_ENABLE
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, RESET,   \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, BL_DEC,  BL_INC,  BL_TOGG, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, \
  _______, RGB_TOG, RGB_MOD, RGB_HUI, RGB_HUD, RGB_SAI, RGB_SAD, RGB_VAI, RGB_VAD, _______, _______,                   _______, \
  _______, F(NEXT_DEFAULT_LAYER), _______,                _______,                          _______, _______, _______, _______, \
  _______, _______
  #else
  _______,  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, RESET,   \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, BL_DEC,  BL_INC,  BL_TOGG, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,                   _______, \
  _______, F(NEXT_DEFAULT_LAYER), _______,                _______,                          _______, _______, _______, _______, \
  _______, _______
  #endif
  ),

/* Keymap _GL_MAC: GUI Layer for Mac
   * ,------------------------------------------------------------------------.
   * |Pwr |    |    |    |    |    |    |    |    |    |    |    |    | Close |
   * |------------------------------------------------------------------------|
   * |      |    |    |    |    |    |    |    |    |    |    |Dsk-|Dsk+| GTab|
   * |------------------------------------------------------------------------|
   * |       |    |    |    |    |    |    |    |    |    |SnpL|SnpR| Maximize|
   * |------------------------------------------------------------------------|
   * |         |    |    |    |    |    |    |    |    |    |    |            |
   * |------------------------------------------------------------------------|
   * |     |     |     |                              |     |     |     |     |
   * `------------------------------------------------------------------------'
   *
   * Foot switches:
   *                ,--------.         ,--------.
   *                |        |         |        |
   *                |        |         |        |
   *                `--------'         `--------'
   */
[_GL_MAC] = KEYMAP_ANSI_FOOTSWITCHES(
  KC_PWR,  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, LGUI(KC_W), \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, LCTL(KC_LEFT), LCTL(KC_RGHT), F(MAC_GUITAB_ENABLE), \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, LCAG(KC_LEFT), LCAG(KC_RGHT), LCAG(KC_M), \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,                   _______, \
  _______, _______, _______,                          _______,                              _______, _______, _______, _______, \
  _______, _______), 

/* Keymap _GL_MAC_GUITAB: GUI Layer for Mac "Gui-Tab" functionality
   * ,------------------------------------------------------------------------.
   * |    |    |    |    |    |    |    |    |    |    |    |    |    |       |
   * |------------------------------------------------------------------------|
   * |      |    |    |    |    |    |    |    |    |    |    |    |    |     |
   * |------------------------------------------------------------------------|
   * |       |    |    |    |    |    |    |    |    |    |    |    |         |
   * |------------------------------------------------------------------------|
   * |         |    |    |    |    |    |    |    |    |    |    |            |
   * |------------------------------------------------------------------------|
   * |     |     |     |                              |     |     |     |     |
   * `------------------------------------------------------------------------'
   *
   * Foot switches:
   *                ,--------.         ,--------.
   *                |        |         |        |
   *                |        |         |        |
   *                `--------'         `--------'
   */
[_GL_MAC_GUITAB] = KEYMAP_ANSI_FOOTSWITCHES(
  KC_ESC, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, LSFT(KC_TAB), KC_TAB, F(MAC_GUITAB_DISABLE), \
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_TAB, LSFT(KC_TAB), XXXXXXX, XXXXXXX, XXXXXXX,          F(MAC_GUITAB_DISABLE), \
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, \
  XXXXXXX, XXXXXXX, XXXXXXX,                          F(MAC_GUITAB_DISABLE),                XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
  XXXXXXX, XXXXXXX),

#if 0
Template:

[] = KEYMAP_ANSI_FOOTSWITCHES(
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,                   _______, \
  _______, _______, _______,                          _______,                              _______, _______, _______, _______, \
  _______, _______),
#endif

};


const uint16_t PROGMEM fn_actions[] = {
  [SHIFT_ESC] = ACTION_FUNCTION(SHIFT_ESC),
  [NEXT_DEFAULT_LAYER] = ACTION_FUNCTION(NEXT_DEFAULT_LAYER),
  [MAC_GUITAB_ENABLE] = ACTION_FUNCTION(MAC_GUITAB_ENABLE),
  [MAC_GUITAB_DISABLE] = ACTION_FUNCTION(MAC_GUITAB_DISABLE),
};

// Used for SHIFT_ESC
#define MODS_SHIFT_MASK  (MOD_BIT(KC_LSHIFT)|MOD_BIT(KC_RSHIFT))

// used for NEXT_DEFAULT_LAYER
extern uint32_t default_layer_state;
#define MAX_DEFAULT_LAYER_STATE (1UL << _DL_MAX)

void persistent_default_layer_set(uint16_t default_layer)
{
    eeconfig_update_default_layer(default_layer);
    default_layer_set(default_layer);
}

void action_function(keyrecord_t *record, uint8_t id, uint8_t opt) {
    uint8_t shift_pressed;
    shift_pressed = get_mods() & MODS_SHIFT_MASK;
    switch (id) {
        case SHIFT_ESC:
        {
            if (record->event.pressed) {
                if (shift_pressed) {
                    add_key(KC_GRV);
                    send_keyboard_report();
                } else {
                    add_key(KC_ESC);
                    send_keyboard_report();
                }
            } else {
                if (shift_pressed) {
                    del_key(KC_GRV);
                    send_keyboard_report();
                } else {
                    del_key(KC_ESC);
                    send_keyboard_report();
                }
            }
            break;
        }
        case NEXT_DEFAULT_LAYER:
        {
            if (record->event.pressed)
            {
                if (default_layer_state == 0)
                {
                    default_layer_state = 1;
                }
                default_layer_state = (default_layer_state << 1) & ~(1UL << _DL_MAX);
                dprintf("default_layer_state: 0x%08X\n", default_layer_state);
                persistent_default_layer_set(default_layer_state);
            }
            break;
        }
        case MAC_GUITAB_ENABLE:
        {
            if (record->event.pressed)
            {
                register_code(KC_LGUI);
                register_code(KC_TAB);
                unregister_code(KC_TAB);
                layer_on(_GL_MAC_GUITAB);
            }
            
            break;
        }
        case MAC_GUITAB_DISABLE:
        {
            if (record->event.pressed)
            {
                unregister_code(KC_LGUI);
                layer_off(_GL_MAC_GUITAB);
                layer_off(_GL_MAC);
            }
            
            break;
        }
    }
}

void matrix_init_user()
{
    debug_enable = true;
}