#include "frosty_flake.h"
#include "frosty_flake_common_keymap.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
DEFINE_COMMON_LAYERS()
};

const uint16_t PROGMEM fn_actions[] = {
    DEFINE_COMMON_FN_ACTIONS()
};

void action_function(keyrecord_t* record, uint8_t id, uint8_t opt) {
    if (common_action_function(record, id, opt))
        return;
    //TODO: add keyboard-specific actions here
}

const macro_t* action_get_macro(keyrecord_t* record, uint8_t id, uint8_t opt) {
    const macro_t* macro = common_action_get_macro(record, id, opt);
    if (macro)
        return macro;

    //TODO: add keyboard-specific macros here

    return MACRO_NONE;
}

void matrix_scan_user(void) {
    uint8_t layer = biton32(layer_state);
    led_set_caps_lock(layer == common_layer_fn);
    led_set_scroll_lock(layer == common_layer_numpad);
};

void led_set_user(uint8_t usb_led)
{
    led_set_num_lock(!(usb_led & (1<<USB_LED_NUM_LOCK)));
}