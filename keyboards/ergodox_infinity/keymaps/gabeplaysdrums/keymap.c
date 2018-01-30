#include QMK_KEYBOARD_H
#include "eeprom.h"
#include "eeconfig.h"

#define EECONFIG_GABEPLAYSDRUMS                         (uint32_t *)15

#define XXXXX KC_NO
#define _____ KC_TRNS

enum layers {
    BASE,
    SYMB,
    FUNC,
};

enum custom_keycodes {
    MAKE = SAFE_RANGE,
    MAKE_RIGHT,
    CPP_DEREF,
    OS_MOD_WORD,
    OS_MOD_OPT,
    OS_TOGGLE,
    MY_SAFE_RANGE,
};

enum os_type {
    OS_WINDOWS,
    OS_MAC,
    OS_MAX
};

typedef union {
  uint32_t raw;
  struct {
    uint8_t os      :2;
  };
} my_config_t;

static my_config_t my_config = {
    .os = OS_MAC,
};

uint32_t eeconfig_read_my_config(void) {
  return eeprom_read_dword(EECONFIG_GABEPLAYSDRUMS);
}
void eeconfig_update_my_config(uint32_t val) {
  eeprom_update_dword(EECONFIG_GABEPLAYSDRUMS, val);
}

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Base Layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * | Esc    |   1  |   2  |   3  |   4  |   5  |      |           |      |   6  |   7  |   8  |   9  |   0  |   -    |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * | Tab    |   Q  |   W  |   E  |   R  |   T  |      |           |      |   Y  |   U  |   I  |   O  |   P  |   \    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | SYMB   |   A  |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  |   ;  |   '    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | LShift |   Z  |   X  |   C  |   V  |   B  |      |           |      |   N  |   M  |   ,  |   .  |   /  | RShift |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       | GUI  |      |      | SYMB | FUNC |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 | Bksp | FUNC |------|       |------|Enter |Space |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
[BASE] = KEYMAP(
        // left hand
        KC_ESC, KC_1, KC_2, KC_3, KC_4, KC_5, XXXXX,
        KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, XXXXX,
        MO(SYMB), KC_A, KC_S, KC_D, KC_F, KC_G,
        KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, XXXXX,
        KC_LCTL, KC_LGUI, KC_LALT, XXXXX, XXXXX,
                                                        XXXXX, XXXXX,
                                                        XXXXX,
                                                        KC_BSPC, TT(FUNC), XXXXX,

        // right hand
                                XXXXX, KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINS,
                                XXXXX, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_BSLS,
                                KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT,
                                XXXXX, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_RSFT,
                                KC_RGUI, XXXXX, XXXXX, TT(SYMB), TT(FUNC),
        XXXXX, XXXXX,
        XXXXX,
        XXXXX, KC_ENT, KC_SPC
    ),

/* Symbol Layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |   ~  |   <  |   >  |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |   &  |   {  |   }  |  +   |  -   |   /    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |------|           |------|   !  |   (  |   )  |  =   |  0   |   *    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |   |  |   [  |   ]  |  ->  |  %   |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
[SYMB] = KEYMAP(
        // left hand
        _____, _____, _____, _____, _____, _____, _____,
        _____, _____, _____, _____, _____, _____, _____,
        _____, _____, _____, _____, _____, _____,
        _____, _____, _____, _____, _____, _____, _____,
        _____, _____, _____, _____, _____,
                                                        _____, _____,
                                                        _____,
                                                        _____, _____, _____,

        // right hand
                                _____, KC_TILD, KC_LT, KC_GT, _____, _____, _____,
                                _____, KC_AMPR, KC_LCBR, KC_RCBR, KC_PLUS, KC_MINS, KC_SLSH,
                                KC_EXLM, KC_LPRN, KC_RPRN, KC_EQL, KC_0, KC_ASTR,
                                _____, KC_PIPE, KC_LBRC, KC_RBRC, CPP_DEREF, KC_PERC, _____,
                                _____, _____, _____, _____, _____,
        _____, _____,
        _____,
        _____, _____, _____
    ),

/* Function Layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |  F1  |  F2  |  F3  |  F4  |  F5  |      |           |      |  F6  |  F7  |  F8  |  F9  | F10  |  F11   |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      | PgUp | Home |  Up  | End  |      |  F12   |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      | Ctrl |Shift | Alt  |      |------|           |------| PgDn | Left | Down | Right|      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        | MAKE |RESET |       | RESET| MAKE |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      | OS++ |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
[FUNC] = KEYMAP(
        // left hand
        _____, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, _____,
        _____, _____, _____, _____, _____, _____, _____,
        _____, _____, OS_MOD_OPT, KC_LSFT, OS_MOD_WORD, _____,
        _____, _____, _____, _____, _____, _____, _____,
        _____, _____, _____, _____, _____,
                                                        MAKE, RESET,
                                                        _____,
                                                        _____, _____, OS_TOGGLE,

        // right hand
                                _____, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11,
                                _____, KC_PGUP, KC_HOME, KC_UP, KC_END, _____, KC_F12,
                                KC_PGDN, KC_LEFT, KC_DOWN, KC_RGHT, _____, _____,
                                _____, _____, _____, _____, _____, _____, _____,
                                _____, _____, _____, _____, _____,
        RESET, MAKE_RIGHT,
        _____,
        _____, _____, _____
    ),

};

#if 0

/* Template Layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |------|           |------|      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
[TEMPLATE] = KEYMAP(
        // left hand
        _____, _____, _____, _____, _____, _____, _____,
        _____, _____, _____, _____, _____, _____, _____,
        _____, _____, _____, _____, _____, _____,
        _____, _____, _____, _____, _____, _____, _____,
        _____, _____, _____, _____, _____,
                                                        _____, _____,
                                                        _____,
                                                        _____, _____, _____,

        // right hand
                                _____, _____, _____, _____, _____, _____, _____,
                                _____, _____, _____, _____, _____, _____, _____,
                                _____, _____, _____, _____, _____, _____,
                                _____, _____, _____, _____, _____, _____, _____,
                                _____, _____, _____, _____, _____,
        _____, _____,
        _____,
        _____, _____, _____
    ),

#endif

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case MAKE:
        case MAKE_RIGHT:
            if (record->event.pressed) {
                SEND_STRING("make ergodox_infinity:gabeplaysdrums:dfu-util");
                if (keycode == MAKE_RIGHT) {
                    SEND_STRING(" MASTER=right");
                }
                SEND_STRING(SS_TAP(X_ENTER));
            }
            return false;
        case CPP_DEREF:
            if (record->event.pressed) {
                SEND_STRING("->");
            }
            return false;
        case OS_MOD_WORD:
        {
            uint8_t code;

            if (my_config.os == OS_WINDOWS) {
                code = KC_LCTL;
            }
            else { // my_config.os == OS_MAC
                code = KC_LALT;
            }

            if (record->event.pressed) {
                register_code(code);
            }
            else {
                unregister_code(code);
            }

            return false;
        }
        case OS_MOD_OPT:
        {
            uint8_t code;

            if (my_config.os == OS_WINDOWS) {
                code = KC_LALT;
            }
            else { // my_config.os == OS_MAC
                code = KC_LCTL;
            }

            if (record->event.pressed) {
                register_code(code);
            }
            else {
                unregister_code(code);
            }

            return false;
        }
        case OS_TOGGLE:
            if (record->event.pressed) {
                ++my_config.os;
                if (my_config.os >= OS_MAX) my_config.os = 0;
                eeconfig_update_my_config(my_config.raw);
            }
            return false;
        default:
          return true;
    }
}

void matrix_scan_user(void) {

    ergodox_board_led_off();
    ergodox_right_led_1_off();
    ergodox_right_led_2_off();
    ergodox_right_led_3_off();

    if (layer_state & (SYMB << 1))
    {
        ergodox_right_led_1_on();
    }

    if (layer_state & (FUNC << 1))
    {
        ergodox_right_led_2_on();
    }

}

void matrix_init_user(void) {
    my_config.raw = eeconfig_read_my_config();
}