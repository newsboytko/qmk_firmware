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
    OS_TOGGLE,
    OS_MOD_META,
    OS_MOD_WORD,
    OS_MOD_GUI_OR_ALT,
    OS_MOD_ALT_OR_GUI,
    OS_SAVE,
    OS_QUIT,
    OS_UNDO,
    OS_CUT,
    OS_COPY,
    OS_PASTE,
    OS_SELECTALL,
    OS_LAUNCH,
    OS_RUN,
    OS_SWITCH_TASK,
    OS_NEXT_TASK,
    OS_PREV_TASK,
    OS_NEXT_DESKTOP,
    OS_PREV_DESKTOP,
    OS_NEXT_COMPUTER,
    OS_PREV_COMPUTER,
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

typedef struct {
    bool task_switcher_active;
} my_state_t;

static my_state_t my_state = {
    .task_switcher_active = false,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Base Layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * | Esc    |   1  |   2  |   3  |   4  |   5  |      |           |      |   6  |   7  |   8  |   9  |   0  |   -    |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * | Tab    |   Q  |   W  |   E  |   R  |   T  | COPY |           |Desk  |   Y  |   U  |   I  |   O  |   P  |   \    |
 * |--------+------+------+------+------+------|      |           |top-  |------+------+------+------+------+--------|
 * | SYMB   |   A  |   S  |   D  |   F  |   G  |------|           |------|   H  |J/Tsk+|K/Tsk-|   L  |   ;  |   '    |
 * |--------+------+------+------+------+------| PASTE|           |Desk  |------+------+------+------+------+--------|
 * | LShift |   Z  |   X  |   C  |   V  |   B  |      |           |top+  |   N  |   M  |   ,  |   .  |   /  | RShift |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   | Ctrl |#/Alt |Alt/# |      |      |                                       | META |      |      | SYMB | FUNC |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 | Bksp | FUNC |------|       |------|Enter |Space |
 *                                 |      |      | TASK |       |LAUNCH|      |      |
 *                                 `--------------------'       `--------------------'
 */
[BASE] = KEYMAP(
        // left hand
        KC_ESC, KC_1, KC_2, KC_3, KC_4, KC_5, XXXXX,
        KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, OS_COPY,
        MO(SYMB), KC_A, KC_S, KC_D, KC_F, KC_G,
        KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, OS_PASTE,
        KC_LCTL, OS_MOD_GUI_OR_ALT, OS_MOD_ALT_OR_GUI, XXXXX, XXXXX,
                                                        XXXXX, XXXXX,
                                                        XXXXX,
                                                        KC_BSPC, TT(FUNC), OS_SWITCH_TASK,

        // right hand
                                XXXXX, KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINS,
                                OS_PREV_DESKTOP, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_BSLS,
                                KC_H, OS_NEXT_TASK, OS_PREV_TASK, KC_L, KC_SCLN, KC_QUOT,
                                OS_NEXT_DESKTOP, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_RSFT,
                                OS_MOD_META, XXXXX, XXXXX, TT(SYMB), TT(FUNC),
        XXXXX, XXXXX,
        XXXXX,
        OS_LAUNCH, KC_ENT, KC_SPC
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
 *                                 |      |      |------|       |------|      |   _  |
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
        _____, _____, KC_UNDS
    ),

/* Function Layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |  F1  |  F2  |  F3  |  F4  |  F5  |      |           |      |  F6  |  F7  |  F8  |  F9  | F10  |  F11   |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        | QUIT |      |      | RUN  |      |      |           |Compu | PgUp | Home |  Up  | End  |      |  F12   |
 * |--------+------+------+------+------+------|      |           |ter-  |------+------+------+------+------+--------|
 * |        |SELALL| SAVE |Shift | WORD |      |------|           |------| PgDn | Left | Down | Right|      |        |
 * |--------+------+------+------+------+------|      |           |Compu |------+------+------+------+------+--------|
 * |        | UNDO | CUT  | COPY |PASTE |      |      |           |ter+  |      |      |      |      |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        | MAKE |RESET |       | RESET| MAKE |
 *                                 ,------|------|------|       |------+------+------.
 *                                 | META |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      | OS++ |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
[FUNC] = KEYMAP(
        // left hand
        _____, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, _____,
        _____, OS_QUIT, _____, _____, OS_RUN, _____, _____,
        _____, OS_SELECTALL, OS_SAVE, KC_LSFT, OS_MOD_WORD, _____,
        _____, OS_UNDO, OS_CUT, OS_COPY, OS_PASTE, _____, _____,
        _____, _____, _____, _____, _____,
                                                        MAKE, RESET,
                                                        _____,
                                                        _____, _____, OS_TOGGLE,

        // right hand
                                _____, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11,
                                OS_PREV_COMPUTER, KC_PGUP, KC_HOME, KC_UP, KC_END, _____, KC_F12,
                                KC_PGDN, KC_LEFT, KC_DOWN, KC_RGHT, _____, _____,
                                OS_NEXT_COMPUTER, _____, _____, _____, _____, _____, _____,
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
        case OS_TOGGLE:
            if (record->event.pressed) {
                ++my_config.os;
                if (my_config.os >= OS_MAX) my_config.os = 0;
                eeconfig_update_my_config(my_config.raw);
            }
            return false;
        case OS_QUIT:
        {
            if (record->event.pressed) {
                if (my_config.os == OS_WINDOWS) {
                    SEND_STRING(SS_DOWN(X_LALT) SS_TAP(X_F4) SS_UP(X_LALT));
                }
                else { // my_config.os == OS_MAC
                    SEND_STRING(SS_LGUI("q"));
                }
            }

            return false;
        }
        case OS_LAUNCH:
        {
            if (record->event.pressed) {
                if (my_config.os == OS_WINDOWS) {
                    SEND_STRING(SS_TAP(X_LGUI));
                }
                else { // my_config.os == OS_MAC
                    SEND_STRING(SS_LCTRL(" "));
                }
            }

            return false;
        }
        case OS_RUN:
        {
            if (record->event.pressed) {
                if (my_config.os == OS_WINDOWS) {
                    SEND_STRING(SS_LGUI("r"));
                }
                else { // my_config.os == OS_MAC
                    SEND_STRING(SS_LCTRL(" ") "terminal" SS_TAP(X_ENTER));
                }
            }

            return false;
        }
        case OS_SWITCH_TASK:
        {
            if (record->event.pressed) {
                if (my_config.os == OS_WINDOWS) {
                    SEND_STRING(SS_DOWN(X_LALT) SS_TAP(X_TAB));
                }
                else { // my_config.os == OS_MAC
                    SEND_STRING(SS_DOWN(X_LGUI) SS_TAP(X_TAB));
                }
                my_state.task_switcher_active = true;
            }
            else
            {
                if (my_config.os == OS_WINDOWS) {
                    SEND_STRING(SS_UP(X_LALT));
                }
                else { // my_config.os == OS_MAC
                    SEND_STRING(SS_UP(X_LGUI));
                }
                my_state.task_switcher_active = false;
            }

            return false;
        }
        case OS_NEXT_TASK:
        {
            if (my_state.task_switcher_active) {
                if (record->event.pressed) {
                    SEND_STRING(SS_TAP(X_TAB));
                }
            }
            else {
                if (record->event.pressed) {
                    register_code(KC_J);
                }
                else
                {
                    unregister_code(KC_J);
                }
            }

            return false;
        }
        case OS_PREV_TASK:
        {
            if (my_state.task_switcher_active) {
                if (record->event.pressed) {
                    SEND_STRING(SS_DOWN(X_LSHIFT) SS_TAP(X_TAB) SS_UP(X_LSHIFT));
                }
            }
            else {
                if (record->event.pressed) {
                    register_code(KC_K);
                }
                else
                {
                    unregister_code(KC_K);
                }
            }

            return false;
        }
        case OS_NEXT_DESKTOP:
        {
            if (record->event.pressed) {
                if (my_config.os == OS_WINDOWS) {
                    SEND_STRING(SS_DOWN(X_LCTRL) SS_DOWN(X_LGUI) SS_TAP(X_RIGHT) SS_UP(X_LGUI) SS_UP(X_LCTRL));
                }
                else { // my_config.os == OS_MAC
                    SEND_STRING(SS_DOWN(X_LCTRL) SS_TAP(X_RIGHT) SS_UP(X_LCTRL));
                }
            }
            return false;
        }
        case OS_PREV_DESKTOP:
        {
            if (record->event.pressed) {
                if (my_config.os == OS_WINDOWS) {
                    SEND_STRING(SS_DOWN(X_LCTRL) SS_DOWN(X_LGUI) SS_TAP(X_LEFT) SS_UP(X_LGUI) SS_UP(X_LCTRL));
                }
                else { // my_config.os == OS_MAC
                    SEND_STRING(SS_DOWN(X_LCTRL) SS_TAP(X_LEFT) SS_UP(X_LCTRL));
                }
            }
            return false;
        }
        case OS_NEXT_COMPUTER:
        {
            if (record->event.pressed) {
                if (my_config.os == OS_WINDOWS) {
                    SEND_STRING(SS_TAP(X_LCTRL) SS_TAP(X_LCTRL) "2" SS_TAP(X_ENTER));
                }
                else { // my_config.os == OS_MAC
                }
            }
            return false;
        }
        case OS_PREV_COMPUTER:
        {
            if (record->event.pressed) {
                if (my_config.os == OS_WINDOWS) {
                    SEND_STRING(SS_TAP(X_LCTRL) SS_TAP(X_LCTRL) "1" SS_TAP(X_ENTER));
                }
                else { // my_config.os == OS_MAC
                }
            }
            return false;
        }

#define DEFINE_BASIC_OS_COMMAND(kc, shortcut) \
        case kc: \
        { \
            if (record->event.pressed) { \
                if (my_config.os == OS_WINDOWS) { \
                    SEND_STRING(SS_LCTRL(shortcut)); \
                } \
                else { /* my_config.os == OS_MAC */ \
                    SEND_STRING(SS_LGUI(shortcut)); \
                } \
            } \
            return false; \
        }

        DEFINE_BASIC_OS_COMMAND(OS_SELECTALL, "a")
        DEFINE_BASIC_OS_COMMAND(OS_SAVE, "s")
        DEFINE_BASIC_OS_COMMAND(OS_UNDO, "z")
        DEFINE_BASIC_OS_COMMAND(OS_CUT, "x")
        DEFINE_BASIC_OS_COMMAND(OS_COPY, "c")
        DEFINE_BASIC_OS_COMMAND(OS_PASTE, "v")

#undef DEFINE_BASIC_OS_COMMAND

#define DEFINE_BASIC_OS_MOD(kc, windows, mac) \
        case kc: \
        { \
            uint8_t code; \
            if (my_config.os == OS_WINDOWS) { \
                code = windows; \
            } \
            else { /* my_config.os == OS_MAC */ \
                code = mac; \
            } \
            if (record->event.pressed) { \
                register_code(code); \
            } \
            else { \
                unregister_code(code); \
            } \
            return false; \
        }

        DEFINE_BASIC_OS_MOD(OS_MOD_META, KC_LCTL, KC_LGUI)
        DEFINE_BASIC_OS_MOD(OS_MOD_WORD, KC_LCTL, KC_LALT)
        DEFINE_BASIC_OS_MOD(OS_MOD_GUI_OR_ALT, KC_LGUI, KC_LALT)
        DEFINE_BASIC_OS_MOD(OS_MOD_ALT_OR_GUI, KC_LALT, KC_LGUI)

#undef DEFINE_BASIC_OS_MOD

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