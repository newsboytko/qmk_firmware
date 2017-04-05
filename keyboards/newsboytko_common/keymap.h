#pragma once
#ifndef __COMMON_KEYMAP_H__
#define __COMMON_KEYMAP_H__

// Readability
#define _______ KC_TRNS
#define XXXXXXX KC_NO

enum common_layer_id {
    common_layer_default_windows,
    common_layer_default_mac,
    common_layer_fn,
    common_layer_fn_ext,
    common_layer_id_max
};

#define DEFINE_COMMON_LAYERS() \
\
/* Keymap common_layer_default_windows: Default layer (Windows)

  ,----.    ,-------------------. ,-------------------. ,-------------------. ,--------------.
  |Esc |    | F1 | F2 | F3 | F4 | | F5 | F6 | F7 | F8 | | F9 | F10| F11| F12| |    |    |    |
  `----'    `-------------------' `-------------------' `-------------------' `--------------'
  ,-------------------------------------------------------------------------. ,--------------. ,-------------------.
  |Esc~| 1  | 2  | 3  | 4  | 5  | 6  | 7  | 8  | 9  | 0  | -  | =  | Backsp | |    |    |    | |    |    |    |    |
  |-------------------------------------------------------------------------| |--------------| |-------------------|
  | Tab  | Q  | W  | E  | R  | T  | Y  | U  | I  | O  | P  | [  | ]  |  \|  | |    |    |    | |    |    |    |    |
  |-------------------------------------------------------------------------| '--------------' |--------------     |
  |  FN   | A  | S  | D  | F  | G  | H  | J  | K  | L  | ;  | '  |   Enter  |                  |    |    |    |    |
  |-------------------------------------------------------------------------|      ,----.      |-------------------|
  | Shift   | Z  | X  | C  | V  | B  | N  | M  | ,  | .  | /  |       Shift |      |    |      |    |    |    |    |
  |-------------------------------------------------------------------------| ,--------------. |--------------     |
  |Ctrl|Gui |Alt |                                      |Alt |FNEX| FN |Ctrl| |    |    |    | |         |    |    |
  `-------------------------------------------------------------------------' `--------------' `-------------------'

  Foot switches:
                  ,--------.         ,--------.
                  |        |         |        |
                  |   FN   |         |        |
                  `--------'         `--------'
*/ \
[common_layer_default_windows] = KEYMAP_COMMON(\
       KC_ESC,  KC_F1,  KC_F2,  KC_F3,  KC_F4,  KC_F5,  KC_F6,  KC_F7,  KC_F8,  KC_F9, KC_F10, KC_F11, KC_F12,          KC_PSCR,KC_SLCK,KC_PAUS,                        \
       KC_GRV,   KC_1,   KC_2,   KC_3,   KC_4,   KC_5,   KC_6,   KC_7,   KC_8,   KC_9,   KC_0,KC_MINS, KC_EQL,KC_BSPC,   KC_INS,KC_HOME,KC_PGUP,  KC_NLCK,KC_PSLS,KC_PAST,KC_PMNS, \
       KC_TAB,   KC_Q,   KC_W,   KC_E,   KC_R,   KC_T,   KC_Y,   KC_U,   KC_I,   KC_O,   KC_P,KC_LBRC,KC_RBRC,KC_BSLS,   KC_DEL, KC_END,KC_PGDN,    KC_P7,  KC_P8,  KC_P9,KC_PPLS, \
      MO(common_layer_fn),   KC_A,   KC_S,   KC_D,   KC_F,   KC_G,   KC_H,   KC_J,   KC_K,   KC_L,KC_SCLN,KC_QUOT,         KC_ENT,                              KC_P4,  KC_P5,  KC_P6,      \
      KC_LSFT,KC_NUBS,   KC_Z,   KC_X,   KC_C,   KC_V,   KC_B,   KC_N,   KC_M,KC_COMM, KC_DOT,KC_SLSH,        KC_RSFT,            KC_UP,            KC_P1,  KC_P2,  KC_P3,KC_PENT, \
      KC_LCTL,KC_LGUI,KC_LALT,                 KC_SPC,                                KC_RALT,MO(common_layer_fn_ext), MO(common_layer_fn),KC_RCTL,  KC_LEFT,KC_DOWN,KC_RGHT,    KC_P0,KC_PDOT, \
      MO(common_layer_fn), KC_LSFT), \
\
/* Keymap common_layer_default_mac: Default layer (Mac)

  ,----.    ,-------------------. ,-------------------. ,-------------------. ,--------------.
  |Esc |    | F1 | F2 | F3 | F4 | | F5 | F6 | F7 | F8 | | F9 | F10| F11| F12| |    |    |    |
  `----'    `-------------------' `-------------------' `-------------------' `--------------'
  ,-------------------------------------------------------------------------. ,--------------. ,-------------------.
  |Esc~| 1  | 2  | 3  | 4  | 5  | 6  | 7  | 8  | 9  | 0  | -  | =  | Backsp | |    |    |    | |    |    |    |    |
  |-------------------------------------------------------------------------| |--------------| |-------------------|
  | Tab  | Q  | W  | E  | R  | T  | Y  | U  | I  | O  | P  | [  | ]  |  \|  | |    |    |    | |    |    |    |    |
  |-------------------------------------------------------------------------| '--------------' |--------------     |
  |  FN   | A  | S  | D  | F  | G  | H  | J  | K  | L  | ;  | '  |   Enter  |                  |    |    |    |    |
  |-------------------------------------------------------------------------|      ,----.      |-------------------|
  | Shift   | Z  | X  | C  | V  | B  | N  | M  | ,  | .  | /  |       Shift |      |    |      |    |    |    |    |
  |-------------------------------------------------------------------------| ,--------------. |--------------     |
  |Ctrl|Alt |Gui |                                      |Gui |FNEX| FN |Ctrl| |    |    |    | |         |    |    |
  `-------------------------------------------------------------------------' `--------------' `-------------------'

  Foot switches:
                  ,--------.         ,--------.
                  |        |         |        |
                  |   FN   |         |        |
                  `--------'         `--------'
*/ \
[common_layer_default_mac] = KEYMAP_COMMON(\
       KC_ESC,  KC_F1,  KC_F2,  KC_F3,  KC_F4,  KC_F5,  KC_F6,  KC_F7,  KC_F8,  KC_F9, KC_F10, KC_F11, KC_F12,          KC_PSCR,KC_SLCK,KC_PAUS,                        \
       KC_GRV,   KC_1,   KC_2,   KC_3,   KC_4,   KC_5,   KC_6,   KC_7,   KC_8,   KC_9,   KC_0,KC_MINS, KC_EQL,KC_BSPC,   KC_INS,KC_HOME,KC_PGUP,  KC_NLCK,KC_PSLS,KC_PAST,KC_PMNS, \
       KC_TAB,   KC_Q,   KC_W,   KC_E,   KC_R,   KC_T,   KC_Y,   KC_U,   KC_I,   KC_O,   KC_P,KC_LBRC,KC_RBRC,KC_BSLS,   KC_DEL, KC_END,KC_PGDN,    KC_P7,  KC_P8,  KC_P9,KC_PPLS, \
      MO(common_layer_fn),   KC_A,   KC_S,   KC_D,   KC_F,   KC_G,   KC_H,   KC_J,   KC_K,   KC_L,KC_SCLN,KC_QUOT,         KC_ENT,                              KC_P4,  KC_P5,  KC_P6,      \
      KC_LSFT,KC_NUBS,   KC_Z,   KC_X,   KC_C,   KC_V,   KC_B,   KC_N,   KC_M,KC_COMM, KC_DOT,KC_SLSH,        KC_RSFT,            KC_UP,            KC_P1,  KC_P2,  KC_P3,KC_PENT, \
      KC_LCTL,KC_LALT,KC_LGUI,                 KC_SPC,                                KC_RGUI,MO(common_layer_fn_ext), MO(common_layer_fn),KC_RCTL,  KC_LEFT,KC_DOWN,KC_RGHT,    KC_P0,KC_PDOT, \
      MO(common_layer_fn), KC_LSFT), \
\
/* Keymap common_layer_fn: Function Layer

  ,----.    ,-------------------. ,-------------------. ,-------------------. ,--------------.
  |    |    |    |    |    |    | |    |    |    |    | |    |    |    |    | |    |    |    |
  `----'    `-------------------' `-------------------' `-------------------' `--------------'
  ,-------------------------------------------------------------------------. ,--------------. ,-------------------.
  |    |    |    |    |    |    |    |    |    |    |    |    |    |        | |    |    |    | |    |    |    |    |
  |-------------------------------------------------------------------------| |--------------| |-------------------|
  |      |    |    |    |    |    |    |    | Up |    |    |    |    |      | |    |    |    | |    |    |    |    |
  |-------------------------------------------------------------------------| '--------------' |--------------     |
  |       |    |    |    |    |    |    |Left|Down|Rght|    |    |          |                  |    |    |    |    |
  |-------------------------------------------------------------------------|      ,----.      |-------------------|
  |         |    |    |    |    |    |    |    |    |    |    |             |      |    |      |    |    |    |    |
  |-------------------------------------------------------------------------| ,--------------. |--------------     |
  |    |    |    |                                      |    |    |    |    | |    |    |    | |         |    |    |
  `-------------------------------------------------------------------------' `--------------' `-------------------'

  Foot switches:
                  ,--------.         ,--------.
                  |        |         |        |
                  |        |         |        |
                  `--------'         `--------'
*/ \
[common_layer_fn] = KEYMAP_COMMON(\
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
    _______, _______, _______, _______, _______, _______, _______, _______, KC_UP, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
    _______, _______, _______, _______, _______, _______, _______, KC_LEFT, KC_DOWN, KC_RGHT, _______, _______, _______, _______, _______, _______, \
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
    _______, _______), \
\
/* Keymap common_layer_fn_ext: Extended Function Layer

  ,----.    ,-------------------. ,-------------------. ,-------------------. ,--------------.
  |    |    |    |    |    |    | |    |    |    |    | |    |    |    |    | |    |    |    |
  `----'    `-------------------' `-------------------' `-------------------' `--------------'
  ,-------------------------------------------------------------------------. ,--------------. ,-------------------.
  |    |    |    |    |    |    |    |    |    |    |    |    |    |  RESET | |    |    |    | |    |    |    |    |
  |-------------------------------------------------------------------------| |--------------| |-------------------|
  |      |    |    |    |    |    |    |    |    |    |    |    |    |      | |    |    |    | |    |    |    |    |
  |-------------------------------------------------------------------------| '--------------' |--------------     |
  |       |    |    |    |    |    |    |    |    |    |    |    |          |                  |    |    |    |    |
  |-------------------------------------------------------------------------|      ,----.      |-------------------|
  |         |    |    |    |    |    |    |    |    |    |    |             |      |    |      |    |    |    |    |
  |-------------------------------------------------------------------------| ,--------------. |--------------     |
  |    |    |    |                                      |    |    |    |    | |    |    |    | |         |    |    |
  `-------------------------------------------------------------------------' `--------------' `-------------------'

  Foot switches:
                  ,--------.         ,--------.
                  |        |         |        |
                  |        |         |        |
                  `--------'         `--------'
*/ \
[common_layer_fn_ext] = KEYMAP_COMMON(\
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, RESET, _______, _______, _______, _______, _______, _______, _______, \
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
    _______, _______)



// Template
#if 0
/* Keymap X: XXXXX

  ,----.    ,-------------------. ,-------------------. ,-------------------. ,--------------.
  |    |    |    |    |    |    | |    |    |    |    | |    |    |    |    | |    |    |    |
  `----'    `-------------------' `-------------------' `-------------------' `--------------'
  ,-------------------------------------------------------------------------. ,--------------. ,-------------------.
  |    |    |    |    |    |    |    |    |    |    |    |    |    |        | |    |    |    | |    |    |    |    |
  |-------------------------------------------------------------------------| |--------------| |-------------------|
  |      |    |    |    |    |    |    |    |    |    |    |    |    |      | |    |    |    | |    |    |    |    |
  |-------------------------------------------------------------------------| '--------------' |--------------     |
  |       |    |    |    |    |    |    |    |    |    |    |    |          |                  |    |    |    |    |
  |-------------------------------------------------------------------------|      ,----.      |-------------------|
  |         |    |    |    |    |    |    |    |    |    |    |             |      |    |      |    |    |    |    |
  |-------------------------------------------------------------------------| ,--------------. |--------------     |
  |    |    |    |                                      |    |    |    |    | |    |    |    | |         |    |    |
  `-------------------------------------------------------------------------' `--------------' `-------------------'

  Foot switches:
                  ,--------.         ,--------.
                  |        |         |        |
                  |        |         |        |
                  `--------'         `--------'
*/ \
[X] = KEYMAP_COMMON(\
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
    _______, _______)
#endif

#endif // __COMMON_KEYMAP_H__