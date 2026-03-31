// Copyright (c) 2022 Marco Pelegrini <marco@pelegrini.ca>
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

// ----------------- Keymap -----------------
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
     * ┌───┬───┬───┐
     * │ 7 │ 8 │ 9 │
     * ├───┼───┼───┤
     * │ 4 │ 5 │ 6 │
     * ├───┼───┼───┤
     * │ 1 │ 2 │ 3 │
     * └───┴───┴───┘
     */
    [0] = LAYOUT_ortho_3x3(
        KC_7, KC_8, KC_9,
        KC_4, KC_5, KC_6,
        KC_1, KC_2, KC_3
    )
};

// ----------------- OLED -----------------
#ifdef OLED_DRIVER_ENABLE
bool oled_task_user(void) {
    // Show a simple message
    oled_write_ln_P(PSTR("MarcoPad"), false);
    return false;
}
#endif

// ----------------- Rotary Encoder -----------------
#ifdef ENCODER_ENABLE
bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) { // first encoder
        if (clockwise) {
            tap_code(KC_VOLU); // volume up
        } else {
            tap_code(KC_VOLD); // volume down
        }
    }
    return false;
}
#endif