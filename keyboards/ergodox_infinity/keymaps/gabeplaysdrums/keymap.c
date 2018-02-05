#include QMK_KEYBOARD_H
#include "eeprom.h"
#include "eeconfig.h"
#include "wait.h"

#define EECONFIG_GABEPLAYSDRUMS                         (uint32_t *)15

#define XXXXX KC_NO
#define _____ KC_TRNS

enum layers {
    BASE,
    SYMB,
    FUNC,
    MAGIC_LAYER_MIN,
    NUMPAD = MAGIC_LAYER_MIN,
    PROTOOLS,
    MAGIC_LAYER_MAX
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
    OS_SELECT_LINE,
    OS_SAVE,
    OS_QUIT,
    OS_UNDO,
    OS_CUT,
    OS_COPY,
    OS_PASTE,
    OS_SELECT_ALL,
    OS_LAUNCH,
    OS_RUN,
    OS_SWITCH_TASK,
    OS_NEXT_TASK,
    OS_PREV_TASK,
    OS_NEXT_DESKTOP,
    OS_PREV_DESKTOP,
    OS_NEXT_COMPUTER,
    OS_PREV_COMPUTER,
    OS_SNAP_LEFT,
    OS_SNAP_RIGHT,
    OS_MOVE_NEXT_MONITOR,
    OS_MOVE_PREV_MONITOR,
    OS_MAXIMIZE,
    OS_MINIMIZE,
    MAGIC,
    MAGIC_TOGGLE,
    PT_SMART_TOOL,
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
    uint8_t magic_layer_index:4;
  };
} my_config_t;

static my_config_t my_config = {
    .os = OS_MAC,
    .magic_layer_index = 0,
};

uint32_t eeconfig_read_my_config(void) {
  return eeprom_read_dword(EECONFIG_GABEPLAYSDRUMS);
}
void eeconfig_update_my_config(uint32_t val) {
  eeprom_update_dword(EECONFIG_GABEPLAYSDRUMS, val);
}

typedef struct {
    bool task_switcher_active;
    uint16_t magic_timer;
} my_state_t;

static my_state_t my_state = {
    .task_switcher_active = false,
    .magic_timer = 0,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Base Layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * | Esc    |   1  |   2  |   3  |   4  |   5  |S.Line|           |      |   6  |   7  |   8  |   9  |   0  |   -    |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * | Tab    |   Q  |   W  |   E  |   R  |   T  | COPY |           |Desk  |   Y  |   U  |   I  |   O  |   P  |   \    |
 * |--------+------+------+------+------+------|      |           |top-  |------+------+------+------+------+--------|
 * | SYMB   |   A  |   S  |   D  |   F  |   G  |------|           |------|   H  |J/Tsk+|K/Tsk-|   L  |   ;  |   '    |
 * |--------+------+------+------+------+------| PASTE|           |Desk  |------+------+------+------+------+--------|
 * | LShift |   Z  |   X  |   C  |   V  |   B  |      |           |top+  |   N  |   M  |   ,  |   .  |   /  | RShift |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   | Ctrl |#/Alt |Alt/# |MAGIC+|MAGIC |                                       | META |MAGIC+|MAGIC | SYMB | FUNC |
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
        KC_ESC, KC_1, KC_2, KC_3, KC_4, KC_5, OS_SELECT_LINE,
        KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, OS_COPY,
        MO(SYMB), KC_A, KC_S, KC_D, KC_F, KC_G,
        KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, OS_PASTE,
        KC_LCTL, OS_MOD_GUI_OR_ALT, OS_MOD_ALT_OR_GUI, MAGIC_TOGGLE, MAGIC,
                                                        XXXXX, XXXXX,
                                                        XXXXX,
                                                        KC_BSPC, TT(FUNC), OS_SWITCH_TASK,

        // right hand
                                XXXXX, KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINS,
                                OS_PREV_DESKTOP, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_BSLS,
                                KC_H, OS_NEXT_TASK, OS_PREV_TASK, KC_L, KC_SCLN, KC_QUOT,
                                OS_NEXT_DESKTOP, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_RSFT,
                                OS_MOD_META, MAGIC_TOGGLE, MAGIC, TT(SYMB), TT(FUNC),
        XXXXX, XXXXX,
        XXXXX,
        OS_LAUNCH, KC_ENT, KC_SPC
    ),

/* Symbol Layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |   ~  |   <  |   >  |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |   &  |   {  |   }  |  +   |  %   |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |------|           |------|   !  |   (  |   )  |  =   |  -   |   _    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |   |  |   [  |   ]  |  ->  |  *   |        |
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
                                _____, KC_AMPR, KC_LCBR, KC_RCBR, KC_PLUS, KC_PERC, _____,
                                KC_EXLM, KC_LPRN, KC_RPRN, KC_EQL, KC_MINS, KC_UNDS,
                                _____, KC_PIPE, KC_LBRC, KC_RBRC, CPP_DEREF, KC_ASTR, _____,
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
 * |        | QUIT |      |      | RUN  |      |      |           |Compu | PgUp | Home |  Up  | End  |      |  F12   |
 * |--------+------+------+------+------+------|      |           |ter-  |------+------+------+------+------+--------|
 * |        |SELALL| SAVE |Shift | WORD |      |------|           |------| PgDn | Left | Down | Right|      |        |
 * |--------+------+------+------+------+------|      |           |Compu |------+------+------+------+------+--------|
 * |        | UNDO | CUT  | COPY |PASTE |      |      |           |ter+  |      | Mon- | Max  | Mon+ |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |Snap L| Min  |Snap R|      |      |
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
        _____, OS_QUIT, _____, _____, OS_RUN, _____, _____,
        _____, OS_SELECT_ALL, OS_SAVE, KC_LSFT, OS_MOD_WORD, _____,
        _____, OS_UNDO, OS_CUT, OS_COPY, OS_PASTE, _____, _____,
        _____, _____, _____, _____, _____,
                                                        MAKE, RESET,
                                                        _____,
                                                        _____, _____, OS_TOGGLE,

        // right hand
                                _____, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11,
                                OS_PREV_COMPUTER, KC_PGUP, KC_HOME, KC_UP, KC_END, _____, KC_F12,
                                KC_PGDN, KC_LEFT, KC_DOWN, KC_RGHT, _____, _____,
                                OS_NEXT_COMPUTER, _____, OS_MOVE_PREV_MONITOR, OS_MAXIMIZE, OS_MOVE_NEXT_MONITOR, _____, _____,
                                OS_SNAP_LEFT, OS_MINIMIZE, OS_SNAP_RIGHT, _____, _____,
        RESET, MAKE_RIGHT,
        _____,
        _____, _____, _____
    ),

/* Numpad Layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |  P7  |  P8  |  P9  |  /   |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |  P4  |  P5  |  P6  |  *   |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |------|           |------|      |  P1  |  P2  |  P3  |  +   |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |  P0  |  P0  |  P.  |  -   |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      | Pad  |      |
 *                                 |      |      |------|       |------| Enter|      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
[NUMPAD] = KEYMAP(
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
                                _____, _____, KC_P7, KC_P8, KC_P9, KC_PSLS, _____,
                                _____, _____, KC_P4, KC_P5, KC_P6, KC_PAST, _____,
                                _____, KC_P1, KC_P2, KC_P3, KC_PPLS, _____,
                                _____, _____, KC_P0, KC_P0, KC_PDOT, KC_PMNS, _____,
                                _____, _____, _____, _____, _____,
        _____, _____,
        _____,
        _____, KC_PENT, _____
    ),

/* Pro Tools Layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |Shuffl| Slip | Spot | Grid |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |  Tab   |      |      |      | Loop | Trim |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |Mix/Edit|      |Smart |      |      |      |------|           |------|      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        | Zoom | Cut  | Copy |Paste |Break |      |           |      |      |      |      |      |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 | Play |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      | Rec  |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
[PROTOOLS] = KEYMAP(
        // left hand
        KC_ESC, KC_F1, KC_F2, KC_F3, KC_F4, XXXXX, XXXXX,
        KC_TAB, XXXXX, XXXXX, XXXXX, LGUI(LSFT(KC_L)), KC_F6, XXXXX,
        LGUI(KC_EQL), XXXXX, PT_SMART_TOOL, XXXXX, XXXXX, XXXXX,
        KC_LSFT, KC_F5, LGUI(KC_X), LGUI(KC_C), LGUI(KC_V), LGUI(KC_E), XXXXX,
        _____, _____, _____, _____, _____,
                                                        XXXXX, XXXXX,
                                                        XXXXX,
                                                        KC_SPC, XXXXX, LGUI(KC_SPC),

        // right hand
                                XXXXX, XXXXX, XXXXX, XXXXX, XXXXX, XXXXX, XXXXX,
                                XXXXX, XXXXX, XXXXX, XXXXX, XXXXX, XXXXX, XXXXX,
                                XXXXX, XXXXX, XXXXX, XXXXX, XXXXX, XXXXX,
                                XXXXX, XXXXX, XXXXX, XXXXX, XXXXX, XXXXX, KC_RSFT,
                                _____, _____, _____, _____, _____,
        XXXXX, XXXXX,
        XXXXX,
        XXXXX, XXXXX, KC_SPC
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

void matrix_scan_magic(void);
bool process_record_magic(uint16_t keycode, keyrecord_t *record);

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (!process_record_magic(keycode, record)) return false;

    switch (keycode) {
        case MAKE:
        case MAKE_RIGHT:
        {
            if (record->event.pressed) {
                SEND_STRING("make ergodox_infinity:gabeplaysdrums:dfu-util");
                if (keycode == MAKE_RIGHT) {
                    SEND_STRING(" MASTER=right");
                }
                SEND_STRING(SS_TAP(X_ENTER));
            }
            return false;
        }
        case CPP_DEREF:
        {
            if (record->event.pressed) {
                SEND_STRING("->");
            }
            return false;
        }
        case PT_SMART_TOOL:
        {
            if (record->event.pressed) {
                if (my_config.os == OS_WINDOWS) {
                }
                else { // my_config.os == OS_MAC
                    SEND_STRING(SS_DOWN(X_F6) SS_DOWN(X_F7));
                    wait_ms(100);
                    SEND_STRING(SS_UP(X_F6) SS_UP(X_F7));
                }
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
        case OS_SELECT_LINE:
        {
            if (record->event.pressed) {
                if (my_config.os == OS_WINDOWS) {
                    SEND_STRING(SS_TAP(X_HOME) SS_DOWN(X_LSHIFT) SS_TAP(X_END) SS_UP(X_LSHIFT));
                }
                else { // my_config.os == OS_MAC
                    SEND_STRING(SS_DOWN(X_LGUI) SS_TAP(X_LEFT) SS_UP(X_LGUI) SS_DOWN(X_LSHIFT) SS_DOWN(X_LGUI) SS_TAP(X_RIGHT) SS_UP(X_LGUI) SS_UP(X_LSHIFT));
                }
            }

            return false;
        }
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
        case OS_SNAP_LEFT:
        {
            if (record->event.pressed) {
                if (my_config.os == OS_WINDOWS) {
                    SEND_STRING(SS_DOWN(X_LGUI) SS_TAP(X_LEFT) SS_UP(X_LGUI));
                }
                else { // my_config.os == OS_MAC
                    SEND_STRING(SS_DOWN(X_LCTRL) SS_DOWN(X_LALT) SS_DOWN(X_LGUI) SS_TAP(X_LEFT) SS_UP(X_LGUI) SS_UP(X_LALT) SS_UP(X_LCTRL));
                }
            }
            return false;
        }
        case OS_SNAP_RIGHT:
        {
            if (record->event.pressed) {
                if (my_config.os == OS_WINDOWS) {
                    SEND_STRING(SS_DOWN(X_LGUI) SS_TAP(X_RIGHT) SS_UP(X_LGUI));
                }
                else { // my_config.os == OS_MAC
                    SEND_STRING(SS_DOWN(X_LCTRL) SS_DOWN(X_LALT) SS_DOWN(X_LGUI) SS_TAP(X_RIGHT) SS_UP(X_LGUI) SS_UP(X_LALT) SS_UP(X_LCTRL));
                }
            }
            return false;
        }
        case OS_MAXIMIZE:
        {
            if (record->event.pressed) {
                if (my_config.os == OS_WINDOWS) {
                    SEND_STRING(SS_DOWN(X_LGUI) SS_TAP(X_UP) SS_UP(X_LGUI));
                }
                else { // my_config.os == OS_MAC
                    SEND_STRING(SS_DOWN(X_LCTRL) SS_DOWN(X_LALT) SS_DOWN(X_LGUI) "m" SS_UP(X_LGUI) SS_UP(X_LALT) SS_UP(X_LCTRL));
                }
            }
            return false;
        }
        case OS_MINIMIZE:
        {
            if (record->event.pressed) {
                if (my_config.os == OS_WINDOWS) {
                    SEND_STRING(SS_DOWN(X_LGUI) SS_TAP(X_DOWN) SS_UP(X_LGUI));
                }
                else { // my_config.os == OS_MAC
                    SEND_STRING(SS_LGUI("h"));
                }
            }
            return false;
        }
        case OS_MOVE_NEXT_MONITOR:
        {
            if (record->event.pressed) {
                if (my_config.os == OS_WINDOWS) {
                    SEND_STRING(SS_DOWN(X_LGUI) SS_DOWN(X_LSHIFT) SS_TAP(X_RIGHT) SS_UP(X_LSHIFT) SS_UP(X_LGUI));
                }
                else { // my_config.os == OS_MAC
                    SEND_STRING(SS_DOWN(X_LCTRL) SS_DOWN(X_LALT) SS_DOWN(X_LGUI) "n" SS_UP(X_LGUI) SS_UP(X_LALT) SS_UP(X_LCTRL));
                }
            }
            return false;
        }
        case OS_MOVE_PREV_MONITOR:
        {
            if (record->event.pressed) {
                if (my_config.os == OS_WINDOWS) {
                    SEND_STRING(SS_DOWN(X_LGUI) SS_DOWN(X_LSHIFT) SS_TAP(X_LEFT) SS_UP(X_LSHIFT) SS_UP(X_LGUI));
                }
                else { // my_config.os == OS_MAC
                    SEND_STRING(SS_DOWN(X_LCTRL) SS_DOWN(X_LALT) SS_DOWN(X_LGUI) "p" SS_UP(X_LGUI) SS_UP(X_LALT) SS_UP(X_LCTRL));
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

        DEFINE_BASIC_OS_COMMAND(OS_SELECT_ALL, "a")
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

// Runs whenever there is a layer state change.
uint32_t layer_state_set_user(uint32_t state) {

    print("layer_state_set_user\n");
    ergodox_board_led_off();
    ergodox_right_led_1_off();
    ergodox_right_led_2_off();
    ergodox_right_led_3_off();

    uint8_t layer = biton32(state);
    switch (layer) {
        case 0:
            break;
        case FUNC:
            ergodox_right_led_3_on();
            break;
        case SYMB:
            ergodox_right_led_2_on();
            break;
        default: // any other layer enabled
            ergodox_right_led_1_on();
            break;
    }

    return state;
};

void magic_init(void) {
    // Ensure config values are in valid range
    if (my_config.magic_layer_index >= (MAGIC_LAYER_MAX - MAGIC_LAYER_MIN)) {
        my_config.magic_layer_index = 0;
    }
}

void matrix_init_user(void) {
    my_config.raw = eeconfig_read_my_config();
    magic_init();
    eeconfig_update_my_config(my_config.raw);

    // enable debugging
    // debug_enable = true;
}

#define MAGIC_TAPPING_TERM TAPPING_TERM

void matrix_scan_user(void) {
    matrix_scan_magic();
}

void matrix_scan_magic(void) {
    if (my_state.magic_timer != 0 && timer_elapsed(my_state.magic_timer) >= MAGIC_TAPPING_TERM) {
        // Magic key is being held.  Turn on the layer
        for (int i = MAGIC_LAYER_MIN; i < MAGIC_LAYER_MAX; i++) {
            layer_off(i);
        }
        my_state.magic_timer = 0;
        layer_on(MAGIC_LAYER_MIN + my_config.magic_layer_index);
    }
}

bool process_record_magic(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case MAGIC:
        {
            if (record->event.pressed) {
                my_state.magic_timer = timer_read();
            }
            else {
                bool was_magic_on = false;
                for (int i = MAGIC_LAYER_MIN; i < MAGIC_LAYER_MAX; i++) {
                    was_magic_on = was_magic_on || !!(layer_state & (1ul << i));
                    layer_off(i);
                }
                if (my_state.magic_timer != 0 && timer_elapsed(my_state.magic_timer) < MAGIC_TAPPING_TERM) {
                    // tapped.  toggle the layer
                    my_state.magic_timer = 0;
                    if (!was_magic_on) layer_on(MAGIC_LAYER_MIN + my_config.magic_layer_index);
                }
            }

            return false;
        }
        case MAGIC_TOGGLE:
        {
            if (record->event.pressed) {
                if (++my_config.magic_layer_index >= (MAGIC_LAYER_MAX - MAGIC_LAYER_MIN)) {
                    my_config.magic_layer_index = 0;
                }
                eeconfig_update_my_config(my_config.raw);

                bool was_magic_on = false;
                for (int i = MAGIC_LAYER_MIN; i < MAGIC_LAYER_MAX; i++) {
                    was_magic_on = was_magic_on || !!(layer_state & (1ul << i));
                    layer_off(i);
                }
                if (was_magic_on) {
                    // turn on the new magic layer
                    my_state.magic_timer = 0;
                    layer_on(MAGIC_LAYER_MIN + my_config.magic_layer_index);
                }
            }

            return false;
        }
        default:
        {
            if (my_state.magic_timer != 0) {
                // magic key is being held.  layer should be on
                layer_on(MAGIC_LAYER_MIN + my_config.magic_layer_index);
                my_state.magic_timer = 0;
            }

            return true;
        }
    }
}