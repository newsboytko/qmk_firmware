#pragma once
#ifndef __COMMON_KEYMAP_H__
#define __COMMON_KEYMAP_H__

// Readability
#define _______ KC_TRNS
#define XXXXXXX KC_NO

enum common_layer_id {
    common_layer_default_basic,
    common_layer_default_windows,
    common_layer_default_mac,
    common_layer_default_max,
    common_layer_fn = common_layer_default_max,
    common_layer_fn_ext,
    common_layer_numpad,
    common_layer_gui_windows,
    common_layer_gui_windows_task_switch,
    common_layer_gui_mac,
    common_layer_gui_mac_task_switch,
    common_layer_email,
    common_layer_id_max
};

enum common_fn_id {
    common_fn_shift_esc,
    common_fn_next_default_layer,
    common_fn_windows_task_switch_enable,
    common_fn_windows_task_switch_select,
    common_fn_windows_task_switch_cancel,
    common_fn_mac_task_switch_enable,
    common_fn_mac_task_switch_select,
    common_fn_mac_task_switch_cancel,
    common_fn_email_enable,
    common_fn_email_reply,
    common_fn_email_forward,
    common_fn_email_new,
    common_fn_email_open,
    common_fn_email_hide_ui,
    common_fn_email_show_ui,
    common_fn_email_cancel,
    common_fn_id_max
};

enum common_macro_id {
    common_macro_kvm1,
    common_macro_kvm2,
    common_macro_id_max
};

#ifndef DEFINE_COMMON_LAYER_DEFAULT_MAC
#define DEFINE_COMMON_LAYER_DEFAULT_MAC() \
/* Keymap common_layer_default_mac: Default layer (Mac)

  ,----.    ,-------------------. ,-------------------. ,-------------------. ,--------------.
  |Esc |    | F1 | F2 | F3 | F4 | | F5 | F6 | F7 | F8 | | F9 | F10| F11| F12| |PrSc|ScLk|Paus|
  `----'    `-------------------' `-------------------' `-------------------' `--------------'
  ,-------------------------------------------------------------------------. ,--------------. ,-------------------.
  |Esc~| 1  | 2  | 3  | 4  | 5  | 6  | 7  | 8  | 9  | 0  | -  | =  | Backsp | |Ins |Home|PgUp| |    |    |    |    |
  |-------------------------------------------------------------------------| |--------------| |-------------------|
  | Tab  | Q  | W  | E  | R  | T  | Y  | U  | I  | O  | P  | [  | ]  |  \|  | |Del |End |PgDn| |    |    |    |    |
  |-------------------------------------------------------------------------| '--------------' |--------------     |
  |  FN   | A  | S  | D  | F  | G  | H  | J  | K  | L  | ;  | '  |   Enter  |                  |    |    |    |    |
  |-------------------------------------------------------------------------|      ,----.      |-------------------|
  | Shift   | Z  | X  | C  | V  | B  | N  | M  | ,  | .  | /  |       Shift |      | Up |      |    |    |    |    |
  |-------------------------------------------------------------------------| ,--------------. |--------------     |
  |Ctrl|Alt |Gui |                                      |FNOS|FNEX| FN |Ctrl| |Left|Down|Rght| |         |    |    |
  `-------------------------------------------------------------------------' `--------------' `-------------------'

  Foot switches:
                  ,--------.         ,--------.
                  |        |         |        |
                  |   FN   |         |        |
                  `--------'         `--------'
*/ \
KEYMAP_COMMON(\
       KC_ESC,  KC_F1,  KC_F2,  KC_F3,  KC_F4,  KC_F5,  KC_F6,  KC_F7,  KC_F8,  KC_F9, KC_F10, KC_F11, KC_F12,          KC_PSCR,TG(common_layer_numpad),KC_PAUS,                        \
       F(common_fn_shift_esc),   KC_1,   KC_2,   KC_3,   KC_4,   KC_5,   KC_6,   KC_7,   KC_8,   KC_9,   KC_0,KC_MINS, KC_EQL,KC_BSPC,   KC_INS,KC_HOME,KC_PGUP,  KC_NLCK,KC_PSLS,KC_PAST,KC_PMNS, \
       KC_TAB,   KC_Q,   KC_W,   KC_E,   KC_R,   KC_T,   KC_Y,   KC_U,   KC_I,   KC_O,   KC_P,KC_LBRC,KC_RBRC,KC_BSLS,   KC_DEL, KC_END,KC_PGDN,    KC_P7,  KC_P8,  KC_P9,KC_PPLS, \
      MO(common_layer_fn),   KC_A,   KC_S,   KC_D,   KC_F,   KC_G,   KC_H,   KC_J,   KC_K,   KC_L,KC_SCLN,KC_QUOT,         KC_ENT,                              KC_P4,  KC_P5,  KC_P6,      \
      KC_LSFT,KC_NUBS,   KC_Z,   KC_X,   KC_C,   KC_V,   KC_B,   KC_N,   KC_M,KC_COMM, KC_DOT,KC_SLSH,        KC_RSFT,            KC_UP,            KC_P1,  KC_P2,  KC_P3,KC_PENT, \
      KC_LCTL,KC_LALT,KC_LGUI,                 KC_SPC,                                MO(common_layer_gui_mac),MO(common_layer_fn_ext), MO(common_layer_fn),KC_RCTL,  KC_LEFT,KC_DOWN,KC_RGHT,    KC_P0,KC_PDOT, \
      MO(common_layer_fn), KC_LSFT)
#endif

#ifndef DEFINE_COMMON_LAYER_FN_EXT
#define DEFINE_COMMON_LAYER_FN_EXT() \
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
  |    |Def+|    |                                      |    |    |    |    | |    |    |    | |         |    |    |
  `-------------------------------------------------------------------------' `--------------' `-------------------'

  Foot switches:
                  ,--------.         ,--------.
                  |        |         |        |
                  |        |         |        |
                  `--------'         `--------'
*/ \
KEYMAP_COMMON(\
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, RESET, _______, _______, _______, _______, _______, _______, _______, \
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
    _______, F(common_fn_next_default_layer), _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
    _______, _______)
#endif

#define DEFINE_COMMON_LAYERS() \
\
/* Keymap common_layer_default_basic: Default layer (Windows)

  ,----.    ,-------------------. ,-------------------. ,-------------------. ,--------------.
  |Esc |    | F1 | F2 | F3 | F4 | | F5 | F6 | F7 | F8 | | F9 | F10| F11| F12| |PrSc|ScLk|Paus|
  `----'    `-------------------' `-------------------' `-------------------' `--------------'
  ,-------------------------------------------------------------------------. ,--------------. ,-------------------.
  |Esc~| 1  | 2  | 3  | 4  | 5  | 6  | 7  | 8  | 9  | 0  | -  | =  | Backsp | |Ins |Home|PgUp| |    |    |    |    |
  |-------------------------------------------------------------------------| |--------------| |-------------------|
  | Tab  | Q  | W  | E  | R  | T  | Y  | U  | I  | O  | P  | [  | ]  |  \|  | |Del |End |PgDn| |    |    |    |    |
  |-------------------------------------------------------------------------| '--------------' |--------------     |
  | Caps  | A  | S  | D  | F  | G  | H  | J  | K  | L  | ;  | '  |   Enter  |                  |    |    |    |    |
  |-------------------------------------------------------------------------|      ,----.      |-------------------|
  | Shift   | Z  | X  | C  | V  | B  | N  | M  | ,  | .  | /  |       Shift |      | Up |      |    |    |    |    ß|
  |-------------------------------------------------------------------------| ,--------------. |--------------     |
  |Ctrl|Gui |Alt |                                      |Alt |FNEX|App |Ctrl| |Left|Down|Rght| |         |    |    |
  `-------------------------------------------------------------------------' `--------------' `-------------------'

  Foot switches:
                  ,--------.         ,--------.
                  |        |         |        |
                  |   FN   |         |        |
                  `--------'         `--------'
*/ \
[common_layer_default_basic] = KEYMAP_COMMON(\
       KC_ESC,  KC_F1,  KC_F2,  KC_F3,  KC_F4,  KC_F5,  KC_F6,  KC_F7,  KC_F8,  KC_F9, KC_F10, KC_F11, KC_F12,          KC_PSCR,TG(common_layer_numpad),KC_PAUS,                        \
       KC_GRV,   KC_1,   KC_2,   KC_3,   KC_4,   KC_5,   KC_6,   KC_7,   KC_8,   KC_9,   KC_0,KC_MINS, KC_EQL,KC_BSPC,   KC_INS,KC_HOME,KC_PGUP,  KC_NLCK,KC_PSLS,KC_PAST,KC_PMNS, \
       KC_TAB,   KC_Q,   KC_W,   KC_E,   KC_R,   KC_T,   KC_Y,   KC_U,   KC_I,   KC_O,   KC_P,KC_LBRC,KC_RBRC,KC_BSLS,   KC_DEL, KC_END,KC_PGDN,    KC_P7,  KC_P8,  KC_P9,KC_PPLS, \
      KC_CAPS,   KC_A,   KC_S,   KC_D,   KC_F,   KC_G,   KC_H,   KC_J,   KC_K,   KC_L,KC_SCLN,KC_QUOT,         KC_ENT,                              KC_P4,  KC_P5,  KC_P6,      \
      KC_LSFT,KC_NUBS,   KC_Z,   KC_X,   KC_C,   KC_V,   KC_B,   KC_N,   KC_M,KC_COMM, KC_DOT,KC_SLSH,        KC_RSFT,            KC_UP,            KC_P1,  KC_P2,  KC_P3,KC_PENT, \
      KC_LCTL,KC_LGUI,KC_LALT,                 KC_SPC,                                KC_RALT,MO(common_layer_fn_ext), KC_APP,KC_RCTL,  KC_LEFT,KC_DOWN,KC_RGHT,    KC_P0,KC_PDOT, \
      _______, _______), \
\
/* Keymap common_layer_default_windows: Default layer (Windows)

  ,----.    ,-------------------. ,-------------------. ,-------------------. ,--------------.
  |Esc |    | F1 | F2 | F3 | F4 | | F5 | F6 | F7 | F8 | | F9 | F10| F11| F12| |PrSc|ScLk|Paus|
  `----'    `-------------------' `-------------------' `-------------------' `--------------'
  ,-------------------------------------------------------------------------. ,--------------. ,-------------------.
  |Esc~| 1  | 2  | 3  | 4  | 5  | 6  | 7  | 8  | 9  | 0  | -  | =  | Backsp | |Ins |Home|PgUp| |    |    |    |    |
  |-------------------------------------------------------------------------| |--------------| |-------------------|
  | Tab  | Q  | W  | E  | R  | T  | Y  | U  | I  | O  | P  | [  | ]  |  \|  | |Del |End |PgDn| |    |    |    |    |
  |-------------------------------------------------------------------------| '--------------' |--------------     |
  |  FN   | A  | S  | D  | F  | G  | H  | J  | K  | L  | ;  | '  |   Enter  |                  |    |    |    |    |
  |-------------------------------------------------------------------------|      ,----.      |-------------------|
  | Shift   | Z  | X  | C  | V  | B  | N  | M  | ,  | .  | /  |       Shift |      | Up |      |    |    |    |    |
  |-------------------------------------------------------------------------| ,--------------. |--------------     |
  |Ctrl|Gui |Alt |                                      |FNOS|FNEX| FN |Ctrl| |Left|Down|Rght| |         |    |    |
  `-------------------------------------------------------------------------' `--------------' `-------------------'

  Foot switches:
                  ,--------.         ,--------.
                  |        |         |        |
                  |   FN   |         |        |
                  `--------'         `--------'
*/ \
[common_layer_default_windows] = KEYMAP_COMMON(\
       KC_ESC,  KC_F1,  KC_F2,  KC_F3,  KC_F4,  KC_F5,  KC_F6,  KC_F7,  KC_F8,  KC_F9, KC_F10, KC_F11, KC_F12,          KC_PSCR,TG(common_layer_numpad),KC_PAUS,                        \
       F(common_fn_shift_esc),   KC_1,   KC_2,   KC_3,   KC_4,   KC_5,   KC_6,   KC_7,   KC_8,   KC_9,   KC_0,KC_MINS, KC_EQL,KC_BSPC,   KC_INS,KC_HOME,KC_PGUP,  KC_NLCK,KC_PSLS,KC_PAST,KC_PMNS, \
       KC_TAB,   KC_Q,   KC_W,   KC_E,   KC_R,   KC_T,   KC_Y,   KC_U,   KC_I,   KC_O,   KC_P,KC_LBRC,KC_RBRC,KC_BSLS,   KC_DEL, KC_END,KC_PGDN,    KC_P7,  KC_P8,  KC_P9,KC_PPLS, \
      MO(common_layer_fn),   KC_A,   KC_S,   KC_D,   KC_F,   KC_G,   KC_H,   KC_J,   KC_K,   KC_L,KC_SCLN,KC_QUOT,         KC_ENT,                              KC_P4,  KC_P5,  KC_P6,      \
      KC_LSFT,KC_NUBS,   KC_Z,   KC_X,   KC_C,   KC_V,   KC_B,   KC_N,   KC_M,KC_COMM, KC_DOT,KC_SLSH,        KC_RSFT,            KC_UP,            KC_P1,  KC_P2,  KC_P3,KC_PENT, \
      KC_LCTL,KC_LGUI,KC_LALT,                 KC_SPC,                                MO(common_layer_gui_windows),MO(common_layer_fn_ext), MO(common_layer_fn),KC_RCTL,  KC_LEFT,KC_DOWN,KC_RGHT,    KC_P0,KC_PDOT, \
      MO(common_layer_fn), KC_LSFT), \
\
[common_layer_default_mac] = DEFINE_COMMON_LAYER_DEFAULT_MAC(), \
\
/* Keymap common_layer_fn: Function Layer

  ,----.    ,-------------------. ,-------------------. ,-------------------. ,--------------.
  |    |    |    |    |    |    | |    |    |    |    | |    |    |    |    | |    |    |    |
  `----'    `-------------------' `-------------------' `-------------------' `--------------'
  ,-------------------------------------------------------------------------. ,--------------. ,-------------------.
  | `  | F1 | F2 | F3 | F4 | F5 | F6 | F7 | F8 | F9 | F10| F11| F12|  Del   | |    |    |    | |    |    |    |    |
  |-------------------------------------------------------------------------| |--------------| |-------------------|
  |      |Home| Up |End |PgUp|    |PgUp|Home| Up |End |    |PrSc|ScLk|Pause | |    |    |    | |    |    |    |    |
  |-------------------------------------------------------------------------| '--------------' |--------------     |
  |       |Left|Down|Rght|PgDn|    |PgDn|Left|Down|Rght|    |Ins | >>Numpad |                  |    |    |    |    |
  |-------------------------------------------------------------------------|      ,----.      |-------------------|
  |         |    |    |    |    |    |Mute|Vol-|Vol+|Skp-|Skp+|             |      |    |      |    |    |    |    |
  |-------------------------------------------------------------------------| ,--------------. |--------------     |
  |    |    |    |              Play/Pause              |    |    |    |CAPS| |    |    |    | |         |    |    |
  `-------------------------------------------------------------------------' `--------------' `-------------------'

  Foot switches:
                  ,--------.         ,--------.
                  |        |         |        |
                  |        |         |        |
                  `--------'         `--------'
*/ \
[common_layer_fn] = KEYMAP_COMMON(\
    _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_NLCK, _______, _______, _______, _______, _______, _______, \
    KC_GRV,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_DEL,  _______, _______, _______, _______, _______, _______, _______, \
    _______, KC_HOME, KC_UP,   KC_END,  KC_PGUP, _______, KC_PGUP, KC_HOME, KC_UP,   KC_END,  _______, KC_PSCR, KC_SLCK, KC_PAUS, _______, _______, _______, _______, _______, _______, _______, \
    _______, KC_LEFT, KC_DOWN, KC_RGHT, KC_PGDN, _______, KC_PGDN, KC_LEFT, KC_DOWN, KC_RGHT, _______, KC_INS,  TG(common_layer_numpad), _______, _______, _______, \
    _______, _______, _______, _______, _______, _______, KC_MUTE, KC_VOLD, KC_VOLU, KC_MPRV, KC_MNXT, _______, _______, _______, _______, _______, _______, _______, \
    _______, _______, _______, KC_MPLY, _______, _______, _______, KC_CAPS, _______, _______, _______, _______, _______, \
    _______, _______), \
\
[common_layer_fn_ext] = DEFINE_COMMON_LAYER_FN_EXT(), \
\
/* Keymap common_layer_numpad: Numpad Layer

  ,----.    ,-------------------. ,-------------------. ,-------------------. ,--------------.
  |    |    |    |    |    |    | |    |    |    |    | |    |    |    |    | |    |    |    |
  `----'    `-------------------' `-------------------' `-------------------' `--------------'
  ,-------------------------------------------------------------------------. ,--------------. ,-------------------.
  |    |    |    |    |    |    |    |    |    |    |    |    |    |        | |    |    |    | |    |    |    |    |
  |-------------------------------------------------------------------------| |--------------| |-------------------|
  |      |    |    |    |    |    |    |    | 7  | 8  | 9  |    |    |      | |    |    |    | |    |    |    |    |
  |-------------------------------------------------------------------------| '--------------' |--------------     |
  |       |    |    |    |    |    |    |    | 4  | 5  | 6  |    |          |                  |    |    |    |    |
  |-------------------------------------------------------------------------|      ,----.      |-------------------|
  |         |    |    |    |    |    |    |    | 1  | 2  | 3  |             |      |    |      |    |    |    |    |
  |-------------------------------------------------------------------------| ,--------------. |--------------     |
  |    |    |    |                   0                  | 0  | .  |    |    | |    |    |    | |         |    |    |
  `-------------------------------------------------------------------------' `--------------' `-------------------'

  Foot switches:
                  ,--------.         ,--------.
                  |        |         |        |
                  |        |         |        |
                  `--------'         `--------'
*/ \
[common_layer_numpad] = KEYMAP_COMMON(\
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
    _______, _______, _______, _______, _______, _______, _______, _______, KC_P7, KC_P8, KC_P9, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
    _______, _______, _______, _______, _______, _______, _______, _______, KC_P4, KC_P5, KC_P6, _______, _______, _______, _______, _______, \
    _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_P1, KC_P2, KC_P3, _______, _______, _______, _______, _______, _______, \
    _______, _______, _______, KC_P0, KC_P0, KC_PDOT, _______, _______, _______, _______, _______, _______, _______, \
    _______, _______), \
\
/* Keymap common_layer_gui_windows: GUI layer (Windows)

  ,----.    ,-------------------. ,-------------------. ,-------------------. ,--------------.
  |Lock|    |    |    |    |    | |    |    |    |    | |    |    |    |    | |    |    |    |
  `----'    `-------------------' `-------------------' `-------------------' `--------------'
  ,-------------------------------------------------------------------------. ,--------------. ,-------------------.
  |Lock|    |    |    |    |    |    |    |    |    |    |KVM1|KVM2| Close  | |    |    |    | |    |    |    |    |
  |-------------------------------------------------------------------------| |--------------| |-------------------|
  |      |    |    |Mail|    |    |    |    |    |    |    |Dsk-|Dsk+|TaskSw| |    |    |    | |    |    |    |    |
  |-------------------------------------------------------------------------| '--------------' |--------------     |
  |       |    |    |    |    |    |    |    |    |    |SnpL|SnpR| Maximize |                  |    |    |    |    |
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
[common_layer_gui_windows] = KEYMAP_COMMON(\
    LGUI(KC_L), _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
    LGUI(KC_L), _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, M(common_macro_kvm1), M(common_macro_kvm2), LALT(KC_F4), _______, _______, _______, _______, _______, _______, _______, \
    _______, _______, _______, F(common_fn_email_enable), _______, _______, _______, _______, _______, _______, _______, LCTL(LGUI(KC_LEFT)), LCTL(LGUI(KC_RGHT)), F(common_fn_windows_task_switch_enable), _______, _______, _______, _______, _______, _______, _______, \
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, LGUI(KC_LEFT), LGUI(KC_RGHT), LGUI(KC_UP), _______, _______, _______, \
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
    _______, _______), \
\
/* Keymap common_layer_gui_windows_task_switch: GUI Layer for Windows Task Switcher

  ,----.    ,-------------------. ,-------------------. ,-------------------. ,--------------.
  |Exit|    |    |    |    |    | |    |    |    |    | |    |    |    |    | |    |    |    |
  `----'    `-------------------' `-------------------' `-------------------' `--------------'
  ,-------------------------------------------------------------------------. ,--------------. ,-------------------.
  |Exit|    |    |    |    |    |    |    |    |    |    |    |    |        | |    |    |    | |    |    |    |    |
  |-------------------------------------------------------------------------| |--------------| |-------------------|
  |      |    |    |    |    |    |    |    |    |    |    |Prev|Next|Select| |    |    |    | |    |    |    |    |
  |-------------------------------------------------------------------------| '--------------' |--------------     |
  |       |    |    |    |    |    |Next|Prev|    |    |    |    |  Select  |                  |    |    |    |    |
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
[common_layer_gui_windows_task_switch] = KEYMAP_COMMON(\
    F(common_fn_windows_task_switch_cancel), XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
    F(common_fn_windows_task_switch_cancel), XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, LSFT(KC_TAB), KC_TAB, F(common_fn_windows_task_switch_select), XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_TAB, LSFT(KC_TAB), XXXXXXX, XXXXXXX, XXXXXXX, F(common_fn_windows_task_switch_select), XXXXXXX, XXXXXXX, XXXXXXX, \
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
    XXXXXXX, XXXXXXX, XXXXXXX, F(common_fn_windows_task_switch_select), XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
    XXXXXXX, XXXXXXX), \
\
/* Keymap common_layer_default_mac: GUI layer (Mac)

  ,----.    ,-------------------. ,-------------------. ,-------------------. ,--------------.
  |Pwr |    |    |    |    |    | |    |    |    |    | |    |    |    |    | |    |    |    |
  `----'    `-------------------' `-------------------' `-------------------' `--------------'
  ,-------------------------------------------------------------------------. ,--------------. ,-------------------.
  |Pwr |    |    |    |    |    |    |    |    |    |    |    |    | Close  | |    |    |    | |    |    |    |    |
  |-------------------------------------------------------------------------| |--------------| |-------------------|
  |      |    |    |    |    |    |    |    |    |    |    |Dsk-|Dsk+|TaskSw| |    |    |    | |    |    |    |    |
  |-------------------------------------------------------------------------| '--------------' |--------------     |
  |       |    |    |    |    |    |    |    |    |    |SnpL|SnpR| Maximize |                  |    |    |    |    |
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
[common_layer_gui_mac] = KEYMAP_COMMON(\
    KC_PWR, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
    KC_PWR, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, LGUI(KC_W), _______, _______, _______, _______, _______, _______, _______, \
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, LCTL(KC_LEFT), LCTL(KC_RGHT), F(common_fn_mac_task_switch_enable), _______, _______, _______, _______, _______, _______, _______, \
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, LCAG(KC_LEFT), LCAG(KC_RGHT), LCAG(KC_M), _______, _______, _______, \
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
    _______, _______), \
\
/* Keymap common_layer_gui_mac_task_switch: GUI Layer for Mac Task Switcher

  ,----.    ,-------------------. ,-------------------. ,-------------------. ,--------------.
  |Exit|    |    |    |    |    | |    |    |    |    | |    |    |    |    | |    |    |    |
  `----'    `-------------------' `-------------------' `-------------------' `--------------'
  ,-------------------------------------------------------------------------. ,--------------. ,-------------------.
  |Exit|    |    |    |    |    |    |    |    |    |    |    |    |        | |    |    |    | |    |    |    |    |
  |-------------------------------------------------------------------------| |--------------| |-------------------|
  |      |    |    |    |    |    |    |    |    |    |    |Prev|Next|Select| |    |    |    | |    |    |    |    |
  |-------------------------------------------------------------------------| '--------------' |--------------     |
  |       |    |    |    |    |    |Next|Prev|    |    |    |    |  Select  |                  |    |    |    |    |
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
[common_layer_gui_mac_task_switch] = KEYMAP_COMMON(\
    F(common_fn_mac_task_switch_cancel), XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
    F(common_fn_mac_task_switch_cancel), XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, LSFT(KC_TAB), KC_TAB, F(common_fn_mac_task_switch_select), XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_TAB, LSFT(KC_TAB), XXXXXXX, XXXXXXX, XXXXXXX, F(common_fn_mac_task_switch_select), XXXXXXX, XXXXXXX, XXXXXXX, \
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
    XXXXXXX, XXXXXXX, XXXXXXX, F(common_fn_mac_task_switch_select), XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
    XXXXXXX, XXXXXXX), \
\
/* Keymap common_layer_email: GUI Layer for email management

  ,----.    ,-------------------. ,-------------------. ,-------------------. ,--------------.
  |Exit|    |    |    |    |    | |    |    |    |    | |    |    |    |    | |    |    |    |
  `----'    `-------------------' `-------------------' `-------------------' `--------------'
  ,-------------------------------------------------------------------------. ,--------------. ,-------------------.
  |Exit|    |    |    |    |    |    |    |    |    |    |    |    |        | |    |    |    | |    |    |    |    |
  |-------------------------------------------------------------------------| |--------------| |-------------------|
  |      |    |    |    |Rply|    |    |    |    |    |    |    |    |      | |    |    |    | |    |    |    |    |
  |-------------------------------------------------------------------------| '--------------' |--------------     |
  |       |Arch|Stky|Del |    |Acco|    |Next|Prev|Expd|Coll|    |          |                  |    |    |    |    |
  |-------------------------------------------------------------------------|      ,----.      |-------------------|
  |         |Undo|    |    |    |    |New |    |    |    |    |             |      |Prev|      |    |    |    |    |
  |-------------------------------------------------------------------------| ,--------------. |--------------     |
  |    |    |    |                                      |    |    |    |    | |Coll|Next|Expd| |         |    |    |
  `-------------------------------------------------------------------------' `--------------' `-------------------'

  Foot switches:
                  ,--------.         ,--------.
                  |        |         |        |
                  |        |         |        |
                  `--------'         `--------'
*/ \
[common_layer_email] = KEYMAP_COMMON(\
    F(common_fn_email_cancel), XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
    F(common_fn_email_cancel), XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
    XXXXXXX, F(common_fn_email_hide_ui), F(common_fn_email_show_ui), XXXXXXX, F(common_fn_email_reply), XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
    XXXXXXX, LCTL(LSFT(KC_1)), LCTL(LSFT(KC_4)), LCTL(KC_D), F(common_fn_email_forward), LCTL(LSFT(KC_3)), XXXXXXX, KC_DOWN, KC_UP, KC_RGHT, KC_LEFT, XXXXXXX, F(common_fn_email_open), XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
    XXXXXXX, LCTL(KC_Z), XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, F(common_fn_email_new), XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_UP, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_LEFT, KC_DOWN, KC_RGHT, XXXXXXX, XXXXXXX, \
    XXXXXXX, XXXXXXX)

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


#define DEFINE_COMMON_FN_ACTIONS() \
  [common_fn_shift_esc] = ACTION_FUNCTION(common_fn_shift_esc), \
  [common_fn_next_default_layer] = ACTION_FUNCTION(common_fn_next_default_layer), \
  [common_fn_windows_task_switch_enable] = ACTION_FUNCTION(common_fn_windows_task_switch_enable), \
  [common_fn_windows_task_switch_select] = ACTION_FUNCTION(common_fn_windows_task_switch_select), \
  [common_fn_windows_task_switch_cancel] = ACTION_FUNCTION(common_fn_windows_task_switch_cancel), \
  [common_fn_mac_task_switch_enable] = ACTION_FUNCTION(common_fn_mac_task_switch_enable), \
  [common_fn_mac_task_switch_select] = ACTION_FUNCTION(common_fn_mac_task_switch_select), \
  [common_fn_mac_task_switch_cancel] = ACTION_FUNCTION(common_fn_mac_task_switch_cancel), \
  [common_fn_email_enable] = ACTION_FUNCTION(common_fn_email_enable), \
  [common_fn_email_reply] = ACTION_FUNCTION(common_fn_email_reply), \
  [common_fn_email_forward] = ACTION_FUNCTION(common_fn_email_forward), \
  [common_fn_email_new] = ACTION_FUNCTION(common_fn_email_new), \
  [common_fn_email_open] = ACTION_FUNCTION(common_fn_email_open), \
  [common_fn_email_hide_ui] = ACTION_FUNCTION(common_fn_email_hide_ui), \
  [common_fn_email_show_ui] = ACTION_FUNCTION(common_fn_email_show_ui), \
  [common_fn_email_cancel] = ACTION_FUNCTION(common_fn_email_cancel)

// Common modifier masks
#define MODS_SHIFT_MASK  (MOD_BIT(KC_LSHIFT)|MOD_BIT(KC_RSHIFT))

// used for common_fn_next_default_layer
extern uint32_t default_layer_state;
#define MAX_DEFAULT_LAYER_STATE (1UL << common_layer_default_max)

void persistent_default_layer_set(uint16_t default_layer)
{
    eeconfig_update_default_layer(default_layer);
    default_layer_set(default_layer);
}

void common_action_email_cancel(void)
{
    dprintf("Email layer off. layer state=0x%08X\n", layer_state);
    layer_off(common_layer_email);
    layer_off(common_layer_gui_windows);
}

bool common_action_function(keyrecord_t* record, uint8_t id, uint8_t opt) {
    const uint8_t shift_pressed = get_mods() & MODS_SHIFT_MASK;
    switch (id) {
        case common_fn_shift_esc:
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
            return true;
        }
        case common_fn_next_default_layer:
        {
            if (record->event.pressed)
            {
                if (default_layer_state == 0)
                {
                    default_layer_state = 1;
                }
                default_layer_state = (default_layer_state << 1) & ~(1UL << common_layer_default_max);
                dprintf("default_layer_state: 0x%08X\n", default_layer_state);
                persistent_default_layer_set(default_layer_state);
            }
            return true;
        }
        case common_fn_windows_task_switch_enable:
        {
            if (record->event.pressed)
            {
                register_code(KC_LALT);
                register_code(KC_TAB);
                unregister_code(KC_TAB);
                layer_on(common_layer_gui_windows_task_switch);
            }

            return true;
        }
        case common_fn_windows_task_switch_select:
        {
            if (record->event.pressed)
            {
                unregister_code(KC_LALT);
                layer_off(common_layer_gui_windows_task_switch);
                layer_off(common_layer_gui_windows);
            }

            return true;
        }
        case common_fn_windows_task_switch_cancel:
        {
            if (record->event.pressed)
            {
                add_key(KC_ESC);
                send_keyboard_report();
                unregister_code(KC_LALT);
                layer_off(common_layer_gui_windows_task_switch);
                layer_off(common_layer_gui_windows);
            }

            return true;
        }
        case common_fn_mac_task_switch_enable:
        {
            if (record->event.pressed)
            {
                register_code(KC_LGUI);
                register_code(KC_TAB);
                unregister_code(KC_TAB);
                layer_on(common_layer_gui_mac_task_switch);
            }

            return true;
        }
        case common_fn_mac_task_switch_select:
        {
            if (record->event.pressed)
            {
                unregister_code(KC_LGUI);
                layer_off(common_layer_gui_mac_task_switch);
                layer_off(common_layer_gui_mac);
            }

            return true;
        }
        case common_fn_mac_task_switch_cancel:
        {
            if (record->event.pressed)
            {
                add_key(KC_ESC);
                send_keyboard_report();
                unregister_code(KC_LGUI);
                layer_off(common_layer_gui_mac_task_switch);
                layer_off(common_layer_gui_mac);
            }

            return true;
        }
        case common_fn_email_enable:
        {
            if (record->event.pressed)
            {
                dprintf("Email layer on. layer state=0x%08X\n", layer_state);

                // Switch to outbox, then inbox (Ctrl+Shift+O, Ctrl+Shift+I)
                register_code(KC_LCTL);
                register_code(KC_LSHIFT);
                register_code(KC_O);
                unregister_code(KC_O);
                register_code(KC_I);
                unregister_code(KC_I);
                unregister_code(KC_LSHIFT);
                unregister_code(KC_LCTL);

                // check for new messages (Ctrl+M)
                register_code(KC_LCTL);
                register_code(KC_M);
                unregister_code(KC_M);
                unregister_code(KC_LCTL);

                layer_on(common_layer_email);
            }

            return true;
        }
        case common_fn_email_reply:
        {
            if (record->event.pressed)
            {
                // Reply and delete (Ctrl+Shift+2)
                register_code(KC_LCTL);
                register_code(KC_LSHIFT);
                register_code(KC_2);
                unregister_code(KC_2);
                unregister_code(KC_LSHIFT);
                unregister_code(KC_LCTL);

                common_action_email_cancel();
            }

            return true;
        }
        case common_fn_email_forward:
        {
            if (record->event.pressed)
            {
                // Forward and delete (Ctrl+Shift+5)
                register_code(KC_LCTL);
                register_code(KC_LSHIFT);
                register_code(KC_5);
                unregister_code(KC_5);
                unregister_code(KC_LSHIFT);
                unregister_code(KC_LCTL);

                common_action_email_cancel();
            }

            return true;
        }
        case common_fn_email_new:
        {
            if (record->event.pressed)
            {
                // Create new email (Ctrl+Shift+M)
                register_code(KC_LCTL);
                register_code(KC_LSHIFT);
                register_code(KC_M);
                unregister_code(KC_M);
                unregister_code(KC_LSHIFT);
                unregister_code(KC_LCTL);

                common_action_email_cancel();
            }

            return true;
        }
        case common_fn_email_open:
        {
            if (record->event.pressed)
            {
                // Open current email (Ctrl+O)
                register_code(KC_LCTL);
                register_code(KC_O);
                unregister_code(KC_O);
                unregister_code(KC_LCTL);

                common_action_email_cancel();
            }

            return true;
        }
        case common_fn_email_hide_ui:
        {
            if (record->event.pressed)
            {
                // Assumes folder pane and ribbon are fully visible

                // Toggle ribbon (Ctrl+F1)
                register_code(KC_LCTL);
                register_code(KC_F1);
                unregister_code(KC_F1);
                unregister_code(KC_LCTL);

                // Toggle folder pane 2x (Alt+F1)
                register_code(KC_LALT);
                register_code(KC_F1);
                unregister_code(KC_F1);
                register_code(KC_F1);
                unregister_code(KC_F1);
                unregister_code(KC_LALT);
            }

            return true;
        }
        case common_fn_email_show_ui:
        {
            if (record->event.pressed)
            {
                // Assumes folder pane and ribbon are hidden

                // Toggle ribbon (Ctrl+F1)
                register_code(KC_LCTL);
                register_code(KC_F1);
                unregister_code(KC_F1);
                unregister_code(KC_LCTL);

                // Toggle folder pane 1x (Alt+F1)
                register_code(KC_LALT);
                register_code(KC_F1);
                unregister_code(KC_F1);
                unregister_code(KC_LALT);
            }

            return true;
        }
        case common_fn_email_cancel:
        {
            if (record->event.pressed)
            {
                common_action_email_cancel();
            }

            return true;
        }
    }

    return false;
}

const macro_t* common_action_get_macro(keyrecord_t* record, uint8_t id, uint8_t opt) {
    switch(id)
    {
        case common_macro_kvm1:
        {
            if (record->event.pressed)
            {
                return MACRO( I(20),
                    T(RCTL), T(RCTL),
                    T(1),
                    T(ENT),
                    END );
            }
            break;
        }
        case common_macro_kvm2:
        {
            if (record->event.pressed)
            {
                return MACRO( I(20),
                    T(RCTL), T(RCTL),
                    T(2),
                    T(ENT),
                    END );
            }
            break;
        }
    };

    return MACRO_NONE;
}

#endif // __COMMON_KEYMAP_H__