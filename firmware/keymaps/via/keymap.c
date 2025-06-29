// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
     * ┌───┬───┬───┬───┐
     * │ 7 │ 8 │ 9 │ / │
     * ├───┼───┼───┼───┤
     * │ 4 │ 5 │ 6 │ * │
     * ├───┼───┼───┼───┤
     * │ 1 │ 2 │ 3 │ - │
     * ├───┼───┼───┼───┤
     * │ 0 │ . │Ent│ + │
     * └───┴───┴───┴───┘
     */
    [0] = LAYOUT(
        KC_P7,   KC_P8,   KC_P9,   
        KC_P4,   KC_P5,   KC_P6,   
        KC_P1,   KC_P2,   KC_P3,   
        KC_MPLY
    ),
    [1] = LAYOUT(
        KC_P7,   KC_P8,   KC_P9,   
        KC_P4,   KC_P5,   KC_P6,   
        KC_P1,   KC_P2,   KC_P3,   
        KC_MPLY
    ),
    [2] = LAYOUT(
        KC_P7,   KC_P8,   KC_P9,   
        KC_P4,   KC_P5,   KC_P6,   
        KC_P1,   KC_P2,   KC_P3,   
        KC_MPLY
    ),
    [3] = LAYOUT(
        KC_P7,   KC_P8,   KC_P9,   
        KC_P4,   KC_P5,   KC_P6,   
        KC_P1,   KC_P2,   KC_P3,   
        KC_MPLY
    )
};  

const uint16_t PROGMEM encoder_map[][1][2] = {
    [0] = {ENCODER_CCW_CW(KC_VOLD, KC_VOLU)},
    [1] = {ENCODER_CCW_CW(KC_VOLD, KC_VOLU)},
    [2] = {ENCODER_CCW_CW(KC_VOLD, KC_VOLU)},
    [3] = {ENCODER_CCW_CW(KC_VOLD, KC_VOLU)},
};

#ifdef OLED_ENABLE
bool oled_task_user(void) {
    // Host Keyboard Layer Status
    oled_write_P(PSTR("Layer: "), false);

    switch (get_highest_layer(layer_state)) {
        case 0:
            oled_write_P(PSTR("Default\n"), false);
            break;
        case 1:
            oled_write_P(PSTR("1\n"), false);
            break;
        case 2:
            oled_write_P(PSTR("2\n"), false);
            break;
        case 3:
            oled_write_P(PSTR("3\n"), false);
            break;
        default:
            // Or use the write_ln shortcut over adding '\n' to the end of your string
            oled_write_ln_P(PSTR("Undefined"), false);
    }

    return false;
}
#endif