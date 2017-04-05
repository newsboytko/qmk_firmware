#include "frosty_flake.h"
#include "keymap_common.h"

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