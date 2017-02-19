#include "satan.h"
#include "process_midi.h"
#include "rgblight.h"

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
    _GL_WINDOWS,
    _GL_WINDOWS_TASKSWITCH,
    _GL_MAC,
    _GL_MAC_TASKSWITCH,
    _ML,
    _ML_ONSTAGE,
};

enum function_id {
    SHIFT_ESC,
    NEXT_DEFAULT_LAYER,
    WINDOWS_TASKSWITCH_ENABLE,
    WINDOWS_TASKSWITCH_SELECT,
    WINDOWS_TASKSWITCH_CANCEL,
    MAC_TASKSWITCH_ENABLE,
    MAC_TASKSWITCH_SELECT,
    MAC_TASKSWITCH_CANCEL,
    ONSTAGE_ENABLE,
    ONSTAGE_PLAYSTOP,
    ONSTAGE_STOP,
    ONSTAGE_SELECT_SONG,
    ONSTAGE_SELECT_SONG_1 = ONSTAGE_SELECT_SONG,
    ONSTAGE_SELECT_SONG_2,
    ONSTAGE_SELECT_SONG_3,
    ONSTAGE_SELECT_SONG_4,
    ONSTAGE_SELECT_SONG_5,
    ONSTAGE_SELECT_SONG_6,
    ONSTAGE_SELECT_SONG_7,
    ONSTAGE_SELECT_SONG_8,
    ONSTAGE_SELECT_SONG_9,
    ONSTAGE_SELECT_SONG_10,
    ONSTAGE_BRIGHTNESS,
    ONSTAGE_BRIGHTD = ONSTAGE_BRIGHTNESS,
    ONSTAGE_BRIGHTU,
};

enum macro_id {
    SD_SUBMIT_YOLO,
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
  KC_LCTL, KC_LGUI, KC_LALT,                           KC_SPC,                             MO(_GL_WINDOWS), MO(_RL), MO(_FL), KC_RCTL, \
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
   * |       |    |    |    |    |    |    |    |    |    |    |    |>>MIDI   |
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
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          TG(_ML), \
  _______, RGB_TOG, RGB_MOD, RGB_HUI, RGB_HUD, RGB_SAI, RGB_SAD, RGB_VAI, RGB_VAD, _______, _______,                   _______, \
  _______, F(NEXT_DEFAULT_LAYER), _______,                _______,                          _______, _______, _______, _______, \
  _______, _______
  #else
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, RESET,   \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, BL_DEC,  BL_INC,  BL_TOGG, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          TG(_ML), \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,                   _______, \
  _______, F(NEXT_DEFAULT_LAYER), _______,                _______,                          _______, _______, _______, _______, \
  _______, _______
  #endif
  ),

/* Keymap _GL_WINDOWS: GUI Layer for Windows
   * ,------------------------------------------------------------------------.
   * |Lock|    |    |    |    |    |    |    |    |    |    |    |    | Close |
   * |------------------------------------------------------------------------|
   * |      |    |    |    |    |    |    |    |    |    |    |Dsk-|Dsk+| Task|
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
[_GL_WINDOWS] = KEYMAP_ANSI_FOOTSWITCHES(
  LGUI(KC_L), M(SD_SUBMIT_YOLO), _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, LALT(KC_F4), \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, LCTL(LGUI(KC_LEFT)), LCTL(LGUI(KC_RGHT)), F(WINDOWS_TASKSWITCH_ENABLE), \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, LGUI(KC_LEFT), LGUI(KC_RGHT), LGUI(KC_UP), \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,                   _______, \
  _______, _______, _______,                          _______,                              _______, _______, _______, _______, \
  _______, _______), 

/* Keymap _GL_WINDOWS_TASKSWITCH: GUI Layer for Windows Task Switcher
   * ,------------------------------------------------------------------------.
   * |Cancel|    |    |    |    |    |    |    |    |    |    |    |    |     |
   * |------------------------------------------------------------------------|
   * |      |    |    |    |    |    |    |    |    |    |    |Prev|Next| Sel |
   * |------------------------------------------------------------------------|
   * |       |    |    |    |    |    |Next|Prev|    |    |    |    |  Select |
   * |------------------------------------------------------------------------|
   * |         |    |    |    |    |    |    |    |    |    |    |            |
   * |------------------------------------------------------------------------|
   * |     |     |     |            Select            |     |     |     |     |
   * `------------------------------------------------------------------------'
   *
   * Foot switches:
   *                ,--------.         ,--------.
   *                |        |         |        |
   *                |        |         |        |
   *                `--------'         `--------'
   */
[_GL_WINDOWS_TASKSWITCH] = KEYMAP_ANSI_FOOTSWITCHES(
  F(WINDOWS_TASKSWITCH_CANCEL), XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, LSFT(KC_TAB), KC_TAB, F(WINDOWS_TASKSWITCH_SELECT), \
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_TAB, LSFT(KC_TAB), XXXXXXX, XXXXXXX, XXXXXXX,          F(WINDOWS_TASKSWITCH_SELECT), \
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, \
  XXXXXXX, XXXXXXX, XXXXXXX,                          F(WINDOWS_TASKSWITCH_SELECT),                XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
  XXXXXXX, XXXXXXX),


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
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, LCTL(KC_LEFT), LCTL(KC_RGHT), F(MAC_TASKSWITCH_ENABLE), \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, LCAG(KC_LEFT), LCAG(KC_RGHT), LCAG(KC_M), \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,                   _______, \
  _______, _______, _______,                          _______,                              _______, _______, _______, _______, \
  _______, _______), 

/* Keymap _GL_MAC_TASKSWITCH: GUI Layer for Mac Task Switcher
   * ,------------------------------------------------------------------------.
   * |Cancel|    |    |    |    |    |    |    |    |    |    |    |    |     |
   * |------------------------------------------------------------------------|
   * |      |    |    |    |    |    |    |    |    |    |    |Prev|Next| Sel |
   * |------------------------------------------------------------------------|
   * |       |    |    |    |    |    |Next|Prev|    |    |    |    |  Select |
   * |------------------------------------------------------------------------|
   * |         |    |    |    |    |    |    |    |    |    |    |            |
   * |------------------------------------------------------------------------|
   * |     |     |     |            Select            |     |     |     |     |
   * `------------------------------------------------------------------------'
   *
   * Foot switches:
   *                ,--------.         ,--------.
   *                |        |         |        |
   *                |        |         |        |
   *                `--------'         `--------'
   */
[_GL_MAC_TASKSWITCH] = KEYMAP_ANSI_FOOTSWITCHES(
  F(MAC_TASKSWITCH_CANCEL), XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, LSFT(KC_TAB), KC_TAB, F(MAC_TASKSWITCH_SELECT), \
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_TAB, LSFT(KC_TAB), XXXXXXX, XXXXXXX, XXXXXXX,          F(MAC_TASKSWITCH_SELECT), \
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, \
  XXXXXXX, XXXXXXX, XXXXXXX,                          F(MAC_TASKSWITCH_SELECT),                XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
  XXXXXXX, XXXXXXX),

/* Keymap _ML: MIDI Layer
   * ,------------------------------------------------------------------------.
   * | Exit |    |    |    |    |    |    |    |    |    |    |    |    |     |
   * |------------------------------------------------------------------------|
   * |  Ch+ |    | C# | D# |    | F# | G# | A# |    | C# | D# |    |    |     |
   * |------------------------------------------------------------------------|
   * |  Mod  | C  | D  | E  | F  | G  | A  | B  | C  | D  | E  | F  |>>OnStage|
   * |------------------------------------------------------------------------|
   * | Sustain |Oct-|Oct+|Mod-|Mod+|    |    |    |Tns-|Tns+|Tns0|   Sustain  |
   * |------------------------------------------------------------------------|
   * |     |     |     |         All notes off        |     |     |     |     |
   * `------------------------------------------------------------------------'
   *
   * Foot switches:
   *                ,--------.         ,--------.
   *                |        |         |        |
   *                |        |         |        |
   *                `--------'         `--------'
   */

[_ML] = KEYMAP_ANSI_FOOTSWITCHES(
  TG(_ML), MI_VEL_1, MI_VEL_2, MI_VEL_3, MI_VEL_4, MI_VEL_5, MI_VEL_6, MI_VEL_7, MI_VEL_8, MI_VEL_9, MI_VEL_10, XXXXXXX, XXXXXXX, XXXXXXX, \
  MI_CHU,  XXXXXXX, MI_Cs,   MI_Ds,   XXXXXXX, MI_Fs,   MI_Gs,   MI_As,   XXXXXXX, MI_Cs_1, MI_Ds_1, XXXXXXX, XXXXXXX, XXXXXXX, \
  MI_MOD,  MI_C,    MI_D,    MI_E,    MI_F,    MI_G,    MI_A,    MI_B,    MI_C_1,  MI_D_1,  MI_E_1,  MI_F_1,           F(ONSTAGE_ENABLE), \
  MI_SUS,  MI_OCTD, MI_OCTU, MI_MODSD, MI_MODSU, XXXXXXX, XXXXXXX, XXXXXXX, MI_TRNSD, MI_TRNSU, MI_TRNS_0,             MI_SUS, \
  _______, _______, _______,                          MI_OFF,                               _______, _______, _______, _______, \
  _______, _______),

/* Keymap _ML_ONSTAGE: MIDI Layer for performance on stage
   * ,------------------------------------------------------------------------.
   * | Exit | C  | C# | D  | D# | E  | F  | F# | G  | G# | A  |    |    |     |
   * |------------------------------------------------------------------------|
   * |      |    |    |    |    |    |    |    |    |    |    |    |    |     |
   * |------------------------------------------------------------------------|
   * |       |    |    |    |    |    |    |    |    |    |    |    |         |
   * |------------------------------------------------------------------------|
   * |  Shift  |    |    |    |    |    |    |    |    |    |    |    Shift   |
   * |------------------------------------------------------------------------|
   * |Stop |     |     |         Play / Stop          |     |     |     |     |
   * `------------------------------------------------------------------------'
   *
   * Foot switches:
   *                ,--------.         ,--------.
   *                |        |         |        |
   *                |        |         |        |
   *                `--------'         `--------'
   */

[_ML_ONSTAGE] = KEYMAP_ANSI_FOOTSWITCHES(
  TG(_ML_ONSTAGE), F(ONSTAGE_SELECT_SONG_1), F(ONSTAGE_SELECT_SONG_2), F(ONSTAGE_SELECT_SONG_3), F(ONSTAGE_SELECT_SONG_4), F(ONSTAGE_SELECT_SONG_5), F(ONSTAGE_SELECT_SONG_6), F(ONSTAGE_SELECT_SONG_7), F(ONSTAGE_SELECT_SONG_8), F(ONSTAGE_SELECT_SONG_9), F(ONSTAGE_SELECT_SONG_10), F(ONSTAGE_BRIGHTD), F(ONSTAGE_BRIGHTU), XXXXXXX, \
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          XXXXXXX, \
  KC_LSFT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   KC_RSFT, \
  F(ONSTAGE_STOP), XXXXXXX, XXXXXXX,                          F(ONSTAGE_PLAYSTOP),                              XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
  XXXXXXX, XXXXXXX),


//
// Template:
//
#if 0
/* Keymap 
   * ,------------------------------------------------------------------------.
   * |      |    |    |    |    |    |    |    |    |    |    |    |    |     |
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
  [WINDOWS_TASKSWITCH_ENABLE] = ACTION_FUNCTION(WINDOWS_TASKSWITCH_ENABLE),
  [WINDOWS_TASKSWITCH_SELECT] = ACTION_FUNCTION(WINDOWS_TASKSWITCH_SELECT),
  [WINDOWS_TASKSWITCH_CANCEL] = ACTION_FUNCTION(WINDOWS_TASKSWITCH_CANCEL),
  [MAC_TASKSWITCH_ENABLE] = ACTION_FUNCTION(MAC_TASKSWITCH_ENABLE),
  [MAC_TASKSWITCH_SELECT] = ACTION_FUNCTION(MAC_TASKSWITCH_SELECT),
  [MAC_TASKSWITCH_CANCEL] = ACTION_FUNCTION(MAC_TASKSWITCH_CANCEL),
  [ONSTAGE_ENABLE] = ACTION_FUNCTION(ONSTAGE_ENABLE),
  [ONSTAGE_PLAYSTOP] = ACTION_FUNCTION(ONSTAGE_PLAYSTOP),
  [ONSTAGE_STOP] = ACTION_FUNCTION(ONSTAGE_STOP),
  [ONSTAGE_SELECT_SONG_1] = ACTION_FUNCTION_OPT(ONSTAGE_SELECT_SONG, 0),
  [ONSTAGE_SELECT_SONG_2] = ACTION_FUNCTION_OPT(ONSTAGE_SELECT_SONG, 1),
  [ONSTAGE_SELECT_SONG_3] = ACTION_FUNCTION_OPT(ONSTAGE_SELECT_SONG, 2),
  [ONSTAGE_SELECT_SONG_4] = ACTION_FUNCTION_OPT(ONSTAGE_SELECT_SONG, 3),
  [ONSTAGE_SELECT_SONG_5] = ACTION_FUNCTION_OPT(ONSTAGE_SELECT_SONG, 4),
  [ONSTAGE_SELECT_SONG_6] = ACTION_FUNCTION_OPT(ONSTAGE_SELECT_SONG, 5),
  [ONSTAGE_SELECT_SONG_7] = ACTION_FUNCTION_OPT(ONSTAGE_SELECT_SONG, 6),
  [ONSTAGE_SELECT_SONG_8] = ACTION_FUNCTION_OPT(ONSTAGE_SELECT_SONG, 7),
  [ONSTAGE_SELECT_SONG_9] = ACTION_FUNCTION_OPT(ONSTAGE_SELECT_SONG, 8),
  [ONSTAGE_SELECT_SONG_10] = ACTION_FUNCTION_OPT(ONSTAGE_SELECT_SONG, 9),
  [ONSTAGE_BRIGHTD] = ACTION_FUNCTION(ONSTAGE_BRIGHTD),
  [ONSTAGE_BRIGHTU] = ACTION_FUNCTION(ONSTAGE_BRIGHTU),
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

#define MIDI_ONSTAGE_SONG_COUNT 10
#define MIDI_ONSTAGE_PLAY_STATUS_LED_COUNT 9
#define MIDI_ONSTAGE_COLOR_VAL_STEP 0.1

// typedef struct {
//     uint8_t r;
//     uint8_t g;
//     uint8_t b;
// } rgb_color_t;

typedef struct {
    uint8_t hue;
    uint8_t sat;
    uint8_t val;
} hsv_color_t;

struct {
    bool playing;
    uint8_t current_song;
    uint8_t songs[MIDI_ONSTAGE_SONG_COUNT];
    uint8_t stop_note;
    float color_val_scale;
    hsv_color_t background_color;
    hsv_color_t stopped_color;
    hsv_color_t playing_color;
    hsv_color_t song_color;
    LED_TYPE* play_status_leds[MIDI_ONSTAGE_PLAY_STATUS_LED_COUNT];
    LED_TYPE* song_status_leds[MIDI_ONSTAGE_SONG_COUNT];
} midi_onstage;

void midi_onstage_set_playing(bool playing)
{
    midi_onstage.playing = playing;
    const hsv_color_t* color = playing ? &midi_onstage.playing_color : &midi_onstage.stopped_color;

    for (uint8_t i=0; i < MIDI_ONSTAGE_PLAY_STATUS_LED_COUNT; i++)
    {
        sethsv(
            color->hue,
            color->sat,
            color->val * midi_onstage.color_val_scale,
            midi_onstage.play_status_leds[i]);
    }

    rgblight_set();
}

void midi_onstage_set_song(uint8_t song)
{
    midi_onstage.current_song = song;

    for (uint8_t i=0; i < MIDI_ONSTAGE_SONG_COUNT; i++)
    {
        if (!midi_onstage.song_status_leds[i])
            continue;

        if (i == song)
        {
            sethsv(
                midi_onstage.song_color.hue + i * (255 / 7),
                midi_onstage.song_color.sat,
                midi_onstage.song_color.val * midi_onstage.color_val_scale,
                midi_onstage.song_status_leds[i]);
        }
        else
        {
            sethsv(
                midi_onstage.background_color.hue,
                midi_onstage.background_color.sat,
                midi_onstage.background_color.val * midi_onstage.color_val_scale,
                midi_onstage.song_status_leds[i]);
        }
    }

    rgblight_set();
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
        case WINDOWS_TASKSWITCH_ENABLE:
        {
            if (record->event.pressed)
            {
                register_code(KC_LALT);
                register_code(KC_TAB);
                unregister_code(KC_TAB);
                layer_on(_GL_WINDOWS_TASKSWITCH);
            }
            
            break;
        }
        case WINDOWS_TASKSWITCH_SELECT:
        {
            if (record->event.pressed)
            {
                unregister_code(KC_LALT);
                layer_off(_GL_WINDOWS_TASKSWITCH);
                layer_off(_GL_WINDOWS);
            }
            
            break;
        }
        case WINDOWS_TASKSWITCH_CANCEL:
        {
            if (record->event.pressed)
            {
                add_key(KC_ESC);
                send_keyboard_report();
                unregister_code(KC_LALT);
                layer_off(_GL_WINDOWS_TASKSWITCH);
                layer_off(_GL_WINDOWS);
            }
            
            break;
        }
        case MAC_TASKSWITCH_ENABLE:
        {
            if (record->event.pressed)
            {
                register_code(KC_LGUI);
                register_code(KC_TAB);
                unregister_code(KC_TAB);
                layer_on(_GL_MAC_TASKSWITCH);
            }
            
            break;
        }
        case MAC_TASKSWITCH_SELECT:
        {
            if (record->event.pressed)
            {
                unregister_code(KC_LGUI);
                layer_off(_GL_MAC_TASKSWITCH);
                layer_off(_GL_MAC);
            }
            
            break;
        }
        case MAC_TASKSWITCH_CANCEL:
        {
            if (record->event.pressed)
            {
                add_key(KC_ESC);
                send_keyboard_report();
                unregister_code(KC_LGUI);
                layer_off(_GL_MAC_TASKSWITCH);
                layer_off(_GL_MAC);
            }
            
            break;
        }
        case ONSTAGE_ENABLE:
        {
            if (record->event.pressed)
            {
                midi_init();
                midi_onstage.stop_note = midi_compute_note(MI_C_2);

                for (uint8_t i = 0; i < MIDI_ONSTAGE_SONG_COUNT; i++)
                {
                    midi_onstage.songs[i] = midi_compute_note(MIDI_TONE_MIN + i);
                }

                midi_onstage.color_val_scale = 0.8f;

                midi_onstage.background_color.hue = 0;
                midi_onstage.background_color.sat = 0;
                midi_onstage.background_color.val = 100;

                midi_onstage.stopped_color.hue = 0;
                midi_onstage.stopped_color.sat = 255;
                midi_onstage.stopped_color.val = 255;
                
                midi_onstage.playing_color.hue = 0;
                midi_onstage.playing_color.sat = 0;
                midi_onstage.playing_color.val = 100;

                midi_onstage.song_color.hue = 80;
                midi_onstage.song_color.sat = 255;
                midi_onstage.song_color.val = 255;

                midi_onstage.play_status_leds[0] = &led[7];
                midi_onstage.play_status_leds[1] = &led[8];
                midi_onstage.play_status_leds[2] = &led[9];
                midi_onstage.play_status_leds[3] = &led[10];
                midi_onstage.play_status_leds[4] = &led[11];
                midi_onstage.play_status_leds[5] = &led[12];
                midi_onstage.play_status_leds[6] = &led[13];
                midi_onstage.play_status_leds[7] = &led[14];
                midi_onstage.play_status_leds[8] = &led[15];

                midi_onstage.song_status_leds[0] = &led[0];
                midi_onstage.song_status_leds[1] = &led[1];
                midi_onstage.song_status_leds[2] = &led[2];
                midi_onstage.song_status_leds[3] = &led[3];
                midi_onstage.song_status_leds[4] = &led[4];
                midi_onstage.song_status_leds[5] = &led[5];
                midi_onstage.song_status_leds[6] = &led[6];
                midi_onstage.song_status_leds[7] = 0;
                midi_onstage.song_status_leds[8] = 0;
                midi_onstage.song_status_leds[9] = 0;

                midi_onstage_set_playing(false);
                midi_onstage_set_song(0);

                layer_on(_ML_ONSTAGE);
            }

            break;
        }
        case ONSTAGE_PLAYSTOP:
        {
            if (record->event.pressed)
            {
                midi_onstage_set_playing(!midi_onstage.playing);

                if (!shift_pressed)
                {
                    uint8_t note = midi_onstage.playing ? midi_onstage.songs[midi_onstage.current_song] : midi_onstage.stop_note;
                    midi_send_noteon(&midi_device, midi_config.channel, note, 127);
                    midi_send_noteoff(&midi_device, midi_config.channel, note, 0);
                }
            }

            break;
        }
        case ONSTAGE_STOP:
        {
            if (record->event.pressed)
            {
                midi_onstage_set_playing(false);

                if (!shift_pressed)
                {
                    uint8_t note = midi_onstage.stop_note;
                    midi_send_noteon(&midi_device, midi_config.channel, note, 127);
                    midi_send_noteoff(&midi_device, midi_config.channel, note, 0);
                }
            }

            break;
        }
        case ONSTAGE_SELECT_SONG:
        {
            if (record->event.pressed)
            {
                midi_onstage_set_song(opt);

                if (!shift_pressed)
                {
                    // start the song
                    uint8_t note = midi_onstage.songs[midi_onstage.current_song];
                    midi_send_noteon(&midi_device, midi_config.channel, note, 127);
                    midi_send_noteoff(&midi_device, midi_config.channel, note, 0);
                    midi_onstage_set_playing(true);
                }
            }

            break;
        }
        case ONSTAGE_BRIGHTD:
        {
            if (record->event.pressed)
            {
                midi_onstage.color_val_scale -= MIDI_ONSTAGE_COLOR_VAL_STEP;
                if (midi_onstage.color_val_scale < 0.0f)
                    midi_onstage.color_val_scale = 0.0f;
                midi_onstage_set_playing(midi_onstage.playing);
                midi_onstage_set_song(midi_onstage.current_song);
            }

            break;
        }
        case ONSTAGE_BRIGHTU:
        {
            if (record->event.pressed)
            {
                midi_onstage.color_val_scale += MIDI_ONSTAGE_COLOR_VAL_STEP;
                if (midi_onstage.color_val_scale > 1.0f)
                    midi_onstage.color_val_scale = 1.0f;
                midi_onstage_set_playing(midi_onstage.playing);
                midi_onstage_set_song(midi_onstage.current_song);
            }

            break;
        }
    }
}

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
    switch(id)
    {
        case SD_SUBMIT_YOLO: // this would trigger when you hit a key mapped as M(SD_SUBMIT_YOLO)
        {
            if (record->event.pressed)
            {
                return MACRO( I(20), 
                    T(S), T(D), T(SPACE), 
                    T(S), T(U), T(B), T(M), T(I), T(T), T(SPACE), 
                    T(MINS), D(LSFT), T(C), U(LSFT), T(SPACE), 
                    D(LSFT), T(QUOT), T(Y), T(O), T(L), T(O), T(QUOT), U(LSFT), T(ENT), 
                    END );
            }
            break;
        }
    };

    return MACRO_NONE;
}

void matrix_init_user()
{
    debug_enable = true;
}