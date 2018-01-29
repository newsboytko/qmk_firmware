#include QMK_KEYBOARD_H

#define XXXXX KC_NO
#define _____ KC_TRNS

enum layers {
    BASE,
};

enum custom_keycodes {
  MY_SAFE_RANGE = SAFE_RANGE,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Base Layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * | Esc    |   1  |   2  |   3  |   4  |   5  |      |           |      |   6  |   7  |   8  |   9  |   0  |   -    |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * | Tab    |   Q  |   W  |   E  |   R  |   T  |      |           |      |   Y  |   U  |   I  |   O  |   P  |   =    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |   A  |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  |   ;  |   '    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | LShift |   Z  |   X  |   C  |   V  |   B  |      |           |      |   N  |   M  |   ,  |   .  |   /  | RShift |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 | Bksp |      |------|       |------|Enter |Space |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
[BASE] = KEYMAP(
        // left hand
        KC_ESC, KC_1, KC_2, KC_3, KC_4, KC_5, XXXXX,
        KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, XXXXX,
        XXXXX, KC_A, KC_S, KC_D, KC_F, KC_G,
        KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, XXXXX,
        KC_LCTL, KC_LGUI, KC_LALT, XXXXX, XXXXX,
                                                        XXXXX, XXXXX,
                                                        XXXXX,
                                                        KC_BSPC, XXXXX, XXXXX,

        // right hand
                                XXXXX, KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINS,
                                XXXXX, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_EQL,
                                KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT,
                                XXXXX, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_RSFT,
                                XXXXX, XXXXX, XXXXX, XXXXX, XXXXX,
        XXXXX, XXXXX,
        XXXXX,
        XXXXX, KC_ENT, KC_SPC
    ),

};